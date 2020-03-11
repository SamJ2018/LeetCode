#### 3.1 TreeMap的红黑树相关内容 ####

TreeMap中于红黑树相关的主要函数有:

##### 1 数据结构 #####

###### 1.1 红黑树的节点颜色--红色 ######

```java
private static final boolean RED = false;
```

###### 1.2 红黑树的节点颜色--黑色 ######

```java
private static final boolean BLACK = true;
```

###### 1.3 “红黑树的节点”对应的类。 ######

```java
static final class Entry<K,V> implements Map.Entry<K,V> { ... }
```

Entry包含了6个部分内容：key(键)、value(值)、left(左孩子)、right(右孩子)、parent(父节点)、color(颜色)
Entry节点根据key进行排序，Entry节点包含的内容为value。

##### 2 相关操作 #####

###### 2.1 左旋 ######

```java
private void rotateLeft(Entry<K,V> p) { ... }
```

###### 2.2 右旋 ######

```java
private void rotateRight(Entry<K,V> p) { ... }
```

###### 2.3 插入操作 ######

```java
public V put(K key, V value) { ... }
```

###### 2.4 插入修正操作 ######

红黑树执行插入操作之后，要执行“插入修正操作”。
目的是：**保红黑树在进行插入节点之后，仍然是一颗红黑树**

```java
private void fixAfterInsertion(Entry<K,V> x) { ... }
```

**2.5 删除操作**

```java
private void deleteEntry(Entry<K,V> p) { ... }
```

**2.6 删除修正操作**

红黑树执行删除之后，要执行“删除修正操作”。
目的是保证：**红黑树删除节点之后，仍然是一颗红黑树**

```java
private void fixAfterDeletion(Entry<K,V> x) { ... }
```

关于红黑树部分，这里主要是指出了TreeMap中那些是红黑树的主要相关内容。具体的红黑树相关操作API，这里没有详细说明，因为它们仅仅只是将算法翻译成代码。



#### 3.2 TreeMap的构造函数 ####

##### 1 默认构造函数 #####

使用默认构造函数构造TreeMap时，使用java的默认的比较器比较Key的大小，从而对TreeMap进行排序。

```java
public TreeMap() {
    comparator = null;
}
```

##### 2 带比较器的构造函数 #####

```java
public TreeMap(Comparator<? super K> comparator) {
    this.comparator = comparator;
}
```

##### 3 带Map的构造函数，Map会成为TreeMap的子集 #####

```java
public TreeMap(Map<? extends K, ? extends V> m) {
    comparator = null;
    putAll(m);
}
```

该构造函数会调用putAll()将m中的所有元素添加到TreeMap中。putAll()源码如下：

```java
public void putAll(Map<? extends K, ? extends V> m) {
    for (Map.Entry<? extends K, ? extends V> e : m.entrySet())
        put(e.getKey(), e.getValue());
}
```

从中，我们可以看出putAll()就是**将m中的key-value逐个的添加到TreeMap中**。

##### 4 带SortedMap的构造函数，SortedMap会成为TreeMap的子集 #####

```java
public TreeMap(SortedMap<K, ? extends V> m) {
    comparator = m.comparator();
    try {
        buildFromSorted(m.size(), m.entrySet().iterator(), null, null);
    } catch (java.io.IOException cannotHappen) {
    } catch (ClassNotFoundException cannotHappen) {
    }
}
```

该构造函数不同于上一个构造函数，在上一个构造函数中传入的参数是Map，Map不是有序的，所以要逐个添加。
而该构造函数的参数是SortedMap是一个有序的Map，我们通过buildFromSorted()来创建对应的Map。
buildFromSorted涉及到的代码如下：

```java
// 根据已经一个排好序的map创建一个TreeMap
    // 将map中的元素逐个添加到TreeMap中，并返回map的中间元素作为根节点。
    private final Entry<K,V> buildFromSorted(int level, int lo, int hi,
                         int redLevel,
                         Iterator it,
                         java.io.ObjectInputStream str,
                         V defaultVal)
        throws  java.io.IOException, ClassNotFoundException {

        if (hi < lo) return null;

      
        // 获取中间元素
        int mid = (lo + hi) / 2;

        Entry<K,V> left  = null;
        // 若lo小于mid，则递归调用获取(middel的)左孩子。
        if (lo < mid)
            left = buildFromSorted(level+1, lo, mid - 1, redLevel,
                   it, str, defaultVal);

        // 获取middle节点对应的key和value
        K key;
        V value;
        if (it != null) {
            if (defaultVal==null) {
                Map.Entry<K,V> entry = (Map.Entry<K,V>)it.next();
                key = entry.getKey();
                value = entry.getValue();
            } else {
                key = (K)it.next();
                value = defaultVal;
            }
        } else { // use stream
            key = (K) str.readObject();
            value = (defaultVal != null ? defaultVal : (V) str.readObject());
        }

        // 创建middle节点
        Entry<K,V> middle =  new Entry<K,V>(key, value, null);

        // 若当前节点的深度=红色节点的深度，则将节点着色为红色。
        if (level == redLevel)
            middle.color = RED;

        // 设置middle为left的父亲，left为middle的左孩子
        if (left != null) {
            middle.left = left;
            left.parent = middle;
        }

        if (mid < hi) {
            // 递归调用获取(middel的)右孩子。
            Entry<K,V> right = buildFromSorted(level+1, mid+1, hi, redLevel,
                           it, str, defaultVal);
            // 设置middle为left的父亲，left为middle的左孩子
            middle.right = right;
            right.parent = middle;
        }

        return middle;
    }
```



要理解buildFromSorted，重点说明以下几点：

第一，buildFromSorted是**通过递归将SortedMap中的元素逐个关联**。
第二，buildFromSorted返回**middle节点(中间节点)作为root。**
第三，buildFromSorted**添加到红黑树中时，只将level == redLevel的节点设为红色。**第level级节点，实际上是buildFromSorted转换成红黑树后的最底端(假设根节点在最上方)的节点；只将红黑树最底端的阶段着色为红色，其余都是黑色。



#### 3.3 TreeMap的Entry相关函数 ####

TreeMap的 **firstEntry()、 lastEntry()、 lowerEntry()、 higherEntry()、 floorEntry()、 ceilingEntry()、 pollFirstEntry() 、 pollLastEntry()** 原理都是类似的；下面以firstEntry()来进行详细说明

我们先看看firstEntry()和getFirstEntry()的代码：

```java
public Map.Entry<K,V> firstEntry() {
    return exportEntry(getFirstEntry());
}

final Entry<K,V> getFirstEntry() {
    Entry<K,V> p = root;
    if (p != null)
        while (p.left != null)
            p = p.left;
    return p;
}
```

从中，我们可以看出 firstEntry() 和 getFirstEntry() 都是用于**获取第一个节点。**
但是，firstEntry() 是**对外接口**； getFirstEntry() 是**内部接口**。而且，firstEntry() 是通过 getFirstEntry() 来实现的。那为什么外界不能直接调用 getFirstEntry()，而需要多此一举的调用 firstEntry() 呢?
先告诉大家原因，再进行详细说明。这么做的目的是：**防止用户修改返回的Entry。**getFirstEntry()返回的Entry是可以被修改的，但是经过firstEntry()返回的Entry不能被修改，只可以读取Entry的key值和value值。下面我们看看到底是如何实现的。

* getFirstEntry()返回的是Entry节点，而Entry是红黑树的节点，它的源码如下：

```java
// 返回“红黑树的第一个节点”
final Entry<K,V> getFirstEntry() {
    Entry<K,V> p = root;
    if (p != null)
    while (p.left != null)
            p = p.left;
    return p;
}
```

