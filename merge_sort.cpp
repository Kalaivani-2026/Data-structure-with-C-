/*
---------------------------------------------------------------------------------------------------------------------------------
EX:10
DATE:13.11.2024
SORTING ALGORITHM-MERGE SORTING
---------------------------------------------------------------------------------------------------------------------------------
*/
//Name:JEFFY D
//RollNo:23bec009
//Class:II-ECE
//Section:A
//Problem Statement:paperfree scholarship
#include <iostream>
#include <string>
using namespace std;
#define MAX 10

class MergeSort {
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
    MergeSort(string nm, string gd, int hsc, float income, long int aadhar, long int acc, int elements[], int size) {
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
    void mergeSort(int l, int r);
    void merge(int l, int m, int r);
    void display();
    void displayDetails();
};

void MergeSort::display() {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void MergeSort::displayDetails() {
    cout << "Name: " << name << endl;
    cout << "Gender: " << gender << endl;
    cout << "HSC Mark: " << hsc_mark << endl;
    cout << "Parent's Income: " << parent_income << endl;
    cout << "Aadhar Number: " << aadhar_no << endl;
    cout << "Account Number: " << account_no << endl;
}

void MergeSort::sort() {
    mergeSort(0, n - 1);
}

void MergeSort::mergeSort(int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}

void MergeSort::merge(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

int main() {
    int elements1[] = {5, 3, 8, 6, 2};
    int elements2[] = {9, 7, 4, 1, 5};
    int elements3[] = {6, 8, 2, 4, 7};
    int elements4[] = {3, 2, 6, 5, 1};
    int elements5[] = {8, 6, 3, 2, 1};

    MergeSort members[] = {
        MergeSort("Alice", "Female", 95, 50000.0, 123456789012, 9876543210, elements1, 5),
        MergeSort("Bob", "Male", 85, 60000.0, 234567890123, 8765432109, elements2, 5),
        MergeSort("Charlie", "Male", 92, 45000.0, 345678901234, 7654321098, elements3, 5),
        MergeSort("Diana", "Female", 88, 55000.0, 456789012345, 6543210987, elements4, 5),
        MergeSort("Eve", "Female", 90, 62000.0, 567890123456, 5432109876, elements5, 5)
    };

    for (int i = 0; i < 5; i++) {
        cout << "\nMember " << (i + 1) << " details:\n";
        members[i].displayDetails();
        members[i].sort();
        cout << "Sorted array (Merge Sort): ";
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
Sorted array (Merge Sort): 2 3 5 6 8 

Member 2 details:
Name: Bob
Gender: Male
HSC Mark: 85
Parent's Income: 60000
Aadhar Number: 234567890123
Account Number: 8765432109
Sorted array (Merge Sort): 1 4 5 7 9 

Member 3 details:
Name: Charlie
Gender: Male
HSC Mark: 92
Parent's Income: 45000
Aadhar Number: 345678901234
Account Number: 7654321098
Sorted array (Merge Sort): 2 4 6 7 8 

Member 4 details:
Name: Diana
Gender: Female
HSC Mark: 88
Parent's Income: 55000
Aadhar Number: 456789012345
Account Number: 6543210987
Sorted array (Merge Sort): 1 2 3 5 6 

Member 5 details:
Name: Eve
Gender: Female
HSC Mark: 90
Parent's Income: 62000
Aadhar Number: 567890123456
Account Number: 5432109876
Sorted array (Merge Sort): 1 2 3 6 8 
*/