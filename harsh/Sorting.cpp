#include <iostream>
using namespace std;

class Company {
    float salary[100];
    int n;

public:
    void input() {
        cout << "Enter number of employees: ";
        cin >> n;
        cout << "Enter salaries: ";
        for (int i = 0; i < n; i++)
            cin >> salary[i];
    }

    void selectionSort() {
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
                if (salary[j] < salary[minIndex])
                    minIndex = j;
            swap(salary[i], salary[minIndex]);
        }
        cout << "Salaries sorted using Selection Sort.\n";
    }

    void bubbleSort() {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (salary[j] > salary[j + 1])
                    swap(salary[j], salary[j + 1]);
        cout << "Salaries sorted using Bubble Sort.\n";
    }

    void displayTopFive() {
        cout << "Top 5 Salaries:\n";
        for (int i = n - 1, count = 0; i >= 0 && count < 5; i--, count++)
            cout << salary[i] << endl;
    }

    void display() {
        for (int i = 0; i < n; i++)
            cout << salary[i] << " ";
        cout << endl;
    }
};

int main() {
    Company c;
    int ch;
    do {
        cout << "\n1. Input\n2. Selection Sort\n3. Bubble Sort\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            c.input();
            break;
        case 2:
            c.selectionSort();
            c.displayTopFive();
            break;
        case 3:
            c.bubbleSort();
            c.displayTopFive();
            break;
        case 4:
            c.display();
            break;
        case 5:
            cout << "Exiting...\n";
        }
    } while (ch != 5);
}
