#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b = temp;
    }

int partition (int A[], int p, int r){
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r- 1; j++){
        if (A[j] <= x){
            i++;
            swap (&A[i], &A[j]);
        }
    }
    swap (&A[i + 1], &A[r]);
    return (i + 1);
}

void quickSort(int A[], int p, int r){
    if (p < r){
        int q = partition(A, p,r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = rand() % 10000;

    auto start = chrono::high_resolution_clock::now();
    quickSort(a,0,n-1);
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // cout << "Sorted array:" << endl;
    // for (int i = 0; i < n; i++)
    //     cout << a[i] << " ";
    // cout << endl;

    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}
