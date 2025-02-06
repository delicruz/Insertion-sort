#include <iostream>

using namespace std;

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++ ){
    int key = arr[i];
    int j = i-1;

    while (j >= 0 && arr[j] > key ) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}
}

int main() {
  int n;
    cout << "Enter the number of elements: ";
    cin >> n;   
    int *arr = new int[n];
    
    cout <<"Enter " << n << " elements " << endl;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
    }
    cout << endl;
    
    insertion_sort(arr, n);

    for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr; 
    return 0;
}