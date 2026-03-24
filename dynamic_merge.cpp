#include <iostream>
#include <string>
using namespace std;
#define MAX 10

class QuickSort {
private:
    int arr[MAX];
    int n;
    string name;
    string gender;
    int hsc_mark;
    float parent_income;
    long int aadhar_no;
    long int account_no;
public:
    void getData();
    void sort();
    void quickSort(int low, int high);
    int partition(int low, int high);
    void display();
    void displayDetails(); // New function to display member details
};

void QuickSort::getData() {
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your gender: ";
    cin >> gender;
    cout << "Enter your HSC mark: ";
    cin >> hsc_mark;
    cout << "Enter your parent's income: ";
    cin >> parent_income;
    cout << "Enter your Aadhar number: ";
    cin >> aadhar_no;
    cout << "Enter your account number: ";
    cin >> account_no;

    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void QuickSort::display() {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void QuickSort::displayDetails() {
    cout << "Name: " << name << endl;
    cout << "Gender: " << gender << endl;
    cout << "HSC Mark: " << hsc_mark << endl;
    cout << "Parent's Income: " << parent_income << endl;
    cout << "Aadhar Number: " << aadhar_no << endl;
    cout << "Account Number: " << account_no << endl;
}

void QuickSort::sort() {
    quickSort(0, n - 1);
}

void QuickSort::quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int QuickSort::partition(int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int main() {
    QuickSort qs;
    qs.getData();
    qs.sort();
    cout << "\nSorted array (Quick Sort): ";
    qs.display();

    // Print the member details
    cout << "\nDetails of the member: ";
    qs.displayDetails();

    return 0;
}
