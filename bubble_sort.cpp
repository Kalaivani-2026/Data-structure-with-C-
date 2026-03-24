/*
---------------------------------------------------------------------------------------------------------------------------------
EX:10
DATE:22.11.2024
SORTING ALGORITHM-MERGE SORTING
---------------------------------------------------------------------------------------------------------------------------------
*/
//Name:KALAIVANI S M 
//RollNo:23bec010
//Class:II-ECE
//Section:A
//Problem Statement:paperfree scholarship
#include <iostream>
#include <string>
using namespace std;
#define MAX 10

class BubbleSort {
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
    BubbleSort(string nm, string gd, int hsc, float income, long int aadhar, long int acc, int elements[], int size) {
        name = nm;
        gender = gd;
        hsc_mark = hsc;
        parent_income = income;
        aadhar_no = aadhar;
        account_no = acc;
        n = size;
        for (int i = 0; i < n; i++) {
            arr[i] = elements[i];
        }
    }
    void sort();
    void display();
    void displayDetails();
};

void BubbleSort::display() {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void BubbleSort::displayDetails() {
    cout << "Name: " << name << endl;
    cout << "Gender: " << gender << endl;
    cout << "HSC Mark: " << hsc_mark << endl;
    cout << "Parent's Income: " << parent_income << endl;
    cout << "Aadhar Number: " << aadhar_no << endl;
    cout << "Account Number: " << account_no << endl;
}

void BubbleSort::sort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int elements1[] = {5, 3, 8, 6, 2};
    int elements2[] = {9, 7, 4, 1, 5};
    int elements3[] = {6, 8, 2, 4, 7};
    int elements4[] = {3, 2, 6, 5, 1};
    int elements5[] = {8, 6, 3, 2, 1};

    BubbleSort members[] = {
        BubbleSort("Alice", "Female", 95, 50000.0, 123456789012, 9876543210, elements1, 5),
        BubbleSort("Bob", "Male", 85, 60000.0, 234567890123, 8765432109, elements2, 5),
        BubbleSort("Charlie", "Male", 92, 45000.0, 345678901234, 7654321098, elements3, 5),
        BubbleSort("Diana", "Female", 88, 55000.0, 456789012345, 6543210987, elements4, 5),
        BubbleSort("Eve", "Female", 90, 62000.0, 567890123456, 5432109876, elements5, 5)
    };

    for (int i = 0; i < 5; i++) {
        cout << "\nMember " << (i + 1) << " details:\n";
        members[i].displayDetails();
        members[i].sort();
        cout << "Sorted array (Bubble Sort): ";
        members[i].display();
    }

    return 0;
}
/*
[?2004l

Member 1 details:
Name: Alice
Gender: Female
HSC Mark: 95
Parent's Income: 50000
Aadhar Number: 123456789012
Account Number: 9876543210
Sorted array (Bubble Sort): 2 3 5 6 8 

Member 2 details:
Name: Bob
Gender: Male
HSC Mark: 85
Parent's Income: 60000
Aadhar Number: 234567890123
Account Number: 8765432109
Sorted array (Bubble Sort): 1 4 5 7 9 

Member 3 details:
Name: Charlie
Gender: Male
HSC Mark: 92
Parent's Income: 45000
Aadhar Number: 345678901234
Account Number: 7654321098
Sorted array (Bubble Sort): 2 4 6 7 8 

Member 4 details:
Name: Diana
Gender: Female
HSC Mark: 88
Parent's Income: 55000
Aadhar Number: 456789012345
Account Number: 6543210987
Sorted array (Bubble Sort): 1 2 3 5 6 

Member 5 details:
Name: Eve
Gender: Female
HSC Mark: 90
Parent's Income: 62000
Aadhar Number: 567890123456
Account Number: 5432109876
Sorted array (Bubble Sort): 1 2 3 6 8 
*/