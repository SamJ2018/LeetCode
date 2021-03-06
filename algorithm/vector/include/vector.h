#pragma once
#include <iostream>
using namespace std;


//寻秩访问
typedef int Rank; 
#define DEFAULT_CAPACITY 3 //默认初始容量（实际可设置更大）

template<typename T>
class Vector{
protected:
	Rank _size;    //规模
	int _capacity; //容量
	T* _elem;       //数据区

	/*复制数组区间A[lo, hi)] */
	void copyFrom(T const* A,Rank lo, Rank hi);  

	/*空间不足时扩容*/
	void expand();

	/*装填因子过小时压缩*/
	void shrink();

	/*交换*/
	bool bubble(Rank lo,Rank hi);
	Rank bubble2(Rank lo,Rank h);

	/*选取最大元素*/
	Rank max(Rank lo,Rank hi);

	/*归并算法*/
	void merge(Rank lo,Rank mi,Rank hi);

	/*轴点构造算法*/
	Rank partition ( Rank lo, Rank hi  ); 

	/*---------------------排序相关----------------------*/
	/*起泡排序算法*/
	void bubbleSort(Rank lo,Rank hi);
	void bubbleSort_fast(Rank lo,Rank hi);

	/*选择排序算法*/
	Rank selectionSort(Rank lo,Rank hi);

	/*归并排序算法*/
	void mergeSort(Rank lo,Rank hi);

	/*快速排序算法*/
	void quickSort(Rank lo,Rank hi);

	/*堆排序*/
	void heapSort(Rank lo,Rank hi);

public:
	/*----------------构造函数---------------*/
	//容量为c、规模为s、所有元素初始化为v
	Vector(int c = DEFAULT_CAPACITY,int s = 0, T v = 0)
	{
		_elem = new T[_capacity = c];
		for(_size = 0; _size < s; _elem[_size++] = v);
	}


	//数组整体复制
	Vector(T const* A,Rank n)
	{
		copyFrom(A,0,n);
	}

	//数组区间复制
	Vector(T const* A,Rank lo,Rank hi)	
	{
		copyFrom(A,lo,hi);
	}

	//向量整体复制
	Vector(Vector<T> const& V)
	{
		copyFrom(V._elem,0,V._size);
	}

	//向量区间复制
	Vector(Vector<T> const& V,int lo, int hi)
	{
		copyFrom(V._elem,lo,hi);
	}

	/*----------------析构函数-----------------*/
	//释放内部空间
	~Vector()
	{
		delete[] _elem;
	}

	/*----------------只读操作---------------------*/
	//判断规模大小
	Rank size() const 
	{
		return _size;
	}

	//判断是否为空
	bool empty() const 
	{
		return !_size;
	}

	//判断向量是否已排序
	int disordered() const;
	
	//无序向量整体查找
	Rank find(T const& e) const 
	{
		return find(e,0,_size);
	}

	//无序向量区间查找
	Rank find(T const& e,Rank lo,Rank hi) const;

	//有序向量整体查找
	Rank search(T const& e) const
	{
		return _size <= 0 ? -1 : search(e,0,_size);
	}

	//有序向量区间查找
	Rank search(T const& e,Rank lo,Rank hi) const;

	/*-----------------可写的访问接口--------------*/
	//重载下标操作符，可以类似于数组形式引用各元素
	T& operator[](Rank rl)const;

	//重载赋值操作符，以便直接克隆向量
	Vector<T>& operator=(Vector<T> const&);

	//删除秩为r的元素
	T remove(Rank r);

	//删除秩在区间[lo, hi)之内的元素
	int remove(Rank lo,Rank hi);

	//插入元素
	Rank insert(Rank r,T const& e);

	//默认作为末元素插入
	Rank insert(T const& e)
	{
		return insert(_size,e);
	}

	//对[lo, hi)排序
	void sort(Rank lo,Rank hi);

	//整体排序
	void sort(){sort(0,_size);}

	//对[lo, hi)置乱
	void unsort(Rank lo,Rank hi);

