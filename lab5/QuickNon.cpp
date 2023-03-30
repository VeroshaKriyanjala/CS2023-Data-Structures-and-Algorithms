#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <chrono>
#include <cstdlib>

using namespace std;

// partition function for quicksort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

// non-recursive quicksort function
void quicksort(vector<int>& arr, int low, int high) {
    stack<int> s;
    s.push(low);
    s.push(high);

    while(!s.empty()) {
        high = s.top();
        s.pop();
        low = s.top();
        s.pop();

        int pivot_index = partition(arr, low, high);

        if(pivot_index - 1 > low) {
            s.push(low);
            s.push(pivot_index - 1);
        }

        if(pivot_index + 1 < high) {
            s.push(pivot_index + 1);
            s.push(high);
        }
    }
}

int main() {
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        arr[i]=rand()%10000;
    }

    // start timer
    auto start = chrono::high_resolution_clock::now();

    // sort the array
    quicksort(arr, 0, n-1);

    // stop timer
    auto stop = chrono::high_resolution_clock::now();

    // print sorted array and time taken
    // cout << "Sorted array: ";
    // for(int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time taken by quicksort: " << duration.count() << " microseconds." << endl;

    return 0;
}