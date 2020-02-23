#include <iostream>
#include <vector>
#include <memory>
using namespace std;


class Point{
private:
	double length,width;
public:
	Point(int x, int y):length(x),width(y){}
	Point(){}
	~Point() {}
};


class Shape{
public:
	virtual Point center() const = 0;
	virtual void move(Point to) = 0;
	
	virtual void draw() const = 0;
	virtual void rotate(int angle) = 0;

	virtual ~Shape() {}
};

void rotate_all(vector<Shape*>& v, int angle){
	for(auto p : v) p->rotate(angle);
}

class Circle : public Shape{
public:
	Circle(Point p, int rr);
	Point center() const { return x; }
	void move(Point to) { x = to; }

	void draw() const;
	void rotate(int) {}
private:
	Point x;  //圆心
	int r;    //半径
};

class Smiley: public Circle{
	vector<Shape*> eyes;
	Shape* mouth;
public:
	Smiley(Point p,int r):Circle{p,2},mouth(nullptr){}

	~Smiley()
	{
		delete mouth;
		for(auto p: eyes) delete p;
	}

	void move(Point to);
	void draw() const;
	void rotate(int);

	void add_eyes(Shape *s){ eyes.push_back(s); }
	void set_mouth(Shape *s);
	virtual void wink(int i);
};

void Smiley::draw() const{
	for(auto p:eyes) p->draw();
	mouth->draw();
}

unique_ptr<Shape> read_shape(istream& is){
					
}

template<typename Container,typename Value>
Value sum(const Container& c, Value v)
{
	for(auto x: c) v += x;
	return v;
}

template<typename T>
class Less_than{
	const T val;
public:
	Less_than(const T& v): val(v){}
	bool operator()(const T& x) const { return x < val; }
};

template<typename C,typename P>
int count(const C& c, P pred){
	int cnt = 0;
	for(const auto& x : c) 
		if(pred(x)) ++cnt;
	return cnt;
}


void compare(const vector<int>& v, int x)
{
	cout << "number of values less than " << x 
		 << ": " << count(v,Less_than<int>{x}) << endl;

	cout << "number of vales greater than " << x
		<< " :" << count(v, [&](int a){ return  a > x; } ) << endl;
}

template<typename Key,typename Value>
class Map{
	//
};

#include <string>
template<typename Value>
using String_Map = Map<string,Value>;

int main()
{
	String_Map<int> m;   //Map<string,int>
    vector<int> v{23,76,3,23,41,22,35,28,30,26,19} ;
    compare(v,40) ;
    return 0;
}

