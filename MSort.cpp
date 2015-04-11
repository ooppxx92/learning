#include <iostream>

using namespace std;

template <class T>
void merge(T source[],T temp[],int s,int m,int e)
{
    int i = s;
    int j = m + 1;
    int k = s;
    while(i <= m && j <= e)
    {
	if(source[i] < source[j])
	    temp[k++] = source[i++];
	else
	    temp[k++] = source[j++];
    }
    while(i <= m)
    	temp[k++] = source[i++];
    while(j <= e)
	temp[k++] = source[j++];
    for(int p = s;p <= e;p++)
	source[p] = temp[p];

}
template <class T>
void MergeSort(T source[],T temp[],int s,int e)
{
    if(s < e)
    {
	int m = (s + e)/2;
	MergeSort(source,temp,s,m);
	MergeSort(source,temp,m+1,e);
	merge(source,temp,s,m,e);
    }
}

int main()
{
    int a[]={85,2,33,44,12,45,42};
    int b[7];
    MergeSort(a,b,0,6);
    for(int i = 0;i < 7;i++)
	cout << a[i]<<endl;
}

