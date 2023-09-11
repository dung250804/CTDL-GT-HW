#include <iostream>
using namespace std;

void printArr(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}


void SelectionSort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        int tmp = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[tmp]){
                tmp = j;
            }

        }
        if(a[i] > a[tmp])
                swap(a[i], a[tmp]);
        printArr(a, n);
    }
}

int main(){
    int a[] = {3, 4, 5, 6, 7, 8, 9, 10, 1, 2};
    int n = sizeof(a) / sizeof(a[0]); //length
    SelectionSort(a, n);
}
