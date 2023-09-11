#include <iostream>
#include <vector>

using namespace std;

//merge two sorted arr [left -> middle] and [middle+1 -> right]
void mergeArr(int a[], int left, int middle, int right)
{
    vector<int> arr1(a + left, a + middle + 1);
    vector<int> arr2(a + middle + 1, a + right + 1);
    int i = 0, j = 0;
    while ( i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] < arr2[j])
        {
            a[left] = arr1[i];
            left++;
            i++;
        }
        else
        {
            a[left] = arr2[j];
            left++;
            j++;
        }
    }
    if(i >= arr1.size())
    {
        while(j < arr2.size())
        {
            a[left] = arr2[j]; left++; j++;
        }
    }
    else
    {
        while(i < arr1.size())
        {
            a[left] = arr1[i]; left++; i++;
        }
    }
}

void mergeSort(int a[], int left, int right)
{
    if(left < right)
    {
        int middle = (left + right) / 2;
        mergeSort(a, left, middle);
        mergeSort(a, middle + 1, right);
        mergeArr(a, left, middle, right);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n-1);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