从中，我们可以调用Entry的getKey()、getValue()来获取key和value值，以及调用setValue()来修改value的值。

* firstEntry()返回的是exportEntry(getFirstEntry())。下面我们看看exportEntry()干了些什么？

```java
static <K,V> Map.Entry<K,V> exportEntry(TreeMap.Entry<K,V> e) {
    return e == null? null :
        new AbstractMap.SimpleImmutableEntry<K,V>(e);
}
```

实际上，exportEntry() 是新建一个AbstractMap.SimpleImmutableEntry类型的对象，并返回。

SimpleImmutableEntry的实现在AbstractMap.java中，下面我们看看AbstractMap.SimpleImmutableEntry是如何实现的，代码如下：

```java
public static class SimpleImmutableEntry<K,V>
implements Entry<K,V>, java.io.Serializable
{
    private static final long serialVersionUID = 7138329143949025153L;

    private final K key;
    private final V value;

    public SimpleImmutableEntry(K key, V value) {
        this.key   = key;
        this.value = value;
    }

    public SimpleImmutableEntry(Entry<? extends K, ? extends V> entry) {
        this.key   = entry.getKey();
            this.value = entry.getValue();
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }

    public V setValue(V value) {
            throw new UnsupportedOperationException();
        }

    public boolean equals(Object o) {
        if (!(o instanceof Map.Entry))
        return false;
        Map.Entry e = (Map.Entry)o;
        return eq(key, e.getKey()) && eq(value, e.getValue());
    }

    public int hashCode() {
        return (key   == null ? 0 :   key.hashCode()) ^
           (value == null ? 0 : value.hashCode());
    }

    public String toString() {
        return key + "=" + value;
    }
}
```

从中，我们可以看出SimpleImmutableEntry实际上是简化的key-value节点。
它只提供了getKey()、getValue()方法类获取节点的值；但不能修改value的值，因为调用 setValue() 会抛出异常UnsupportedOperationException();


再回到我们之前的问题：那为什么外界不能直接调用 getFirstEntry()，而需要多此一举的调用 firstEntry() 呢?
现在我们清晰的了解到：

* firstEntry()是对外接口，而getFirstEntry()是内部接口。
* 对firstEntry()返回的Entry对象只能进行getKey()、getValue()等读取操作；而对getFirstEntry()返回的对象除了可以进行读取操作之后，还可以通过setValue()修改值。

#### 3.4 TreeMap的key相关函数 ####

TreeMap的**firstKey()、lastKey()、lowerKey()、higherKey()、floorKey()、ceilingKey()**原理都是类似的；下面以ceilingKey()来进行详细说明

ceilingKey(K key)的作用是“返回大于/等于key的最小的键值对所对应的KEY，没有的话返回null”，它的代码如下：

```java
public K ceilingKey(K key) {
    return keyOrNull(getCeilingEntry(key));
}
```

ceilingKey()是通过getCeilingEntry()实现的。keyOrNull()的代码很简单，它是获取节点的key，没有的话，返回null。

```java
static <K,V> K keyOrNull(TreeMap.Entry<K,V> e) {
    return e == null? null : e.key;
}
```

getCeilingEntry(K key)的作用是“获取TreeMap中大于/等于key的最小的节点，若不存在(即TreeMap中所有节点的键都比key大)，就返回null”。它的实现代码如下：

```java
final Entry<K,V> getCeilingEntry(K key) {
    Entry<K,V> p = root;
    while (p != null) {
        int cmp = compare(key, p.key);
        // 情况一：若“p的key” > key。
        // 若 p 存在左孩子，则设 p=“p的左孩子”；
        // 否则，返回p
        if (cmp < 0) {
            if (p.left != null)
                p = p.left;
            else
                return p;
        // 情况二：若“p的key” < key。
        } else if (cmp > 0) {
            // 若 p 存在右孩子，则设 p=“p的右孩子”
            if (p.right != null) {
                p = p.right;
            } else {
                // 若 p 不存在右孩子，则找出 p 的后继节点，并返回
                // 注意：这里返回的 “p的后继节点”有2种可能性：第一，null；第二，TreeMap中大于key的最小的节点。
                //   理解这一点的核心是，getCeilingEntry是从root开始遍历的。
                //   若getCeilingEntry能走到这一步，那么，它之前“已经遍历过的节点的key”都 > key。
                //   能理解上面所说的，那么就很容易明白，为什么“p的后继节点”有2种可能性了。
                Entry<K,V> parent = p.parent;
                Entry<K,V> ch = p;
                while (parent != null && ch == parent.right) {
                    ch = parent;
                    parent = parent.parent;
                }
                return parent;
            }
        // 情况三：若“p的key” = key。
        } else
            return p;
    }
    return null;
}
```

#### 3.5 TreeMap的values()函数 ####

values() 返回**“TreeMap中值的集合”**

values()的实现代码如下：

```java
public Collection<V> values() {
    Collection<V> vs = values;
    return (vs != null) ? vs : (values = new Values());
}
```

说明：从中，我们可以发现values()是通过 new Values() 来实现 “返回TreeMap中值的集合”。

那么Values()是如何实现的呢？ 没错！由于返回的是值的集合，那么Values()肯定返回一个集合；而Values()正好是集合类Value的构造函数。Values继承于AbstractCollection，它的代码如下：

```java
// ”TreeMap的值的集合“对应的类，它集成于AbstractCollection
class Values extends AbstractCollection<V> {
    // 返回迭代器
    public Iterator<V> iterator() {
        return new ValueIterator(getFirstEntry());
    }

    // 返回个数
    public int size() {
        return TreeMap.this.size();
    }

    // "TreeMap的值的集合"中是否包含"对象o"
    public boolean contains(Object o) {
        return TreeMap.this.containsValue(o);
    }

    // 删除"TreeMap的值的集合"中的"对象o"
    public boolean remove(Object o) {
        for (Entry<K,V> e = getFirstEntry(); e != null; e = successor(e)) {
            if (valEquals(e.getValue(), o)) {
                deleteEntry(e);
                return true;
            }
        }
        return false;
    }

    // 清空删除"TreeMap的值的集合"
    public void clear() {
        TreeMap.this.clear();
    }
}
```

说明：从中，我们可以知道Values类就是一个集合。而 AbstractCollection 实现了除 size() 和 iterator() 之外的其它函数，因此只需要在Values类中实现这两个函数即可。
size() 的实现非常简单，Values集合中元素的个数=该TreeMap的元素个数。(TreeMap每一个元素都有一个值嘛！)
iterator() 则返回一个迭代器，用于遍历Values。下面，我们一起可以看看iterator()的实现：

```java
public Iterator<V> iterator() {
    return new ValueIterator(getFirstEntry());
}
```

说明： iterator() 是通过ValueIterator() 返回迭代器的，ValueIterator是一个类。代码如下：

```java
final class ValueIterator extends PrivateEntryIterator<V> {
    ValueIterator(Entry<K,V> first) {
        super(first);
    }
    public V next() {
        return nextEntry().value;
    }
}
```

说明：ValueIterator的代码很简单，它的主要实现应该在它的父类PrivateEntryIterator中。下面我们一起看看PrivateEntryIterator的代码：

