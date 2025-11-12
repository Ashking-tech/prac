#include <iostream>
using namespace std;

class Queue {
    string events[10];
    int front, rear;

public:
    Queue() { front = -1; rear = -1; }

    void addEvent(string event) {
        if (rear == 9) { cout << "Queue Full!\n"; return; }
        if (front == -1) front = 0;
        events[++rear] = event;
        cout << "Event Added: " << event << endl;
    }

    void processEvent() {
        if (front == -1 || front > rear) { cout << "No Events.\n"; return; }
        cout << "Processing: " << events[front++] << endl;
    }

    void display() {
        if (front == -1 || front > rear) { cout << "No Pending Events.\n"; return; }
        cout << "Pending Events:\n";
        for (int i = front; i <= rear; i++) cout << events[i] << endl;
    }

    void cancelEvent(string event) {
        if (front == -1 || front > rear) { cout << "No Events.\n"; return; }
        int pos = -1;
        for (int i = front; i <= rear; i++)
            if (events[i] == event) pos = i;
        if (pos == -1) { cout << "Event Not Found.\n"; return; }
        for (int i = pos; i < rear; i++) events[i] = events[i + 1];
        rear--;
        cout << "Cancelled: " << event << endl;
    }
};

int main() {
    Queue q;
    int ch;
    string e;
    do {
        cout << "\n1.Add  2.Process  3.Display  4.Cancel  5.Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
        case 1: cout << "Enter Event: "; cin >> e; q.addEvent(e); break;
        case 2: q.processEvent(); break;
        case 3: q.display(); break;
        case 4: cout << "Enter Event to Cancel: "; cin >> e; q.cancelEvent(e); break;
        case 5: cout << "Exiting...\n"; break;
        }
    } while (ch != 5);
}
