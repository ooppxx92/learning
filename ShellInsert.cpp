#include <iostream>

using namespace std;

template <class T>
void ShellInsert(T a[],int length,int dk)
{
    T tmp;
    for(int i = dk;i < length;i++)
    {
	tmp = a[i];
	int j;
	for(j = i - dk;j >= 0 && tmp < a[j];j-=dk)
	{
	    a[j + dk] = a[j];
	}
	a[j + dk] = tmp;
    }
}
template <class T>
void ShellSort(T a[],int dlta[],int length,int t)
{
    for(int k = 0;k < t;k++)
	ShellInsert(a,length,dlta[k]);
}

int main()
{
    int a[] = {4,5,2,3,6,7,8,1,9};
    int b[]={3,2,1};
    ShellSort(a,b,9,3);
    for(int i = 0;i < 9;i++)
	cout << a[i];
}