```java
abstract class PrivateEntryIterator<T> implements Iterator<T> {
    // 下一节点
    Entry<K,V> next;
    // 上一次返回的节点
    Entry<K,V> lastReturned;
    // 修改次数统计数
    int expectedModCount;

    PrivateEntryIterator(Entry<K,V> first) {
        expectedModCount = modCount;
        lastReturned = null;
        next = first;
    }

    // 是否存在下一个节点
    public final boolean hasNext() {
        return next != null;
    }

    // 返回下一个节点
    final Entry<K,V> nextEntry() {
        Entry<K,V> e = next;
        if (e == null)
            throw new NoSuchElementException();
        if (modCount != expectedModCount)
            throw new ConcurrentModificationException();
        next = successor(e);
        lastReturned = e;
        return e;
    }

    // 返回上一节点
    final Entry<K,V> prevEntry() {
        Entry<K,V> e = next;
        if (e == null)
            throw new NoSuchElementException();
        if (modCount != expectedModCount)
            throw new ConcurrentModificationException();
        next = predecessor(e);
        lastReturned = e;
        return e;
    }

    // 删除当前节点
    public void remove() {
        if (lastReturned == null)
            throw new IllegalStateException();
        if (modCount != expectedModCount)
            throw new ConcurrentModificationException();
        // deleted entries are replaced by their successors
        if (lastReturned.left != null && lastReturned.right != null)
            next = lastReturned;
        deleteEntry(lastReturned);
        expectedModCount = modCount;
        lastReturned = null;
    }
}
```

说明：PrivateEntryIterator是一个抽象类，它的实现很简单，只只实现了Iterator的remove()和hasNext()接口，没有实现next()接口。
而我们在ValueIterator中已经实现的next()接口。
至此，我们就了解了iterator()的完整实现了。



#### 3.6 TreeMap的entrySet()函数 ####

ntrySet() 返回**“键值对集合”**。顾名思义，它返回的是一个集合，集合的元素是“键值对”。

下面，我们看看它是如何实现的？entrySet() 的实现代码如下：

```java
public Set<Map.Entry<K,V>> entrySet() {
    EntrySet es = entrySet;
    return (es != null) ? es : (entrySet = new EntrySet());
}
```

说明：entrySet()返回的是一个EntrySet对象。

下面我们看看EntrySet的代码：

```java
// EntrySet是“TreeMap的所有键值对组成的集合”，
// EntrySet集合的单位是单个“键值对”。
class EntrySet extends AbstractSet<Map.Entry<K,V>> {
    public Iterator<Map.Entry<K,V>> iterator() {
        return new EntryIterator(getFirstEntry());
    }

    // EntrySet中是否包含“键值对Object”
    public boolean contains(Object o) {
        if (!(o instanceof Map.Entry))
            return false;
        Map.Entry<K,V> entry = (Map.Entry<K,V>) o;
        V value = entry.getValue();
        Entry<K,V> p = getEntry(entry.getKey());
        return p != null && valEquals(p.getValue(), value);
    }

    // 删除EntrySet中的“键值对Object”
    public boolean remove(Object o) {
        if (!(o instanceof Map.Entry))
            return false;
        Map.Entry<K,V> entry = (Map.Entry<K,V>) o;
        V value = entry.getValue();
        Entry<K,V> p = getEntry(entry.getKey());
        if (p != null && valEquals(p.getValue(), value)) {
            deleteEntry(p);
            return true;
        }
        return false;
    }

    // 返回EntrySet中元素个数
    public int size() {
        return TreeMap.this.size();
    }

    // 清空EntrySet
    public void clear() {
        TreeMap.this.clear();
    }
}
```

说明：
EntrySet是“**TreeMap的所有键值对组成的集合”**，而且它单位是单个“键值对”。
EntrySet是一个集合，它继承于AbstractSet。而AbstractSet实现了除size() 和 iterator() 之外的其它函数，因此，我们重点了解一下EntrySet的size() 和 iterator() 函数

size() 的实现非常简单，AbstractSet集合中元素的个数=该TreeMap的元素个数。
iterator() 则返回一个迭代器，用于遍历AbstractSet。从上面的源码中，我们可以发现**iterator() 是通过EntryIterator实现的**；下面我们看看EntryIterator的源码：



```java
final class EntryIterator extends PrivateEntryIterator<Map.Entry<K,V>> {
    EntryIterator(Entry<K,V> first) {
        super(first);
    }
    public Map.Entry<K,V> next() {
        return nextEntry();
    }
}
```

说明：和Values类一样，EntryIterator也继承于PrivateEntryIterator类。

#### 3.7部分 TreeMap实现的Cloneable接口 ####

TreeMap实现了Cloneable接口，即**实现了clone()方法。**
clone()方法的作用很简单，就是克隆一个TreeMap对象并返回。

```java
// 克隆一个TreeMap，并返回Object对象
public Object clone() {
    TreeMap<K,V> clone = null;
    try {
        clone = (TreeMap<K,V>) super.clone();
    } catch (CloneNotSupportedException e) {
        throw new InternalError();
    }

    // Put clone into "virgin" state (except for comparator)
    clone.root = null;
    clone.size = 0;
    clone.modCount = 0;
    clone.entrySet = null;
    clone.navigableKeySet = null;
    clone.descendingMap = null;

    // Initialize clone with our mappings
    try {
        clone.buildFromSorted(size, entrySet().iterator(), null, null);
    } catch (java.io.IOException cannotHappen) {
    } catch (ClassNotFoundException cannotHappen) {
    }

    return clone;
}
```

#### 3.8 TreeMap实现的Serializable接口 ####

TreeMap实现java.io.Serializable，分别实现了串行读取、写入功能。
串行写入函数是writeObject()，它的作用是**将TreeMap的“容量，所有的Entry”都写入到输出流中。**
而串行读取函数是readObject()，它的作用是**将TreeMap的“容量、所有的Entry”依次读出。**
readObject() 和 writeObject() 正好是一对，通过它们，我能实现TreeMap的串行传输。

```java
// java.io.Serializable的写入函数
// 将TreeMap的“容量，所有的Entry”都写入到输出流中
private void writeObject(java.io.ObjectOutputStream s)
    throws java.io.IOException {
    // Write out the Comparator and any hidden stuff
    s.defaultWriteObject();

    // Write out size (number of Mappings)
    s.writeInt(size);

    // Write out keys and values (alternating)
    for (Iterator<Map.Entry<K,V>> i = entrySet().iterator(); i.hasNext(); ) {
        Map.Entry<K,V> e = i.next();
        s.writeObject(e.getKey());
        s.writeObject(e.getValue());
    }
}


// java.io.Serializable的读取函数：根据写入方式读出
// 先将TreeMap的“容量、所有的Entry”依次读出
private void readObject(final java.io.ObjectInputStream s)
    throws java.io.IOException, ClassNotFoundException {
    // Read in the Comparator and any hidden stuff
    s.defaultReadObject();

    // Read in size
    int size = s.readInt();

    buildFromSorted(size, null, s, null);
}
```

说到这里，就顺便说一下**“关键字transient”的作用**

transient是Java语言的关键字，它被用来**表示一个域不是该对象串行化的一部分。**
Java的serialization提供了**一种持久化对象实例的机制**。当持久化对象时，可能有一个特殊的对象数据成员，我们不想用serialization机制来保存它。为了在一个特定对象的一个域上关闭serialization，可以在这个域前加上关键字transient。
当一个对象被串行化的时候，transient型变量的值不包括在串行化的表示中，然而非transient型的变量是被包括进去的



#### 3.9 TreeMap实现的NavigableMap接口 ####

**firstKey()、lastKey()、lowerKey()、higherKey()、ceilingKey()、floorKey();**
**firstEntry()、 lastEntry()、 lowerEntry()、 higherEntry()、 floorEntry()、 ceilingEntry()、 pollFirstEntry() 、 pollLastEntry();**
上面已经讲解过这些API了，下面对其它的API进行说明。

**1 反向TreeMap**
descendingMap() 的作用是**返回当前TreeMap的反向的TreeMap**。所谓反向，就是**排序顺序和原始的顺序相反。**

