### 一、说明
下面先看看Collection的一些框架类的关系图：
![alt](../../pic/2.jpg)

Collection是一个接口，它主要的两个分支是：`List` 和 `Set`。

List和Set都是接口，它们继承于Collection。
*   List是有序的队列，List中可以有重复的元素；
*   而Set是数学概念中的集合，Set中没有重复元素！

List和Set都有它们各自的实现类。

  1. 为了方便，我们抽象出了`AbstractCollection`抽象类，它实现了`Collection`中的绝大部分函数；这样，在`Collection`的实现类中，我们就可以通过继承`AbstractCollection`省去重复编码。`AbstractList`和`AbstractSet`都继承于`AbstractCollection`，具体的`List`实现类继承于`AbstractList`，而`Set`的实现类则继承于`AbstractSet`。

  2. 另外，`Collection`中有一个`iterator()`函数，它的作用是返回一个`Iterator`接口。通常，我们通过`Iterator`迭代器来遍历集合。`ListIterator`是`List`接口所特有的，在`List`接口中，通过`ListIterator()`返回一个`ListIterator`对象。




### 二、Collection简介
**Collection的定义如下：**
```java
public interface Collection<E> extends Iterable<E> {}
```
它是一个接口，是高度抽象出来的集合，它包含了集合的基本操作：
>添加、删除、清空、遍历(读取)、是否为空、获取大小、是否保护某元素等等。

Collection接口的所有子类(直接子类和间接子类)都必须实现2种构造函数：
==不带参数的构造函数== 和 ==参数为Collection的构造函数==。带参数的构造函数，可以用来转换Collection的类型。

```java
// Collection的API
abstract boolean         add(E object)
abstract boolean         addAll(Collection<? extends E> collection)
abstract void            clear()
abstract boolean         contains(Object object)
abstract boolean         containsAll(Collection<?> collection)
abstract boolean         equals(Object object)
abstract int             hashCode()
abstract boolean         isEmpty()
abstract Iterator<E>     iterator()
abstract boolean         remove(Object object)
abstract boolean         removeAll(Collection<?> collection)
abstract boolean         retainAll(Collection<?> collection)
abstract int             size()
abstract <T> T[]         toArray(T[] array)
abstract Object[]        toArray()
```




### 三、List简介
**List的定义如下：**
```java
public interface List<E> extends Collection<E> {}
```
List是一个继承于Collection的接口，即List是集合中的一种。List是有序的队列，List中的每一个元素都有一个索引；第一个元素的索引值是0，往后的元素的索引值依次+1。和Set不同，List中允许有重复的元素。

1. List的官方介绍如下：

>A List is a collection which maintains an ordering for its elements. Every element in the List has an index. Each element can thus be accessed by its index, with the first index being zero. Normally, Lists allow duplicate elements, as compared to Sets, where elements have to be unique.


2. 关于API方面。既然List是继承于Collection接口，它自然就包含了Collection中的全部函数接口；由于List是有序队列，它也额外的有自己的API接口。
>主要有“添加、删除、获取、修改指定位置的元素”、“获取List中的子队列”等。

```java
// Collection的API
abstract boolean         add(E object)
abstract boolean         addAll(Collection<? extends E> collection)
abstract void            clear()
abstract boolean         contains(Object object)
abstract boolean         containsAll(Collection<?> collection)
abstract boolean         equals(Object object)
abstract int             hashCode()
abstract boolean         isEmpty()
abstract Iterator<E>     iterator()
abstract boolean         remove(Object object)
abstract boolean         removeAll(Collection<?> collection)
abstract boolean         retainAll(Collection<?> collection)
abstract int             size()
abstract <T> T[]         toArray(T[] array)
abstract Object[]        toArray()
// 相比与Collection，List新增的API：
abstract void                add(int location, E object)
abstract boolean             addAll(int location, Collection<? extends E> collection)
abstract E                   get(int location)
abstract int                 indexOf(Object object)
abstract int                 lastIndexOf(Object object)
abstract ListIterator<E>     listIterator(int location)
abstract ListIterator<E>     listIterator()
abstract E                   remove(int location)
abstract E                   set(int location, E object)
abstract List<E>             subList(int start, int end)
```




