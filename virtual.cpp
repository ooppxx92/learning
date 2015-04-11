#include <iostream>

using namespace std;

class A{
    public :
	virtual ~A(){cout<<"A"<<endl;}
};
class B : public A{
    public:
	virtual ~B(){cout<<"B"<<endl;}
};
int main()
{
    A* a=new B;
    delete a;
    return 0;
}
