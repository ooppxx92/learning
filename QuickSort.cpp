#include <iostream>

using namespace std;

template <class T>
int Partition(T a[],int low,int high)
{
    T pivotkey = a[low];
    while(low < high)
    {
	while(low < high && a[high] >= pivotkey) high--;
	a[low]=a[high];
	while(low < high && a[low] <= pivotkey) low++;
	a[high]=a[low];
    }
    a[low]=pivotkey;
    return low;
}
template <class T>
void QuickSort(T a[],int low,int high)
{
    if(low < high)
    {
	T pivotloc = Partition(a,low,high);
	QuickSort(a,low,pivotloc - 1);
	QuickSort(a,pivotloc + 1,high);
    }
}
int main()
{
    int a[]={4,6,3,2,9,4,6,1};
    QuickSort(a,0,7);
    for(int i =0;i < 8;i++)
	cout << a[i];
}