我们已经知道TreeMap是一颗红黑树，而红黑树是有序的。
TreeMap的排序方式是通过比较器，在创建TreeMap的时候，若指定了比较器，则使用该比较器；否则，就使用Java的默认比较器。
而获取TreeMap的反向TreeMap的原理就是将比较器反向即可！

理解了descendingMap()的反向原理之后，再讲解一下descendingMap()的代码。

```java
// 获取TreeMap的降序Map
public NavigableMap<K, V> descendingMap() {
    NavigableMap<K, V> km = descendingMap;
    return (km != null) ? km :
        (descendingMap = new DescendingSubMap(this,
                                              true, null, true,
                                              true, null, true));
}
```

从中，我们看出descendingMap()实际上是返回DescendingSubMap类的对象。下面，看看DescendingSubMap的源码:

```java
static final class DescendingSubMap<K,V>  extends NavigableSubMap<K,V> {
    private static final long serialVersionUID = 912986545866120460L;
    DescendingSubMap(TreeMap<K,V> m,
                    boolean fromStart, K lo, boolean loInclusive,
                    boolean toEnd,     K hi, boolean hiInclusive) {
        super(m, fromStart, lo, loInclusive, toEnd, hi, hiInclusive);
    }

    // 反转的比较器：是将原始比较器反转得到的。
    private final Comparator<? super K> reverseComparator =
        Collections.reverseOrder(m.comparator);

    // 获取反转比较器
    public Comparator<? super K> comparator() {
        return reverseComparator;
    }

    // 获取“子Map”。
    // 范围是从fromKey 到 toKey；fromInclusive是是否包含fromKey的标记，toInclusive是是否包含toKey的标记
    public NavigableMap<K,V> subMap(K fromKey, boolean fromInclusive,
                                    K toKey,   boolean toInclusive) {
        if (!inRange(fromKey, fromInclusive))
            throw new IllegalArgumentException("fromKey out of range");
        if (!inRange(toKey, toInclusive))
            throw new IllegalArgumentException("toKey out of range");
        return new DescendingSubMap(m,
                                    false, toKey,   toInclusive,
                                    false, fromKey, fromInclusive);
    }

    // 获取“Map的头部”。
    // 范围从第一个节点 到 toKey, inclusive是是否包含toKey的标记
    public NavigableMap<K,V> headMap(K toKey, boolean inclusive) {
        if (!inRange(toKey, inclusive))
            throw new IllegalArgumentException("toKey out of range");
        return new DescendingSubMap(m,
                                    false, toKey, inclusive,
                                    toEnd, hi,    hiInclusive);
    }

    // 获取“Map的尾部”。
    // 范围是从 fromKey 到 最后一个节点，inclusive是是否包含fromKey的标记
    public NavigableMap<K,V> tailMap(K fromKey, boolean inclusive){
        if (!inRange(fromKey, inclusive))
            throw new IllegalArgumentException("fromKey out of range");
        return new DescendingSubMap(m,
                                    fromStart, lo, loInclusive,
                                    false, fromKey, inclusive);
    }

    // 获取对应的降序Map
    public NavigableMap<K,V> descendingMap() {
        NavigableMap<K,V> mv = descendingMapView;
        return (mv != null) ? mv :
            (descendingMapView =
             new AscendingSubMap(m,
                                 fromStart, lo, loInclusive,
                                 toEnd,     hi, hiInclusive));
    }

    // 返回“升序Key迭代器”
    Iterator<K> keyIterator() {
        return new DescendingSubMapKeyIterator(absHighest(), absLowFence());
    }

    // 返回“降序Key迭代器”
    Iterator<K> descendingKeyIterator() {
        return new SubMapKeyIterator(absLowest(), absHighFence());
    }

    // “降序EntrySet集合”类
    // 实现了iterator()
    final class DescendingEntrySetView extends EntrySetView {
        public Iterator<Map.Entry<K,V>> iterator() {
            return new DescendingSubMapEntryIterator(absHighest(), absLowFence());
        }
    }

    // 返回“降序EntrySet集合”
    public Set<Map.Entry<K,V>> entrySet() {
        EntrySetView es = entrySetView;
        return (es != null) ? es : new DescendingEntrySetView();
    }

    TreeMap.Entry<K,V> subLowest()       { return absHighest(); }
    TreeMap.Entry<K,V> subHighest()      { return absLowest(); }
    TreeMap.Entry<K,V> subCeiling(K key) { return absFloor(key); }
    TreeMap.Entry<K,V> subHigher(K key)  { return absLower(key); }
    TreeMap.Entry<K,V> subFloor(K key)   { return absCeiling(key); }
    TreeMap.Entry<K,V> subLower(K key)   { return absHigher(key); }
}
```

从中，我们看出DescendingSubMap是降序的SubMap，它的实现机制是将“SubMap的比较器反转”。

它继承于NavigableSubMap。而NavigableSubMap是一个继承于AbstractMap的抽象类；它包括2个子类——"(升序)AscendingSubMap"和"(降序)DescendingSubMap"。NavigableSubMap为它的两个子类实现了许多公共API。
下面看看NavigableSubMap的源码。

