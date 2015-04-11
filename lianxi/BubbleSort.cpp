#include <iostream>

using namespace std;

void BubbleSort(int a[],int length)
{
    for(int i = 0;i < length - 1;i++)
	for(int j = i + 1;j < length;j++)
	{
	    if(a[j] < a[j-1])
	    {
		int tmp = a[j];
		a[j] = a[j - 1];
		a[j - 1] = tmp;
	    }
	}
}
int main()
{
    int a[] = {2,1,66,4,3,7};
    BubbleSort(a,6);
    for(int i = 0;i < 6;i++)
	cout << a[i]<<endl;
}
