#include <iostream>
#include <vector>
using namespace std;

// A helper function to print the array with indices
void printArray(const vector<int>& arr) {
    // Print indices (optional, for clarity)
    cout << "Index: ";
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << i << "  ";
    }
    cout << "\nValue: ";
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i] << "  ";
    }
    cout << "\n---------------------------------\n";
}

void insertionSortVisualized(vector<int>& arr) {
    int n = arr.size();

    cout << "Initial array:\n";
    printArray(arr);

    // Perform insertion sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        cout << "\n--- Inserting " << key 
             << " (arr[" << i << "]) into the sorted subarray [0.."
             << i-1 << "] ---\n";

        // Move elements that are greater than key to one position ahead
        // of their current position
        while (j >= 0 && arr[j] > key) {
            cout << "Compare key (" << key << ") with arr[" << j << "] = "
                 << arr[j] << " -> " << arr[j] << " is bigger, shift it right.\n";

            arr[j + 1] = arr[j];
            printArray(arr); // Show the array after shifting

            j--;
        }

        // Place key into the correct position
        arr[j + 1] = key;
        cout << "Insert key (" << key << ") at index " << (j + 1) << ":\n";
        printArray(arr);
    }

    cout << "\nSorting complete. Final array:\n";
    printArray(arr);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Dynamic array using std::vector
    vector<int> arr(n);

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Run our insertion sort with visualization
    insertionSortVisualized(arr);

    return 0;
}