	//整体置乱
	void unsort(){unsort(0,_size);}

	//无序去重
	int deduplicate();
	int deduplicate2();

	//有序去重
	int uniquify();

	/*------------------遍历---------------*/
	//遍历（使用函数指针，只读或局部性修改）
	void traverse(void (*)(T&));

	//遍历（使用函数对象，可全局性修改）
	template<typename VST>
	void traverse(VST&);

};

template<typename T>
void Vector<T>::traverse(void (*vist)(T&))
{
	for(int i = 0; i < _size; ++i)
		vist(_elem[i]);
	cout << endl;	
}

template<typename T>
template<typename VST>
void Vector<T>::traverse(VST& visit)
{
	for(int i = 0; i < _size; ++i)
		visit(_elem[i]);
}

template<typename T>
void Vector<T>::copyFrom(T const* A,Rank lo,Rank hi)
{
	_elem = new T[_capacity = 2 * (hi - lo)];
	_size = 0;
	while(lo < hi) 
		_elem[_size++] = A[lo++];
}


template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& V)
{
	//释放原有内容
	if(_elem) delete[] _elem;  
	//整体复制
	copyFrom(V._elem,0,V.size());

	//返回当前对象的引用，以便链式赋值
	return *this;
}


//重载[]
template<typename T>
T& Vector<T>::operator[](Rank r) const
{
	return _elem[r];  //assert: 0 <= r < _size
}


template<typename T>
bool Vector<T>::bubble(Rank lo, Rank hi)
{
	bool sorted = true;
	while(++lo < hi)
		if(_elem[lo - 1] > _elem[lo])
		{
			sorted = false;
			swap(_elem[lo - 1], _elem[lo]);
		}
	return sorted;
}


template<typename T>
Rank Vector<T>::bubble2(Rank lo ,Rank hi)
{
	Rank last = lo;
	while (++lo < hi)
	{
		if(_elem[lo - 1] > _elem[lo])
		{
			last = lo;
			swap(_elem[lo - 1] ,_elem[lo]);
		}
	}
	return last;
}

template<typename T>
void Vector<T>::bubbleSort(Rank lo,Rank hi)
{
	while(!bubble(lo,hi--));
}

template<typename T>
void Vector<T>::bubbleSort_fast(Rank lo,Rank hi)
{
	while(lo < (hi = bubble2(lo,hi)));
}

template<typename T>
void Vector<T>::sort(Rank lo,Rank hi)
{
	bubbleSort_fast(lo,hi);
}

template<typename T>
int Vector<T>::deduplicate()
{
	int oldSize= _size;
	Rank i = 1;
	while(i < _size)
	{
		find(_elem[i],0,i) < 0 ? ++i : remove(i);
	}
	return oldSize;
}

template<typename T>
int Vector<T>::deduplicate2()
{
	int oldSize = _size;
	int i = -1;
	while(++i < _size -1)
	{
		int j = i + 1;
		while(j < _size)
			if(_elem[i] == _elem[j]) remove(j);
			else j++;
	}
	return oldSize-_size;
}

template<typename T>
int Vector<T>::disordered() const
{
	int n = 0;
	for(int i = 1; i < _size; i++)
		if(_elem[i - 1] > _elem[i]) ++n;
	return n;
}

template<typename T>
void Vector<T>::expand()
{
	if(_size < _capacity)
		return ;
	if(_capacity < DEFAULT_CAPACITY)
		_capacity = DEFAULT_CAPACITY;

	T* oldElem = _elem;
	_elem = new T[_capacity <<= 1];
	for(int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];
	delete[] oldElem;
}

template<typename T>
Rank Vector<T>::find(T const& e,Rank lo,Rank hi) const
{
	while(lo < hi-- && e != _elem[hi]);
	return hi;
}
	
template<typename T>
Rank Vector<T>::insert(Rank r,T const& e)
{
	expand();
	for(int i = _size; i > r; --i) 
		_elem[i] = _elem[i-1];
	_elem[r] = e;
	_size++;
	return r;
}




