```java
static abstract class NavigableSubMap<K,V> extends AbstractMap<K,V>
    implements NavigableMap<K,V>, java.io.Serializable {
    // TreeMap的拷贝
    final TreeMap<K,V> m;
    // lo是“子Map范围的最小值”，hi是“子Map范围的最大值”；
    // loInclusive是“是否包含lo的标记”，hiInclusive是“是否包含hi的标记”
    // fromStart是“表示是否从第一个节点开始计算”，
    // toEnd是“表示是否计算到最后一个节点      ”
    final K lo, hi;      
    final boolean fromStart, toEnd;
    final boolean loInclusive, hiInclusive;

    // 构造函数
    NavigableSubMap(TreeMap<K,V> m,
                    boolean fromStart, K lo, boolean loInclusive,
                    boolean toEnd,     K hi, boolean hiInclusive) {
        if (!fromStart && !toEnd) {
            if (m.compare(lo, hi) > 0)
                throw new IllegalArgumentException("fromKey > toKey");
        } else {
            if (!fromStart) // type check
                m.compare(lo, lo);
            if (!toEnd)
                m.compare(hi, hi);
        }

        this.m = m;
        this.fromStart = fromStart;
        this.lo = lo;
        this.loInclusive = loInclusive;
        this.toEnd = toEnd;
        this.hi = hi;
        this.hiInclusive = hiInclusive;
    }

    // 判断key是否太小
    final boolean tooLow(Object key) {
        // 若该SubMap不包括“起始节点”，
        // 并且，“key小于最小键(lo)”或者“key等于最小键(lo)，但最小键却没包括在该SubMap内”
        // 则判断key太小。其余情况都不是太小！
        if (!fromStart) {
            int c = m.compare(key, lo);
            if (c < 0 || (c == 0 && !loInclusive))
                return true;
        }
        return false;
    }

    // 判断key是否太大
    final boolean tooHigh(Object key) {
        // 若该SubMap不包括“结束节点”，
        // 并且，“key大于最大键(hi)”或者“key等于最大键(hi)，但最大键却没包括在该SubMap内”
        // 则判断key太大。其余情况都不是太大！
        if (!toEnd) {
            int c = m.compare(key, hi);
            if (c > 0 || (c == 0 && !hiInclusive))
                return true;
        }
        return false;
    }

    // 判断key是否在“lo和hi”开区间范围内
    final boolean inRange(Object key) {
        return !tooLow(key) && !tooHigh(key);
    }

    // 判断key是否在封闭区间内
    final boolean inClosedRange(Object key) {
        return (fromStart || m.compare(key, lo) >= 0)
            && (toEnd || m.compare(hi, key) >= 0);
    }

    // 判断key是否在区间内, inclusive是区间开关标志
    final boolean inRange(Object key, boolean inclusive) {
        return inclusive ? inRange(key) : inClosedRange(key);
    }

    // 返回最低的Entry
    final TreeMap.Entry<K,V> absLowest() {
    // 若“包含起始节点”，则调用getFirstEntry()返回第一个节点
    // 否则的话，若包括lo，则调用getCeilingEntry(lo)获取大于/等于lo的最小的Entry;
    //           否则，调用getHigherEntry(lo)获取大于lo的最小Entry
    TreeMap.Entry<K,V> e =
            (fromStart ?  m.getFirstEntry() :
             (loInclusive ? m.getCeilingEntry(lo) :
                            m.getHigherEntry(lo)));
        return (e == null || tooHigh(e.key)) ? null : e;
    }

    // 返回最高的Entry
    final TreeMap.Entry<K,V> absHighest() {
    // 若“包含结束节点”，则调用getLastEntry()返回最后一个节点
    // 否则的话，若包括hi，则调用getFloorEntry(hi)获取小于/等于hi的最大的Entry;
    //           否则，调用getLowerEntry(hi)获取大于hi的最大Entry
    TreeMap.Entry<K,V> e =
    TreeMap.Entry<K,V> e =
            (toEnd ?  m.getLastEntry() :
             (hiInclusive ?  m.getFloorEntry(hi) :
                             m.getLowerEntry(hi)));
        return (e == null || tooLow(e.key)) ? null : e;
    }

    // 返回"大于/等于key的最小的Entry"
    final TreeMap.Entry<K,V> absCeiling(K key) {
        // 只有在“key太小”的情况下，absLowest()返回的Entry才是“大于/等于key的最小Entry”
        // 其它情况下不行。例如，当包含“起始节点”时，absLowest()返回的是最小Entry了！
        if (tooLow(key))
            return absLowest();
        // 获取“大于/等于key的最小Entry”
    TreeMap.Entry<K,V> e = m.getCeilingEntry(key);
        return (e == null || tooHigh(e.key)) ? null : e;
    }

    // 返回"大于key的最小的Entry"
    final TreeMap.Entry<K,V> absHigher(K key) {
        // 只有在“key太小”的情况下，absLowest()返回的Entry才是“大于key的最小Entry”
        // 其它情况下不行。例如，当包含“起始节点”时，absLowest()返回的是最小Entry了,而不一定是“大于key的最小Entry”！
        if (tooLow(key))
            return absLowest();
        // 获取“大于key的最小Entry”
    TreeMap.Entry<K,V> e = m.getHigherEntry(key);
        return (e == null || tooHigh(e.key)) ? null : e;
    }

    // 返回"小于/等于key的最大的Entry"
    final TreeMap.Entry<K,V> absFloor(K key) {
        // 只有在“key太大”的情况下，(absHighest)返回的Entry才是“小于/等于key的最大Entry”
        // 其它情况下不行。例如，当包含“结束节点”时，absHighest()返回的是最大Entry了！
        if (tooHigh(key))
            return absHighest();
    // 获取"小于/等于key的最大的Entry"
    TreeMap.Entry<K,V> e = m.getFloorEntry(key);
        return (e == null || tooLow(e.key)) ? null : e;
    }

    // 返回"小于key的最大的Entry"
    final TreeMap.Entry<K,V> absLower(K key) {
        // 只有在“key太大”的情况下，(absHighest)返回的Entry才是“小于key的最大Entry”
        // 其它情况下不行。例如，当包含“结束节点”时，absHighest()返回的是最大Entry了,而不一定是“小于key的最大Entry”！
        if (tooHigh(key))
            return absHighest();
    // 获取"小于key的最大的Entry"
    TreeMap.Entry<K,V> e = m.getLowerEntry(key);
        return (e == null || tooLow(e.key)) ? null : e;
    }

    // 返回“大于最大节点中的最小节点”，不存在的话，返回null
    final TreeMap.Entry<K,V> absHighFence() {
        return (toEnd ? null : (hiInclusive ?
                                m.getHigherEntry(hi) :
                                m.getCeilingEntry(hi)));
    }

    // 返回“小于最小节点中的最大节点”，不存在的话，返回null
    final TreeMap.Entry<K,V> absLowFence() {
        return (fromStart ? null : (loInclusive ?
                                    m.getLowerEntry(lo) :
                                    m.getFloorEntry(lo)));
    }

    // 下面几个abstract方法是需要NavigableSubMap的实现类实现的方法
    abstract TreeMap.Entry<K,V> subLowest();
    abstract TreeMap.Entry<K,V> subHighest();
    abstract TreeMap.Entry<K,V> subCeiling(K key);
    abstract TreeMap.Entry<K,V> subHigher(K key);
    abstract TreeMap.Entry<K,V> subFloor(K key);
    abstract TreeMap.Entry<K,V> subLower(K key);
    // 返回“顺序”的键迭代器
    abstract Iterator<K> keyIterator();
    // 返回“逆序”的键迭代器
    abstract Iterator<K> descendingKeyIterator();

    // 返回SubMap是否为空。空的话，返回true，否则返回false
    public boolean isEmpty() {
        return (fromStart && toEnd) ? m.isEmpty() : entrySet().isEmpty();
    }

    // 返回SubMap的大小
    public int size() {
        return (fromStart && toEnd) ? m.size() : entrySet().size();
    }

    // 返回SubMap是否包含键key
    public final boolean containsKey(Object key) {
        return inRange(key) && m.containsKey(key);
    }

    // 将key-value 插入SubMap中
    public final V put(K key, V value) {
        if (!inRange(key))
            throw new IllegalArgumentException("key out of range");
        return m.put(key, value);
    }

    // 获取key对应值
    public final V get(Object key) {
        return !inRange(key)? null :  m.get(key);
    }

    // 删除key对应的键值对
    public final V remove(Object key) {
        return !inRange(key)? null  : m.remove(key);
    }

    // 获取“大于/等于key的最小键值对”
    public final Map.Entry<K,V> ceilingEntry(K key) {
        return exportEntry(subCeiling(key));
    }

    // 获取“大于/等于key的最小键”
    public final K ceilingKey(K key) {
        return keyOrNull(subCeiling(key));
    }

    // 获取“大于key的最小键值对”
    public final Map.Entry<K,V> higherEntry(K key) {
        return exportEntry(subHigher(key));
    }

    // 获取“大于key的最小键”
    public final K higherKey(K key) {
        return keyOrNull(subHigher(key));
    }

    // 获取“小于/等于key的最大键值对”
    public final Map.Entry<K,V> floorEntry(K key) {
        return exportEntry(subFloor(key));
    }

    // 获取“小于/等于key的最大键”
    public final K floorKey(K key) {
        return keyOrNull(subFloor(key));
    }

    // 获取“小于key的最大键值对”
    public final Map.Entry<K,V> lowerEntry(K key) {
        return exportEntry(subLower(key));
    }

    // 获取“小于key的最大键”
    public final K lowerKey(K key) {
        return keyOrNull(subLower(key));
    }

    // 获取"SubMap的第一个键"
    public final K firstKey() {
        return key(subLowest());
    }

    // 获取"SubMap的最后一个键"
    public final K lastKey() {
        return key(subHighest());
    }

    // 获取"SubMap的第一个键值对"
    public final Map.Entry<K,V> firstEntry() {
        return exportEntry(subLowest());
    }

    // 获取"SubMap的最后一个键值对"
    public final Map.Entry<K,V> lastEntry() {
        return exportEntry(subHighest());
    }

    // 返回"SubMap的第一个键值对"，并从SubMap中删除改键值对
    public final Map.Entry<K,V> pollFirstEntry() {
    TreeMap.Entry<K,V> e = subLowest();
        Map.Entry<K,V> result = exportEntry(e);
        if (e != null)
            m.deleteEntry(e);
        return result;
    }

    // 返回"SubMap的最后一个键值对"，并从SubMap中删除改键值对
    public final Map.Entry<K,V> pollLastEntry() {
    TreeMap.Entry<K,V> e = subHighest();
        Map.Entry<K,V> result = exportEntry(e);
        if (e != null)
            m.deleteEntry(e);
        return result;
    }

    // Views
    transient NavigableMap<K,V> descendingMapView = null;
    transient EntrySetView entrySetView = null;
    transient KeySet<K> navigableKeySetView = null;

    // 返回NavigableSet对象，实际上返回的是当前对象的"Key集合"。 
    public final NavigableSet<K> navigableKeySet() {
        KeySet<K> nksv = navigableKeySetView;
        return (nksv != null) ? nksv :
            (navigableKeySetView = new TreeMap.KeySet(this));
    }

    // 返回"Key集合"对象
    public final Set<K> keySet() {
        return navigableKeySet();
    }

    // 返回“逆序”的Key集合
    public NavigableSet<K> descendingKeySet() {
        return descendingMap().navigableKeySet();
    }

    // 排列fromKey(包含) 到 toKey(不包含) 的子map
    public final SortedMap<K,V> subMap(K fromKey, K toKey) {
        return subMap(fromKey, true, toKey, false);
    }

    // 返回当前Map的头部(从第一个节点 到 toKey, 不包括toKey)
    public final SortedMap<K,V> headMap(K toKey) {
        return headMap(toKey, false);
    }

    // 返回当前Map的尾部[从 fromKey(包括fromKeyKey) 到 最后一个节点]
    public final SortedMap<K,V> tailMap(K fromKey) {
        return tailMap(fromKey, true);
    }

    // Map的Entry的集合
    abstract class EntrySetView extends AbstractSet<Map.Entry<K,V>> {
        private transient int size = -1, sizeModCount;

        // 获取EntrySet的大小
        public int size() {
            // 若SubMap是从“开始节点”到“结尾节点”，则SubMap大小就是原TreeMap的大小
            if (fromStart && toEnd)
                return m.size();
            // 若SubMap不是从“开始节点”到“结尾节点”，则调用iterator()遍历EntrySetView中的元素
            if (size == -1 || sizeModCount != m.modCount) {
                sizeModCount = m.modCount;
                size = 0;
                Iterator i = iterator();
                while (i.hasNext()) {
                    size++;
                    i.next();
                }
            }
            return size;
        }

        // 判断EntrySetView是否为空
        public boolean isEmpty() {
            TreeMap.Entry<K,V> n = absLowest();
            return n == null || tooHigh(n.key);
        }

        // 判断EntrySetView是否包含Object
        public boolean contains(Object o) {
            if (!(o instanceof Map.Entry))
                return false;
            Map.Entry<K,V> entry = (Map.Entry<K,V>) o;
            K key = entry.getKey();
            if (!inRange(key))
                return false;
            TreeMap.Entry node = m.getEntry(key);
            return node != null &&
                valEquals(node.getValue(), entry.getValue());
        }

        // 从EntrySetView中删除Object
        public boolean remove(Object o) {
            if (!(o instanceof Map.Entry))
                return false;
            Map.Entry<K,V> entry = (Map.Entry<K,V>) o;
            K key = entry.getKey();
            if (!inRange(key))
                return false;
            TreeMap.Entry<K,V> node = m.getEntry(key);
            if (node!=null && valEquals(node.getValue(),entry.getValue())){
                m.deleteEntry(node);
                return true;
            }
            return false;
        }
    }

    // SubMap的迭代器
    abstract class SubMapIterator<T> implements Iterator<T> {
        // 上一次被返回的Entry
        TreeMap.Entry<K,V> lastReturned;
        // 指向下一个Entry
        TreeMap.Entry<K,V> next;
        // “栅栏key”。根据SubMap是“升序”还是“降序”具有不同的意义
        final K fenceKey;
        int expectedModCount;

        // 构造函数
        SubMapIterator(TreeMap.Entry<K,V> first,
                       TreeMap.Entry<K,V> fence) {
            // 每创建一个SubMapIterator时，保存修改次数
            // 若后面发现expectedModCount和modCount不相等，则抛出ConcurrentModificationException异常。
            // 这就是所说的fast-fail机制的原理！
            expectedModCount = m.modCount;
            lastReturned = null;
            next = first;
            fenceKey = fence == null ? null : fence.key;
        }

        // 是否存在下一个Entry
        public final boolean hasNext() {
            return next != null && next.key != fenceKey;
        }

        // 返回下一个Entry
        final TreeMap.Entry<K,V> nextEntry() {
            TreeMap.Entry<K,V> e = next;
            if (e == null || e.key == fenceKey)
                throw new NoSuchElementException();
            if (m.modCount != expectedModCount)
                throw new ConcurrentModificationException();
            // next指向e的后继节点
            next = successor(e);
    lastReturned = e;
            return e;
        }

        // 返回上一个Entry
        final TreeMap.Entry<K,V> prevEntry() {
            TreeMap.Entry<K,V> e = next;
            if (e == null || e.key == fenceKey)
                throw new NoSuchElementException();
            if (m.modCount != expectedModCount)
                throw new ConcurrentModificationException();
            // next指向e的前继节点
            next = predecessor(e);
    lastReturned = e;
            return e;
        }

        // 删除当前节点(用于“升序的SubMap”)。
        // 删除之后，可以继续升序遍历；红黑树特性没变。
        final void removeAscending() {
            if (lastReturned == null)
                throw new IllegalStateException();
            if (m.modCount != expectedModCount)
                throw new ConcurrentModificationException();
            // 这里重点强调一下“为什么当lastReturned的左右孩子都不为空时，要将其赋值给next”。
            // 目的是为了“删除lastReturned节点之后，next节点指向的仍然是下一个节点”。
            //     根据“红黑树”的特性可知：
            //     当被删除节点有两个儿子时。那么，首先把“它的后继节点的内容”复制给“该节点的内容”；之后，删除“它的后继节点”。
            //     这意味着“当被删除节点有两个儿子时，删除当前节点之后，'新的当前节点'实际上是‘原有的后继节点(即下一个节点)’”。
            //     而此时next仍然指向"新的当前节点"。也就是说next是仍然是指向下一个节点；能继续遍历红黑树。
            if (lastReturned.left != null && lastReturned.right != null)
                next = lastReturned;
            m.deleteEntry(lastReturned);
            lastReturned = null;
            expectedModCount = m.modCount;
        }

        // 删除当前节点(用于“降序的SubMap”)。
        // 删除之后，可以继续降序遍历；红黑树特性没变。
        final void removeDescending() {
            if (lastReturned == null)
                throw new IllegalStateException();
            if (m.modCount != expectedModCount)
                throw new ConcurrentModificationException();
            m.deleteEntry(lastReturned);
            lastReturned = null;
            expectedModCount = m.modCount;
        }

    }

    // SubMap的Entry迭代器，它只支持升序操作，继承于SubMapIterator
    final class SubMapEntryIterator extends SubMapIterator<Map.Entry<K,V>> {
        SubMapEntryIterator(TreeMap.Entry<K,V> first,
                            TreeMap.Entry<K,V> fence) {
            super(first, fence);
        }
        // 获取下一个节点(升序)
        public Map.Entry<K,V> next() {
            return nextEntry();
        }
        // 删除当前节点(升序)
        public void remove() {
            removeAscending();
        }
    }

    // SubMap的Key迭代器，它只支持升序操作，继承于SubMapIterator
    final class SubMapKeyIterator extends SubMapIterator<K> {
        SubMapKeyIterator(TreeMap.Entry<K,V> first,
                          TreeMap.Entry<K,V> fence) {
            super(first, fence);
        }
        // 获取下一个节点(升序)
        public K next() {
            return nextEntry().key;
        }
        // 删除当前节点(升序)
        public void remove() {
            removeAscending();
        }
    }

    // 降序SubMap的Entry迭代器，它只支持降序操作，继承于SubMapIterator
    final class DescendingSubMapEntryIterator extends SubMapIterator<Map.Entry<K,V>> {
        DescendingSubMapEntryIterator(TreeMap.Entry<K,V> last,
                                      TreeMap.Entry<K,V> fence) {
            super(last, fence);
        }

        // 获取下一个节点(降序)
        public Map.Entry<K,V> next() {
            return prevEntry();
        }
        // 删除当前节点(降序)
        public void remove() {
            removeDescending();
        }
    }

    // 降序SubMap的Key迭代器，它只支持降序操作，继承于SubMapIterator
    final class DescendingSubMapKeyIterator extends SubMapIterator<K> {
        DescendingSubMapKeyIterator(TreeMap.Entry<K,V> last,
                                    TreeMap.Entry<K,V> fence) {
            super(last, fence);
        }
        // 获取下一个节点(降序)
        public K next() {
            return prevEntry().key;
        }
        // 删除当前节点(降序)
        public void remove() {
            removeDescending();
        }
    }
}
```

