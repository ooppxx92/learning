#include <iostream>

using namespace std;

int Partition(int a[],int low,int high)
{
    int tmp = a[low];
    while(low < high)
    {
	if(tmp <= a[high] && low < high) high--;
	a[low] = a[high];
	if(tmp >= a[low] && low < high) low++;
	a[high] = a[low];
    }
    a[low] = tmp;
    return low;
}
void quicksort(int a[],int low,int high)
{
    if(low < high)
    {
    	int tmp = Partition(a,low,high);
    	quicksort(a,low,tmp-1);
    	quicksort(a,tmp + 1,high);
    }
}
int main()
{
    int a[]={3,6,2,4,9,4,1,66};
    quicksort(a,0,7);
    for(int i = 0;i < 8;i++)
	cout <<a[i]<<endl;
}

