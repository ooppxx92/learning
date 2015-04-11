#include <iostream>

using namespace std;

template <class T>
void BInsertSort(T a[],int length)
{
    T tmp;
    for(int i = 1;i < length;i++)
    {
	tmp = a[i];
	int low = 0,high = i - 1;
	int j,m;
	while(low <= high)
	{
	    m = (low + high)/2;
	    if(tmp <= a[m])
		high = m - 1;
	    else if(tmp > a[m])
		low = m + 1;
	}
	for(j = i - 1;j >= high + 1;j--)
	{
	    a[j+1]=a[j];
	}
	a[j + 1] = tmp;
    }
}
int main()
{
    int a[] = {5,2,4,1,9,7,8,6,6};
    BInsertSort(a,9);
    for(int i = 0;i < 9;i++)
	cout << a[i];
}
