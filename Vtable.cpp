#include <iostream>

using namespace std;

class Base{
    public:
	virtual void f()
	{
	    cout << "Base::f" << endl;
	}
	virtual void g()
	{
	    cout << "Base::g" <<endl;
	}
	virtual void h()
	{
	    cout << "Base::h" <<endl;
	}
};
typedef void(*Fun) void;

int main()
{
    Base b;
    Fun pFun = NULL;
    cout << "virtual funtion address:" << (int*)(&b)<<endl;
    cout << "the first virtual funtion address:"<<(int*)*(int*)(&b)<<endl;

