### 一、概要 ###

前面，我们已经系统的对List进行了学习。接下来，我们先学习Map，然后再学习Set；因为**Set的实现类都是基于Map来实现的**(如，HashSet是通过HashMap实现的，TreeSet是通过TreeMap实现的)。

首先，我们看看Map架构。

![](..\..\..\pic\8.jpg)

如上图：

1. Map 是**映射接口**，Map中存储的内容是**键值对(key-value)**。
2. AbstractMap 是**继承于Map的抽象类，它实现了Map中的大部分API**。其它Map的实现类可以通过继承AbstractMap来减少重复编码。
3. SortedMap 是继承于Map的接口。SortedMap中的内容是**排序的键值对**，排序的方法是通过比较器(Comparator)。
4. NavigableMap 是继承于SortedMap的接口。相比于SortedMap，NavigableMap有一系列的导航方法；如"获取大于/等于某对象的键值对"、“获取小于/等于某对象的键值对”等等。
5. TreeMap 继承于AbstractMap，且实现了NavigableMap接口；因此，TreeMap中的内容是“**有序的键值对**”！
6. HashMap 继承于AbstractMap，但没实现NavigableMap接口；因此，HashMap的内容是“**键值对，但不保证次序**”！
7. Hashtable 虽然不是继承于AbstractMap，但它继承于Dictionary(Dictionary也是键值对的接口)，而且也实现Map接口；因此，Hashtable的内容也是“**键值对，也不保证次序**”。但和HashMap相比，Hashtable是线程安全的，而且它支持通过Enumeration去遍历。
8. WeakHashMap 继承于AbstractMap。它和HashMap的键类型不同，**WeakHashMap的键是“弱键”**。



### 二、Map ###

#### 1. Map的定义如下： ####

```java
public interface Map<K,V> { }
```

Map 是一个键值对(key-value)映射接口。**Map映射中不能包含重复的键；每个键最多只能映射到一个值**。
Map 接口提供三种collection 视图，允许以**键集**、**值集**或**键-值映**射关系集的形式查看某个映射的内容。
Map 映射顺序。有些实现类，可以明确保证其顺序，如 TreeMap；另一些映射实现则不保证顺序，如 HashMap 类。
Map 的实现类应该提供2个“标准的”构造方法：**第一个，void（无参数）构造方法，用于创建空映射**；**第二个，带有单个 Map 类型参数的构造方法，用于创建一个与其参数具有相同键-值映射关系的新映射。**实际上，后一个构造方法允许用户复制任意映射，生成所需类的一个等价映射。尽管无法强制执行此建议（因为接口不能包含构造方法），但是 JDK 中所有通用的映射实现都遵从它。



#### 2. Map的API ####

```java
abstract void                 clear()
abstract boolean              containsKey(Object key)
abstract boolean              containsValue(Object value)
abstract Set<Entry<K, V>>     entrySet()
abstract boolean              equals(Object object)
abstract V                    get(Object key)
abstract int                  hashCode()
abstract boolean              isEmpty()
abstract Set<K>               keySet()
abstract V                    put(K key, V value)
abstract void                 putAll(Map<? extends K, ? extends V> map)
abstract V                    remove(Object key)
abstract int                  size()
abstract Collection<V>        values()
```



#### 3.说明： ####

* Map提供接口分别用于返回 键集、值集或键-值映射关系集。
      entrySet()用于返回**键-值集**的**Set集合**
      keySet()用于返回**键集**的**Set集合**
      values()用户返回**值集**的**Collection集合**
      因为Map中不能包含重复的键；每个键最多只能映射到一个值。

  ​	所以，**键-值集、键集都是Set，值集时Collection**。

* Map提供了“键-值对”、“根据键获取值”、“删除键”、“获取容量大小”等方法。



### 三、Map.Entry ###

#### 1. Map.Entry的定义如下： ####

```java
interface Entry<K,V> { }
```

Map.Entry是Map中内部的一个接口，Map.Entry是**键值对**，Map通过 entrySet() 获取Map.Entry的键值对集合，从而通过该集合实现对键值对的操作。

**Map.Entry的API**

```java
abstract boolean       equals(Object object)
abstract K             getKey()
abstract V             getValue()
abstract int           hashCode()
abstract V             setValue(V object)
```



### 四、AbstractMap ###

#### 1. AbstractMap的定义如下： ####

```java
public abstract class AbstractMap<K,V> implements Map<K,V> {}
```

AbstractMap类提供 Map 接口的骨干实现，以最大限度地减少实现此接口所需的工作。
要实现不可修改的映射，编程人员只需扩展此类并提供 entrySet 方法的实现即可，该方法将返回映射的映射关系 set 视图。通常，返回的 set 将依次在 AbstractSet 上实现。此 set 不支持 add() 或 remove() 方法，其迭代器也不支持 remove() 方法。

要实现可修改的映射，编程人员必须另外重写此类的 put 方法（否则将抛出 `UnsupportedOperationException`），entrySet().iterator() 返回的迭代器也必须另外实现其 remove 方法。

#### 2. AbstractMap的API ####

```java
abstract Set<Entry<K, V>>     entrySet()
         void                 clear()
         boolean              containsKey(Object key)
         boolean              containsValue(Object value)
         boolean              equals(Object object)
         V                    get(Object key)
         int                  hashCode()
         boolean              isEmpty()
         Set<K>               keySet()
         V                    put(K key, V value)
         void                 putAll(Map<? extends K, ? extends V> map)
         V                    remove(Object key)
         int                  size()
         String               toString()
         Collection<V>        values()
         Object               clone()
```



