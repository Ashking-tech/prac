#include <iostream>
using namespace std;

struct Node {
    int roll;
    string name;
    Node* next;
};

class StudentList {
    Node* head;
public:
    StudentList() { head = NULL; }

    void addRecord(int r, string n) {
        Node* newNode = new Node{r, n, NULL};
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        cout << "Record Added.\n";
    }

    void display() {
        if (!head) { cout << "No Records.\n"; return; }
        Node* temp = head;
        while (temp) {
            cout << "Roll: " << temp->roll << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    void deleteRecord(int r) {
        if (!head) { cout << "List Empty.\n"; return; }
        if (head->roll == r) { head = head->next; cout << "Deleted.\n"; return; }
        Node* temp = head;
        while (temp->next && temp->next->roll != r)
            temp = temp->next;
        if (!temp->next) cout << "Not Found.\n";
        else {
            temp->next = temp->next->next;
            cout << "Deleted.\n";
        }
    }
};

int main() {
    StudentList s;
    int ch, r;
    string n;
    do {
        cout << "\n1.Add 2.Display 3.Delete 4.Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
        case 1: cout << "Enter Roll & Name: "; cin >> r >> n; s.addRecord(r, n); break;
        case 2: s.display(); break;
        case 3: cout << "Enter Roll to Delete: "; cin >> r; s.deleteRecord(r); break;
        case 4: cout << "Exiting...\n"; break;
        }
    } while (ch != 4);
}