NavigableSubMap源码很多，但不难理解；读者可以通过源码和注释进行理解。

其实，读完NavigableSubMap的源码后，我们可以得出它的核心思想是：它是一个抽象集合类，为2个子类——"(升序)AscendingSubMap"和"(降序)DescendingSubMap"而服务；因为NavigableSubMap实现了许多公共API。它的最终目的是实现下面的一系列函数：

```java
headMap(K toKey, boolean inclusive) 
headMap(K toKey)
subMap(K fromKey, K toKey)
subMap(K fromKey, boolean fromInclusive, K toKey, boolean toInclusive)
tailMap(K fromKey)
tailMap(K fromKey, boolean inclusive)
navigableKeySet() 
descendingKeySet()
```

#### 3.10 TreeMap其它函数 ####

**1 顺序遍历和逆序遍历**

TreeMap的顺序遍历和逆序遍历原理非常简单。
由于TreeMap中的元素是**从小到大的顺序排列的。**因此，顺序遍历，就是从第一个元素开始，逐个向后遍历；而倒序遍历则恰恰相反，它是从最后一个元素开始，逐个往前遍历。

我们可以通过 keyIterator() 和 descendingKeyIterator()来说明！
keyIterator()的作用是**返回顺序的KEY的集合，**
descendingKeyIterator()的作用是**返回逆序的KEY的集合。**

