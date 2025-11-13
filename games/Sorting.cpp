#include <iostream>
using namespace std;

void selectionsort(float arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if (arr[j]<arr[min])
            min =j;
        }
        swap(arr[i],arr[min]);
        
    }
    cout << "Salaries Sorted using selection sort:"<< endl;
    for(int i=0;i<n;i++)
    cout << arr[i]<< " ";
    cout << endl;
    
}
void bubblesort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    cout << "\nSalaries Sorted using Bubble Sort:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void displayTopFive(float arr[],int n){
    cout << "Top 5 Highest Salaries:" << endl;
    int count =0;
    for(int i=n-1;i >= 0 && count<5; i--, count++)
    cout << arr[i] << " ";
    cout << endl;
}


int main(){
    float salary[100];
    int n, choice;
    
    cout << "Enter number of employees: ";
    cin >> n;
    cout << "Enter Salaries of " << n << " employees" << endl;
    for(int i=0; i<n;i++)
    cin >> salary[i];
    
    do{
        cout << "====== SALARY MENU====="<< endl;
        cout << "1. Selection Sort" << endl;
        cout << "2. Bubble Sort"<< endl;
        cout << "3. Display top 5 salaries" << endl;
        cout << "4. Display All Salarie: " << endl;
        cout << "5. Exit"<< endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
            selectionsort(salary,n);
            break;
            case 2:
            bubblesort(salary,n);
            break;
            case 3:
            displayTopFive(salary,n);
            break;
            case 4:
            cout << "Employee Salaries: ";
            for (int i=0; i<n;i++)
            cout << salary[i]<< " ";
            cout << endl;
            break;
            case 5:
            cout << "Exiting Program.." << endl;
            break;
            default:
            cout << "Invalid Choice!! Try Again."<<endl;
            
        }
        
    }while(choice!=5);
    return 0;
}
