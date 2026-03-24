//Write an OOP in C++ for array based implementation of Stack
//Name:S.M.KALAIVANI
//RollNo:23bec010
//Class:II-ECE
//Section:A
//Problem Statement: Paperless Scholarship in India 
#include<iostream>
#include<string.h>
#define max 10
using namespace std;
class scholarship{
    private:
        struct paperfree{
          string name;
	      char gender;
	      int hsc_mark;
	      float parent_income;
	      long int aadhar_no;
	      long int account_no;
		  
		  
        	
        }s[max];
        int top;
    public:
        scholarship(){
            top=-1;
        }
        void PUSH(string,char,int,float,long int,long int);
        void display();
        struct paperfree* POP();
};
int main(){
    scholarship a;
    a.PUSH("Meera",'F',490,40000,603220304050,005235672642);
    a.PUSH("Priya",'F',485,50000,603220306542,105233172642);
    a.PUSH("Nisha",'F',480,60000,603220306871,100646573208);
    a.PUSH("Keerthy",'F',475,70000,603220302006,640687463077);
    a.PUSH("Madhu",'F',491,30000,603220309076,3049846505987);
    
    a.display();
    //cout<<"\nPopped data:"<<a.POP();
    //cout<<"\nPopped data:"<<a.POP();
    //cout<<"\nPopped data:"<<a.POP();
    //a.display();
}
void scholarship::PUSH(string n,char g, int h, float pc, long int adh,long int acc){
    if(top==max-1){
        cout<<"\nSorry stack overflow; can't insert";
        return;
    }
    ++top;
    
    for(int i=top;i>0;i--){
	s[i].name=n;
    s[i].gender=g;
    //s[i].aadhar_no=adh;
    s[i].hsc_mark=h;
    s[i].parent_income=pc;
    s[i].aadhar_no=adh;
    s[i].account_no=acc;
}}
void scholarship::display(){
    if(top==-1){
        cout<<"\nSorry Stack Underflow; can't print";
        return;
    }
    cout<<"\nThe stack contents are:\n";
    for(int i=top;i>=0;i--)
        cout<<s[i].name<<"--"<<endl<<s[i].gender<<"--"<<s[i].hsc_mark<<"--"<<s[i].parent_income<<"--"<<s[i].aadhar_no<<"--"<<s[i].aadhar_no<<endl;
	//cout<<s[i].gender<<"--"<<endl;
	
    //cout<<s[i].parent_account<<endl;
    //cout<<s[i].aadhar_no<<endl;
    //cout<<s[i].account_no<<endl;
}/*
struct paperfree* scholarship::POP(){
    int x;
    if(top==-1){
        cout<<"\nSorry Stack Underflow; can't print";
        return -1;
    }
    x=s[top].name;
    --top;
    return x;
}*/