### 五、SortedMap ###

#### 1. SortedMap的定义如下： ####

```java
public interface SortedMap<K,V> extends Map<K,V> { }
```

SortedMap是一个继承于Map接口的接口。它是一个有序的SortedMap键值映射。
SortedMap的排序方式有两种：**自然排序** 或者 **用户指定比较器**。 插入有序 SortedMap 的所有元素都必须实现 Comparable 接口（或者被指定的比较器所接受）。

另外，所有SortedMap 实现类都应该提供 4 个“标准”构造方法：

* **void（无参数）构造方法**，它创建一个空的有序映射，按照键的自然顺序进行排序。
* 带有一个 Comparator 类型参数的构造方法
* 带有一个 Map 类型参数的构造方法**，它创建一个新的有序映射，其键-值映射关系与参数相同，按照键的自然顺序进行排序。
* **带有一个 SortedMap 类型参数的构造方法**，它创建一个新的有序映射，其键-值映射关系和排序方法与输入的有序映射相同。无法保证强制实施此建议，因为接口不能包含构造方法。

#### 2. SortedMap的API ####

```java
// 继承于Map的API
abstract void                 clear()
abstract boolean              containsKey(Object key)
abstract boolean              containsValue(Object value)
abstract Set<Entry<K, V>>     entrySet()
abstract boolean              equals(Object object)
abstract V                    get(Object key)
abstract int                  hashCode()
abstract boolean              isEmpty()
abstract Set<K>               keySet()
abstract V                    put(K key, V value)
abstract void                 putAll(Map<? extends K, ? extends V> map)
abstract V                    remove(Object key)
abstract int                  size()
abstract Collection<V>        values()
// SortedMap新增的API 
abstract Comparator<? super K>     comparator()
abstract K                         firstKey()
abstract SortedMap<K, V>           headMap(K endKey)
abstract K                         lastKey()
abstract SortedMap<K, V>           subMap(K startKey, K endKey)
abstract SortedMap<K, V>           tailMap(K startKey)
```



### 六、NavigableMap ###

#### 1. NavigableMap的定义如下： ####

```java
public interface NavigableMap<K,V> extends SortedMap<K,V> { }
```

`NavigableMap`是继承于`SortedMap`的接口。它是一个可导航的键-值对集合，具有了为给定搜索目标报告最接近匹配项的导航方法。
`NavigableMap`分别提供了获取“键”、“键-值对”、“键集”、“键-值对集”的相关方法。



#### 2. NavigableMap的API ####

```java
abstract Entry<K, V>             ceilingEntry(K key)
abstract Entry<K, V>             firstEntry()
abstract Entry<K, V>             floorEntry(K key)
abstract Entry<K, V>             higherEntry(K key)
abstract Entry<K, V>             lastEntry()
abstract Entry<K, V>             lowerEntry(K key)
abstract Entry<K, V>             pollFirstEntry()
abstract Entry<K, V>             pollLastEntry()
abstract K                       ceilingKey(K key)
abstract K                       floorKey(K key)
abstract K                       higherKey(K key)
abstract K                       lowerKey(K key)
abstract NavigableSet<K>         descendingKeySet()
abstract NavigableSet<K>         navigableKeySet()
abstract NavigableMap<K, V>      descendingMap()
abstract NavigableMap<K, V>      headMap(K toKey, boolean inclusive)
abstract SortedMap<K, V>         headMap(K toKey)
abstract SortedMap<K, V>         subMap(K fromKey, K toKey)
abstract NavigableMap<K, V>      subMap(K fromKey, boolean fromInclusive, K toKey, boolean toInclusive)
abstract SortedMap<K, V>         tailMap(K fromKey)
abstract NavigableMap<K, V>      tailMap(K fromKey, boolean inclusive)
```



#### 3.**说明**： ####

NavigableMap除了继承SortedMap的特性外，它的提供的功能可以分为4类：

第1类，**提供操作键-值对的方法。**
        lowerEntry、floorEntry、ceilingEntry 和 higherEntry 方法，它们分别返回与小于、小于等于、大于等于、大于给定键的键关联的 Map.Entry 对象。
        firstEntry、pollFirstEntry、lastEntry 和 pollLastEntry 方法，它们返回和/或移除最小和最大的映射关系（如果存在），否则返回 null。

第2类，**提供操作键的方法**。这个和第1类比较类似
        lowerKey、floorKey、ceilingKey 和 higherKey 方法，它们分别返回与小于、小于等于、大于等于、大于给定键的键。

第3类，**获取键集。**
       navigableKeySet、descendingKeySet分别获取正序/反序的键集。
第4类，获取键-值对的子集。



### 六、Dictionary ###

#### 1. Dictionary的定义如下： ####

```java
public abstract class Dictionary<K,V> {}
```

`NavigableMap`是JDK 1.0定义的键值对的接口，它也包括了操作键值对的基本函数。



#### 2. Dictionary的API ####

```java
abstract Enumeration<V>     elements()
abstract V                  get(Object key)
abstract boolean            isEmpty()
abstract Enumeration<K>     keys()
abstract V                  put(K key, V value)
abstract V                  remove(Object key)
abstract int                size()
```

