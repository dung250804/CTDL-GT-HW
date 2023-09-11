#include <iostream>
using namespace std;
//l: left
//r: right
void QuickSort(int a[], int l, int r)
{
    if(l >= r) return;
    int i = l-1;
    int x = a[r];
    for(int j = l; j < r; j++)
    {
        if(a[j] < a[r])
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    QuickSort(a, l, i);
    QuickSort(a, i+2, r);
}

int main()
{
    int n;cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    QuickSort(a, 0, n-1);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
