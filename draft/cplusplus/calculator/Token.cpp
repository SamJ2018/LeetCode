#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int no_of_error = 0;
map<string,double> table;
static double prim(bool);
static double expr(bool);
static double term(bool);
static double error(const string&);

enum class Kind : char {
	name, number ,end,
	plus =  '+', minus = '-', mul = '*' , div = '/' , print = ';' ,assign = '=', lp = '(' ,rp = ')'
};

struct Token {
	Kind kind;
	string string_value;
	double numeber_value;
};

class Token_stream
{
public:
	Token get(); // 读取并获取下一个单词
	const Token& current();


	Token_stream(istream& s):ip{&s},owns(false){}
	Token_stream(istream* p):ip{p},owns{true}{}

	~Token_stream(){close();}

	void set_input(istream &s){ close(); ip = &s; owns = false;}
	void set_iput(istream *p) {close(); ip = p; owns = true;}
private:
	void close(){if (owns) delete ip;}
	
	istream* ip;
	bool owns;
	Token ct {Kind::end};
};

//全局变量

Token_stream ts{cin};


Token Token_stream::get()
{
	char ch = 0;
	*ip >> ch;

	switch(ch)
	{
	case 0:
		return ct = {Kind::end};
	case ';':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
		return ct = { static_cast<Kind>(ch) };   
	case '0': case '1': case '2': case '3' : case '4': case '5' : case '6' : case '7': case '8': case '9':
	case '.':
		ip -> putback(ch);
		*ip >> ct.numeber_value;
		ct.kind = Kind::number;
		return ct;
	default:
		if(isalpha(ch)){
			ip->putback(ch);
			*ip >> ct.string_value;
			ct.kind = Kind::name;
			return ct;
		}
		error("bad token");
		return ct = {Kind::print};
	}
}



//一次寻找加法和减法所需要的项目
static double expr(bool get)
{
	double left = term(get);

	for(;;)
	{
		switch(ts.current().kind)
		{
		case Kind::plus:
			left += term(true);
			break;
		case Kind::minus:
			left -= term(true);
			break;
		default:
			return left;
		}
	}
}


//对term执行乘法和除法操作

static double term(bool get)
{
	double left = prim(get);

	for(;;)
	{
		switch(ts.current().kind)
		{
		case Kind::mul:
			left *= prim(true);
			break;
		case Kind::div:
			if(auto d = prim(true)){
				left /= d;
				break;
			}
			return error("divide by 0");
		defualt:
			return left;
		}
	}
}

//函数prim 处理 初等项  
static double prim(bool get)
{ 
	if(get) ts.get();  // 获取下个一个单词

	switch(ts.current().kind){
	case Kind::number:
		{
			double v = ts.current().numeber_value;
			ts.get();
			return v;
		}

	case Kind::name:
		{
			double &v = table[ts.current().string_value];
			//看到了'=' 进行赋值运算
			if(ts.get().kind == Kind::assign){
				v = expr(true); 
			}
			return v;
		}
	case Kind::minus:   //一元减法
		return -prim(true);
	case Kind::lp:
		{
			auto e = expr(true);
			if(ts.current().kind != Kind::rp){
				return error("')' expected");
				ts.get();
				return e;
			}
		}
	default:
		return error("primary expected");
	}
}


static double error(const string &s)
{
	no_of_error++;
	cerr << "error:"<< s << "\n";
	return 1;
}


void calculate()
{
	for(;;)
	{
		ts.get();
		if(ts.current().kind == Kind::end) break;
		if(ts.current().kind == Kind::print) continue;
		cout << expr(false) << '\n';
	}
}


int main(int argc,char *argv[])
{
	switch(argc){
	case 1:
		break;
	case 2:
		ts.set_iput(new istringstream{argv[1]});
		break;
	default:
		error("too many arguments");
		return 1;
	}
	table["pi"]  = 3.141592653587932385;
	table["e"] = 2.7182818284590452345;

	calculate();

	return no_of_error;
}

