#include <iostream>

using namespace std;

class A{
    public:
	virtual void hehe()
	{
	    cout << "a"<<endl;
	}
};
class B:public A{
    public:
	void hehe()
	{
	    cout << "b"<<endl;
	}
};
int main()
{
    B *b = new B;
    b->hehe();
    A *a = new A;
    a->hehe();
    a = b;
    a->hehe();
}
