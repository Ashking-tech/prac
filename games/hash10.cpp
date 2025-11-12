#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class HashTable {
    Node* table[10];
public:
    HashTable() { for (int i = 0; i < 10; i++) table[i] = NULL; }

    int hashFunc(int key) { return key % 10; }

    void insert(int key) {
        int index = hashFunc(key);
        Node* newNode = new Node{key, table[index]};
        table[index] = newNode;
        cout << "Inserted " << key << endl;
    }

    void search(int key) {
        int index = hashFunc(key);
        Node* temp = table[index];
        while (temp) {
            if (temp->data == key) { cout << "Found at index " << index << endl; return; }
            temp = temp->next;
        }
        cout << "Not Found.\n";
    }

    void display() {
        for (int i = 0; i < 10; i++) {
            cout << i << ": ";
            Node* temp = table[i];
            while (temp) { cout << temp->data << " -> "; temp = temp->next; }
            cout << "NULL\n";
        }
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
