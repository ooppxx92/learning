#include <iostream>

using namespace std;

int main()
{
    int i = 10;
    int *const j = &i;
    (*j)++;
    cout << i <<endl<< *j << endl;
    cout << &i <<endl<< j <<endl;
    return 0;
}