keyIterator() 的代码如下：

```java
Iterator<K> keyIterator() {
    return new KeyIterator(getFirstEntry());
}
```

说明：从中我们可以看出keyIterator() 是返回以“第一个节点(getFirstEntry)” 为其实元素的迭代器。
KeyIterator的代码如下：



```java
final class KeyIterator extends PrivateEntryIterator<K> {
    KeyIterator(Entry<K,V> first) {
        super(first);
    }
    public K next() {
        return nextEntry().key;
    }
}
```



说明：KeyIterator继承于PrivateEntryIterator。当我们通过next()不断获取下一个元素的时候，就是执行的顺序遍历了。


descendingKeyIterator()的代码如下：

```java
Iterator<K> descendingKeyIterator() {
    return new DescendingKeyIterator(getLastEntry());
}
```

说明：从中我们可以看出descendingKeyIterator() 是返回以“最后一个节点(getLastEntry)” 为其实元素的迭代器。
再看看DescendingKeyIterator的代码：

```java
final class DescendingKeyIterator extends PrivateEntryIterator<K> {
    DescendingKeyIterator(Entry<K,V> first) {
        super(first);
    }
    public K next() {
        return prevEntry().key;
    }
}
```

说明：DescendingKeyIterator继承于PrivateEntryIterator。当我们通过next()不断获取下一个元素的时候，实际上调用的是prevEntry()获取的上一个节点，这样它实际上执行的是逆序遍历了。



### 四、TreeMap遍历方式 ###

#### 4.1 遍历TreeMap的键值对 ####

第一步：根据entrySet()获取TreeMap的“键值对”的Set集合。
第二步：通过Iterator迭代器遍历“第一步”得到的集合。

```java
// 假设map是TreeMap对象
// map中的key是String类型，value是Integer类型
Integer integ = null;
Iterator iter = map.entrySet().iterator();
while(iter.hasNext()) {
    Map.Entry entry = (Map.Entry)iter.next();
    // 获取key
    key = (String)entry.getKey();
        // 获取value
    integ = (Integer)entry.getValue();
}
```

#### 4.2 遍历TreeMap的键 ####

第一步：根据keySet()获取TreeMap的“键”的Set集合。
第二步：通过Iterator迭代器遍历“第一步”得到的集合。

```java
// 假设map是TreeMap对象
// map中的key是String类型，value是Integer类型
String key = null;
Integer integ = null;
Iterator iter = map.keySet().iterator();
while (iter.hasNext()) {
        // 获取key
    key = (String)iter.next();
        // 根据key，获取value
    integ = (Integer)map.get(key);
}
```

#### 4.3 遍历TreeMap的值 ####

第一步：根据value()获取TreeMap的“值”的集合。
第二步：通过Iterator迭代器遍历“第一步”得到的集合。

```java
// 假设map是TreeMap对象
// map中的key是String类型，value是Integer类型
Integer value = null;
Collection c = map.values();
Iterator iter= c.iterator();
while (iter.hasNext()) {
    value = (Integer)iter.next();
}
```

**TreeMap遍历测试程序如下：**

```java
import java.util.Map;
import java.util.Random;
import java.util.Iterator;
import java.util.TreeMap;
import java.util.HashSet;
import java.util.Map.Entry;
import java.util.Collection;

/*
 * @desc 遍历TreeMap的测试程序。
 *   (01) 通过entrySet()去遍历key、value，参考实现函数：
 *        iteratorTreeMapByEntryset()
 *   (02) 通过keySet()去遍历key、value，参考实现函数：
 *        iteratorTreeMapByKeyset()
 *   (03) 通过values()去遍历value，参考实现函数：
 *        iteratorTreeMapJustValues()
 *
 * @author skywang
 */
public class TreeMapIteratorTest {

    public static void main(String[] args) {
        int val = 0;
        String key = null;
        Integer value = null;
        Random r = new Random();
        TreeMap map = new TreeMap();

        for (int i=0; i<12; i++) {
            // 随机获取一个[0,100)之间的数字
            val = r.nextInt(100);
            
            key = String.valueOf(val);
            value = r.nextInt(5);
            // 添加到TreeMap中
            map.put(key, value);
            System.out.println(" key:"+key+" value:"+value);
        }
        // 通过entrySet()遍历TreeMap的key-value
        iteratorTreeMapByEntryset(map) ;
        
        // 通过keySet()遍历TreeMap的key-value
        iteratorTreeMapByKeyset(map) ;
        
        // 单单遍历TreeMap的value
        iteratorTreeMapJustValues(map);        
    }
    
    /*
     * 通过entry set遍历TreeMap
     * 效率高!
     */
    private static void iteratorTreeMapByEntryset(TreeMap map) {
        if (map == null)
            return ;

        System.out.println("\niterator TreeMap By entryset");
        String key = null;
        Integer integ = null;
        Iterator iter = map.entrySet().iterator();
        while(iter.hasNext()) {
            Map.Entry entry = (Map.Entry)iter.next();
            
            key = (String)entry.getKey();
            integ = (Integer)entry.getValue();
            System.out.println(key+" -- "+integ.intValue());
        }
    }

    /*
     * 通过keyset来遍历TreeMap
     * 效率低!
     */
    private static void iteratorTreeMapByKeyset(TreeMap map) {
        if (map == null)
            return ;

        System.out.println("\niterator TreeMap By keyset");
        String key = null;
        Integer integ = null;
        Iterator iter = map.keySet().iterator();
        while (iter.hasNext()) {
            key = (String)iter.next();
            integ = (Integer)map.get(key);
            System.out.println(key+" -- "+integ.intValue());
        }
    }
    

    /*
     * 遍历TreeMap的values
     */
    private static void iteratorTreeMapJustValues(TreeMap map) {
        if (map == null)
            return ;
        
        Collection c = map.values();
        Iterator iter= c.iterator();
        while (iter.hasNext()) {
            System.out.println(iter.next());
       }
    }
}
```