### 四、Set简介
**Set的定义如下：**
```java
public interface Set<E> extends Collection<E> {}
```
Set是一个继承于Collection的接口，即Set也是集合中的一种。==Set是没有重复元素的集合。==

**关于API方面。Set的API和Collection完全一样。**

```java
// Set的API
abstract boolean         add(E object)
abstract boolean         addAll(Collection<? extends E> collection)
abstract void             clear()
abstract boolean         contains(Object object)
abstract boolean         containsAll(Collection<?> collection)
abstract boolean         equals(Object object)
abstract int             hashCode()
abstract boolean         isEmpty()
abstract Iterator<E>     iterator()
abstract boolean         remove(Object object)
abstract boolean         removeAll(Collection<?> collection)
abstract boolean         retainAll(Collection<?> collection)
abstract int             size()
abstract <T> T[]         toArray(T[] array)
abstract Object[]         toArray()
```




### 五、抽象接口
#### 1、AbstractCollection
**AbstractCollection的定义如下：**
```java
public abstract class AbstractCollection<E> implements Collection<E> {}
```
   1.1 AbstractCollection是一个抽象类，它实现了Collection中除iterator()和size()之外的函数。
   1.2 AbstractCollection的主要作用：它实现了Collection接口中的大部分函数。从而方便其它类实现Collection。
>比如ArrayList、LinkedList等，它们这些类想要实现Collection接口，通过继承AbstractCollection就已经实现了大部分的接口了。  




#### 2、AbstractList
**AbstractList的定义如下：**
```java
public abstract class AbstractList<E> 
    extends AbstractCollection<E> 
        implements List<E> {}
```
*   AbstractList是一个继承于AbstractCollection，并且实现List接口的抽象类。它实现了List中除size()、get(int location)之外的函数。
*   AbstractList的主要作用：它实现了List接口中的大部分函数。从而方便其它类继承List。另外，和AbstractCollection相比，AbstractList抽象类中，实现了iterator()接口。




#### 3、AbstractSet
**AbstractSet的定义如下：** 
```java
public abstract class AbstractSet<E> 
    extends AbstractCollection<E> 
        implements Set<E> {}
```
*   AbstractSet是一个继承于AbstractCollection，并且实现Set接口的抽象类。由于Set接口和Collection接口中的API完全一样，Set也就没有自己单独的API。和AbstractCollection一样，它实现了List中除iterator()和size()之外的函数。
*   AbstractSet的主要作用：它实现了Set接口中的大部分函数。从而方便其它类实现Set接口。



 ### 六、迭代器
#### 1、Iterator
**Iterator的定义如下：**
```java
public interface Iterator<E> {}
```
Iterator是一个接口，它是集合的迭代器。集合可以通过Iterator去遍历集合中的元素。Iterator提供的API接口:
>包括：是否存在下一个元素、获取下一个元素、删除当前元素。

==注意：Iterator遍历Collection时，是fail-fast机制的。==
>即，当某一个线程A通过iterator去遍历某集合的过程中，若该集合的内容被其他线程所改变了；那么线程A访问集合时，就会抛出ConcurrentModificationException异常，产生fail-fast事件。关于fail-fast的详细内容，我们会在后面专门进行说明。TODO

```java
// Iterator的API
abstract boolean hasNext()
abstract E next()
abstract void remove()
```



#### 2、ListIterator
**ListIterator的定义如下：**

```java
public interface ListIterator<E> extends Iterator<E> {}
```
ListIterator是一个继承于Iterator的接口，它是队列迭代器。专门用于便利List，能提供向前/向后遍历。
相比于Iterator，它==新增了添加、是否存在上一个元素、获取上一个元素等等API接口==。

```java
// ListIterator的API
// 继承于Iterator的接口
abstract boolean hasNext()
abstract E next()
abstract void remove()
// 新增API接口
abstract void add(E object)
abstract boolean hasPrevious()
abstract int nextIndex()
abstract E previous()
abstract int previousIndex()
abstract void set(E object)
```