#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int BinarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[100], n, key, choice;
    cout << "Enter number of Customer IDs: ";
    cin >> n;
    cout << "Enter " << n << " Account IDs (sorted for binary search): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    do {
        cout << "\n1. Linear Search\n2. Binary Search\n3. Display IDs\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Account ID to search (Linear): ";
            cin >> key;
            if (LinearSearch(arr, n, key) != -1)
                cout << "Account found.\n";
            else
                cout << "Account not found.\n";
            break;
        case 2:
            cout << "Enter Account ID to search (Binary): ";
            cin >> key;
            if (BinarySearch(arr, n, key) != -1)
                cout << "Account found.\n";
            else
                cout << "Account not found.\n";
            break;
        case 3:
            cout << "Customer Account IDs: ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
            break;
        case 4:
            cout << "Exiting...\n";
        }
    } while (choice != 4);
}
