#include <iostream>
#include <algorithm>

class Vector{
private:
	double *elem;
	int sz;
public:
	Vector(){};
	Vector(int i) : sz(i){}
	Vector(std::initializer_list<double>);
	double operator[](int i) { return elem[i]; }
	int size()const{ return sz; }
	void Push_back(double);
};


Vector::Vector(std::initializer_list<double> lst):
			elem{new double[lst.size()]},sz{(int)lst.size()}{
	std::copy(lst.begin(),lst.end(),elem);
}

Vector read(std::istream& is){
	Vector v;
	//可以使用移动构造函数，使得返回数据量代价很低的数据
	for(double d; is >> d;) v.Push_back(d);
}

class Container{
public:
	virtual double operator[](int) = 0;
	virtual int size() = 0;
	virtual ~Container(){}
};

class Vector_Container: public Container{
private:
	Vector v;
public:
	double operator[](int i){ return v[i]; }
	int size() const{ return v.size(); }
	Vector_Container(double s):v(s){}
	~Vector_Container(){}
};


int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

