#include <test.h>
void HeapAdjust(int a[],int i,int n)
{
    int tmp = a[i];
    int j = 2 * i + 1;
    while(j <= n - 1)
    {
	if(j < n - 1 && a[j] < a[j + 1])
	    j++;
	if(tmp >= a[j])
	    break;
	a[i] = a[j];
	i = j;
	j = 2 * i + 1;
    }
    a[i] = tmp;
}
void HeapSort(int a[],int n)
{
    for(int i = n/2 - 1;i >= 0;i--)
    {
	HeapAdjust(a,i,n);
    }
    for(int i = n - 1;i >= 1;i--)
    {
	int tmp = a[0];
	a[0] = a[i];
	a[i] = tmp;
	HeapAdjust(a,0,i);
    }
}
