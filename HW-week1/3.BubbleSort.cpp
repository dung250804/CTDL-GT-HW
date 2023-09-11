#include <iostream>
using namespace std;

void printArr(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void BubbleSort(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);

            }
        }
        printArr(a, n);
    }
}

int main()
{
    int a[] = {3, 4, 5, 6, 7, 8, 9, 10, 1, 2};
    int length = sizeof(a)/sizeof(a[0]);
    BubbleSort(a, length);
}
