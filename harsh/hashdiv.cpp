#include <iostream>
using namespace std;

class HashTable {
    int table[10];
public:
    HashTable() { for (int i = 0; i < 10; i++) table[i] = -1; }

    int hashFunc(int key) { return key % 10; }

    void insert(int key) {
        int index = hashFunc(key);
        for (int i = 0; i < 10; i++) {
            int newIndex = (index + i) % 10;
            if (table[newIndex] == -1) {
                table[newIndex] = key;
                cout << "Inserted at index " << newIndex << endl;
                return;
            }
        }
        cout << "Hash Table Full!\n";
    }

    void search(int key) {
        int index = hashFunc(key);
        for (int i = 0; i < 10; i++) {
            int newIndex = (index + i) % 10;
            if (table[newIndex] == key) { cout << "Found at index " << newIndex << endl; return; }
        }
        cout << "Not Found.\n";
    }

    void display() {
        for (int i = 0; i < 10; i++)
            cout << i << ": " << (table[i] == -1 ? -1 : table[i]) << endl;
    }
};

int main() {
    HashTable h;
    int ch, key;
    do {
        cout << "\n1.Insert 2.Search 3.Display 4.Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
        case 1: cout << "Enter key: "; cin >> key; h.insert(key); break;
        case 2: cout << "Enter key: "; cin >> key; h.search(key); break;
        case 3: h.display(); break;
        case 4: cout << "Exiting...\n"; break;
        }
    } while (ch != 4);
}
