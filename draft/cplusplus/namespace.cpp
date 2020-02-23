#include <iostream>
#include <cstring>

using namespace std;
namespace First{

class Vector{
private:
	int len;
	char *elem;
public:
	Vector():elem{new char[20]},len(0){}
	void operator=(char*);
	void show(){cout << elem;}
//	friend ostream& operator<<(ostream& os,Vector &);
	int size();
	~Vector(){ cout << "deconstructor\n";}
};
int main();

}

//ostream& operator<<(ostream& os,First::Vector & v){
//	 os << v.elem;
//	 return os;
//}

void First::Vector::operator=(char *str){
	this->elem = str;
	this->len = strlen(str);
}

int First::Vector::size(){
	return len;
}


int main()
{
	First::Vector v;
	v = "hello world\n";
	cout << v;
	return 0;
}

