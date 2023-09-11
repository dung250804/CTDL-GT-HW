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


void insertArr(int a[], int t1, int t2)
{
    int n = sizeof(a) / sizeof(a[0]);
    int tmp = a[t2];
    for(int i = t2; i > t1; i--)
    {
        a[i] = a[i-1];
    }
    a[t1] = tmp;
}

void InsertionSort(int a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        if(a[i] < a[i-1])
        {
            int key = i;
            int des = i;
            while(des >= 0 && a[key] <= a[des])
            {
                des--;
            }
            des++;
            insertArr(a, des, key);
            printArr(a, n);
        }

    }
}

int main()
{
    int a[] = {9, 10, 1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]); //length
    InsertionSort(a, n);
}
