//insertion Sort 
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono; 

void display(int *array, int size) {
    for(int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void insertionSort(int *array, int size) {
    int key, j;
    for(int i = 1; i < size; i++) {
        key = array[i];
        j = i;
        while(j > 0 && array[j - 1] > key) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements:";
    cin >> n;
    int arr[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array before Insertion Sort:\n";
    display(arr, n);

   
    auto start = high_resolution_clock::now(); 

    insertionSort(arr, n);

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 

    cout << "Array after insertion Sort:\n";
    display(arr, n);

  
    cout << "Time taken by insertion sort: " << duration.count() << " microseconds" << endl;
}

