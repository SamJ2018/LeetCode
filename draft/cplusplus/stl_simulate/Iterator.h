#include <cstddef>

struct input_iterator_tag {};    //返回输入迭代器
struct output_iterator_tag {};   //返回输出迭代器


struct forward_iterator_tag : public input_iterator_tag {};					//返回前向迭代器
struct bidirectional_iterator_tag : public forward_iterator_tag {} ;		//返回双向迭代器
struct random_access_iterator_tag : public bidirectional_iterator_tag {};	//返回随机迭代器


template<class T, class Distance>
struct input_iterator{
	typedef input_iterator_tag iterator_category;       //返回类型
	typedef T                  value_type;              //迭代器所指对象类型
	typedef Distance           difference_type;         //迭代器间距类型
	typedef T*                 pointer;                 //迭代器操作结果累心
	typedef T&                 reference;               //解引用操作结果类型
};

//输出迭代器
struct output_iterator{
	typedef output_iterator_tag iterator_category;
	typedef void                value_type;
	typedef void                difference_type;
	typedef void				pointer;
	typedef void				reference;
};


//前向迭代器
template<class T,class Distance>
struct forward_iterator{
	typedef forward_iterator_tag  iterator_category;
	typedef T					  value_type;
	typedef Distance			  difference_type;
	typedef T*					  pointer;
	typedef T&					  reference;
};

//双向迭代器
template<class T,class Distance>
struct bidirectional_iterator{
	typedef bidirectional_iterator_tag iterator_category;
	typedef T					  value_type;
	typedef Distance			  difference_type;
	typedef T*					  pointer;
	typedef T&					  reference;
};



//随机迭代器
template<class T,class Distance>
struct random_access_iterator{
	typedef random_access_iterator  iterator_category;
	typedef T					  value_type;
	typedef Distance			  difference_type;
	typedef T*					  pointer;
	typedef T&					  reference;
};


