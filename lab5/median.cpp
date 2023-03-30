#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cout<<"How many elements in an Array : ";
    int n;
    cin >> n;
    vector<int> a(n);
    cout<<"Enter the values for the array : " ;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        // sort the vector using bubble sort
        for(int j = 0; j < i; j++) {
            if(a[j] > a[i]) {
                swap(a[i], a[j]);
            }
        }
        // calculate the median 
        double median;
        if(i % 2 != 0) {
            median = (a[i/2] + a[(i/2)+1]) / 2.0;
        }
        else {
            median = a[i/2];
        }

        cout << median << endl;
    }
    return 0;
}