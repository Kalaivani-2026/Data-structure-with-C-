//Write an OOP in C++ for array based implementation of list
//Name:S.M.Kalaivani
//RollNo:23bec010
//Class:II-ECE
//Section:A
//Problem Statement:Paperless Scholarship
#include<iostream>
#define max 10
using namespace std;
class scholarship{

    private:
        struct node{
		string name; 
		char gender; 
		int hsc_mark; 
		float parent_income; 
		long int aadhar_no; 
		long int account_no;
		struct node *next;
        }s[max];
        int top;
    public:
        ArrayList(){
            top=-1;
        }
        void insert(string,char,int,float,long int,long int);
        void display();
        
};
int main(){
    scholarship a;
    a.insert("rani",'f',566,720000,908667576,6745459);
    a.insert("teddy",'F',543,767658,876764435,9877685);
    //a.insert(30);
    //a.insert(40);
    //a.insert(50);
    //a.insert(60);
    a.display();
    
}
void scholarship::insert(string n,char g, int h, float pc, long int adh,long int acc){
    if(top==max-1){
        cout<<"\nSorry List is full; can't insert";
        return;
    }
    ++top;
    s[top].name=n;
    s[top].gender=g;
    s[top].hsc_mark=h;
    s[top].parent_income=pc;
    s[top].aadhar_no=adh;
    s[top].account_no=acc;
	
}
void scholarship::display(){
    if(top==-1){
        cout<<"\nSorry List is empty; can't print";
        return;
    }
    
	for(int i=0;i<=top;i++)
		cout<<"/*NAME :"<< s[i].name<<"-->gender: "<<s[i].gender<<endl
		 <<"-->hsc mark:"<<s[i].hsc_mark<<"-->parentincomeL: "<<s[i].parent_income<<"-->account number:"<<s[i].account_no<<endl
		 <<"-->aadharnumber:"<<s[i].aadhar_no<<endl<<endl<<"*/";

		
	}
	