### 五、TreeMap示例 ###

下面通过实例来学习如何使用TreeMap

```java
import java.util.*;

/**
 * @desc TreeMap测试程序 
 *
 * @author skywang
 */
public class TreeMapTest  {

    public static void main(String[] args) {
        // 测试常用的API
        testTreeMapOridinaryAPIs();

        // 测试TreeMap的导航函数
        //testNavigableMapAPIs();

        // 测试TreeMap的子Map函数
        //testSubMapAPIs();
    }

    /**
     * 测试常用的API
     */
    private static void testTreeMapOridinaryAPIs() {
        // 初始化随机种子
        Random r = new Random();
        // 新建TreeMap
        TreeMap tmap = new TreeMap();
        // 添加操作
        tmap.put("one", r.nextInt(10));
        tmap.put("two", r.nextInt(10));
        tmap.put("three", r.nextInt(10));

        System.out.printf("\n ---- testTreeMapOridinaryAPIs ----\n");
        // 打印出TreeMap
        System.out.printf("%s\n",tmap );

        // 通过Iterator遍历key-value
        Iterator iter = tmap.entrySet().iterator();
        while(iter.hasNext()) {
            Map.Entry entry = (Map.Entry)iter.next();
            System.out.printf("next : %s - %s\n", entry.getKey(), entry.getValue());
        }

        // TreeMap的键值对个数        
        System.out.printf("size: %s\n", tmap.size());

        // containsKey(Object key) :是否包含键key
        System.out.printf("contains key two : %s\n",tmap.containsKey("two"));
        System.out.printf("contains key five : %s\n",tmap.containsKey("five"));

        // containsValue(Object value) :是否包含值value
        System.out.printf("contains value 0 : %s\n",tmap.containsValue(new Integer(0)));

        // remove(Object key) ： 删除键key对应的键值对
        tmap.remove("three");

        System.out.printf("tmap:%s\n",tmap );

        // clear() ： 清空TreeMap
        tmap.clear();

        // isEmpty() : TreeMap是否为空
        System.out.printf("%s\n", (tmap.isEmpty()?"tmap is empty":"tmap is not empty") );
    }


    /**
     * 测试TreeMap的子Map函数
     */
    public static void testSubMapAPIs() {
        // 新建TreeMap
        TreeMap tmap = new TreeMap();
        // 添加“键值对”
        tmap.put("a", 101);
        tmap.put("b", 102);
        tmap.put("c", 103);
        tmap.put("d", 104);
        tmap.put("e", 105);

        System.out.printf("\n ---- testSubMapAPIs ----\n");
        // 打印出TreeMap
        System.out.printf("tmap:\n\t%s\n", tmap);

        // 测试 headMap(K toKey)
        System.out.printf("tmap.headMap(\"c\"):\n\t%s\n", tmap.headMap("c"));
        // 测试 headMap(K toKey, boolean inclusive) 
        System.out.printf("tmap.headMap(\"c\", true):\n\t%s\n", tmap.headMap("c", true));
        System.out.printf("tmap.headMap(\"c\", false):\n\t%s\n", tmap.headMap("c", false));

        // 测试 tailMap(K fromKey)
        System.out.printf("tmap.tailMap(\"c\"):\n\t%s\n", tmap.tailMap("c"));
        // 测试 tailMap(K fromKey, boolean inclusive)
        System.out.printf("tmap.tailMap(\"c\", true):\n\t%s\n", tmap.tailMap("c", true));
        System.out.printf("tmap.tailMap(\"c\", false):\n\t%s\n", tmap.tailMap("c", false));
   
        // 测试 subMap(K fromKey, K toKey)
        System.out.printf("tmap.subMap(\"a\", \"c\"):\n\t%s\n", tmap.subMap("a", "c"));
        // 测试 
        System.out.printf("tmap.subMap(\"a\", true, \"c\", true):\n\t%s\n", 
                tmap.subMap("a", true, "c", true));
        System.out.printf("tmap.subMap(\"a\", true, \"c\", false):\n\t%s\n", 
                tmap.subMap("a", true, "c", false));
        System.out.printf("tmap.subMap(\"a\", false, \"c\", true):\n\t%s\n", 
                tmap.subMap("a", false, "c", true));
        System.out.printf("tmap.subMap(\"a\", false, \"c\", false):\n\t%s\n", 
                tmap.subMap("a", false, "c", false));

        // 测试 navigableKeySet()
        System.out.printf("tmap.navigableKeySet():\n\t%s\n", tmap.navigableKeySet());
        // 测试 descendingKeySet()
        System.out.printf("tmap.descendingKeySet():\n\t%s\n", tmap.descendingKeySet());
    }

    /**
     * 测试TreeMap的导航函数
     */
    public static void testNavigableMapAPIs() {
        // 新建TreeMap
        NavigableMap nav = new TreeMap();
        // 添加“键值对”
        nav.put("aaa", 111);
        nav.put("bbb", 222);
        nav.put("eee", 333);
        nav.put("ccc", 555);
        nav.put("ddd", 444);

        System.out.printf("\n ---- testNavigableMapAPIs ----\n");
        // 打印出TreeMap
        System.out.printf("Whole list:%s%n", nav);

        // 获取第一个key、第一个Entry
        System.out.printf("First key: %s\tFirst entry: %s%n",nav.firstKey(), nav.firstEntry());

        // 获取最后一个key、最后一个Entry
        System.out.printf("Last key: %s\tLast entry: %s%n",nav.lastKey(), nav.lastEntry());

        // 获取“小于/等于bbb”的最大键值对
        System.out.printf("Key floor before bbb: %s%n",nav.floorKey("bbb"));

        // 获取“小于bbb”的最大键值对
        System.out.printf("Key lower before bbb: %s%n", nav.lowerKey("bbb"));

        // 获取“大于/等于bbb”的最小键值对
        System.out.printf("Key ceiling after ccc: %s%n",nav.ceilingKey("ccc"));

        // 获取“大于bbb”的最小键值对
        System.out.printf("Key higher after ccc: %s%n\n",nav.higherKey("ccc"));
    }

}
```

##### 运行结果 #####

```java
{one=8, three=4, two=2}
next : one - 8
next : three - 4
next : two - 2
size: 3
contains key two : true
contains key five : false
contains value 0 : false
tmap:{one=8, two=2}
tmap is empty
```



