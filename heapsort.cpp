//heapsort
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSortAscending(int arr[], int n) {
   
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

   
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    }
}

int main() {
    int N;

 
    cout << "Enter the number of elements (N): ";
    cin >> N;

    int arr[N];

   
    int choice;
    cout << "Enter 1 to manually enter elements, 2 for random values: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter " << N << " elements: ";
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
    } else if (choice == 2) {
        
        srand(time(0));

      
        for (int i = 0; i < N; i++) {
            arr[i] = rand() % 1000; 
        }
    } else {
        cout << "Invalid choice. Exiting program." << endl;
        return 1;
    }

    
    clock_t start_time = clock();

    heapSortAscending(arr, N);

    
    clock_t end_time = clock();

    double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    
    cout << "Sorted array in ascending order: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    
    cout << "Time taken for sorting: " << elapsed_time << " seconds" << endl;

    return 0;
}

