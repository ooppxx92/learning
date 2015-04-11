#include <iostream>

using namespace std;

template <class T>
void HeapAdjust(T a[],int i,int n)
{
    int tmp = a[i];
    int j = 2 * i + 1;
    while(j <= n - 1)
    {
	if(j < n- 1 && a[j] < a[j+1])
	    j++;
	if(tmp >= a[j])
	    break;
	a[i] = a[j];
	i = j;
	j = 2 * i + 1;
    }
    a[i]=tmp;
}

template <class T>
void HeapSort(T a[],int n)
{
    for(int i = n/2 - 1;i >= 0;i--)
	HeapAdjust(a,i,n);
    for(int i = n - 1;i >= 1;i--)
    {
	int tmp = a[0];
	a[0] = a[i];
	a[i]=tmp;
	HeapAdjust(a,0,i);
    }
}

int  main()
{
    int a[] = {2,3,5,8,3,1};
    HeapSort(a,6);
    for(int i = 0;i < 6;i++)
	cout << a[i];
    return 0;
}
