//Array Linked list based implementation of list ADT
//Name:KALAIVAN S.M
//RollNo:23bec010
//Class:II-ECE
//Section:A
//Problem Statement: Paperfree  scholarship
#include<iostream>
#define MAX 10
using namespace std;
class scholarship {
private:
struct paperfree{
string name;
string g;
int h;
        float pc;
        long int adh;
        long int acc;
} s[MAX];
int top;
public:
scholarship() : top(-1) {}
void insert(string ,char , int , float , long int ,long int );
void display();
void del(string name);
void modify(string oldname, string newname);
void search(string name);
};
void scholarship::insert(string name,char g, int h, float pc, long int adh,long int acc) {
if (top == MAX - 1) {
cout << "\nSorry, the list is full";
return;
}
++top;
s[top].name=name;
//s[top] = {name,g,h,pc,adh,acc};
}
void scholarship::display() {
if (top == -1) {
cout << "\nSorry, the list is empty";
return;
}
cout << "\nName of student\tgender\thsc_mark\tparents income\t\taadhar no\taccount no\n";
for (int i = 0; i <= top; i++) {
cout<<s[i].name<<"\t\t"<<s[i].g<<"\t\t"<<s[i].h<<"\t\t"<<s[i].pc<<"\t\t"<< s[i].adh<<s[i].acc<<endl;
}
}
void scholarship::del(string name) {
if (top == -1) {
cout << "\nSorry, the list is empty";
return;
}
int i;
for (i = 0; i <= top; i++) {
if (s[i].name == name) {
break;
}
}
if (i > top) {
cout << "\nArea not found";
return;
}
for (; i < top; i++) {
s[i] = s[i + 1];
}
--top;
}
void scholarship::modify(string oldname, string newname) {
if (top == -1) {
cout << "\nSorry, the list is empty";
return;
}
for (int i = 0; i <= top; i++) {
if (s[i].name == oldname) {
s[i].name = newname;
}
}
}
void scholarship::search(string name) {
if (top == -1) {
cout << "\nSorry, the list is empty";
return;
}
for (int i = 0; i <= top; i++) {
if (s[i].name == name) {
cout<<"/*NAME :"<< s[i].name<<"-->gender: "<<s[i].g<<endl
		 <<"-->hsc mark:"<<s[i].h<<"-->parentincomeL: "<<s[i].pc<<"-->account number:"<<s[i].acc<<endl
		 <<"-->aadharnumber:"<<s[i].adh<<endl<<endl<<"*/";

return;
}
}
cout << "\nname not found";
}
int main() {
scholarship w;
w.insert("Meera",'F',490,40000,603220304050,005235672642);
w.insert("Priya",'F',485,50000,603220306542,105233172642);
w.insert("Nisha",'F',480,60000,603220306871,100646573208);
w.insert("Keerthy",'F',475,70000,603220302006,640687463077);
w.insert("Madhu",'F',491,30000,603220309076,3049846505987);
w.display();
cout << "\nInserting the info:";
w.display();
cout << "\nModifying the info:";
w.modify("Nisha", "pavi");
w.display();
cout << "\nSearching the info:";
w.search("Madhu");
cout << "\nDeleting the info:";
w.del("pavi");
w.display();
return 0;
}
