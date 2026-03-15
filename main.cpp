//Write an OOP in C++ for linked list based implementation of Stack
//Name :  KALAIVANI S M
//Class : II-ECE-A
//Roll.No : 23BEC010
//Problem Statement : Paperless Scholarship for students
#include<iostream>
using namespace std;
class scholarship{
    private:
        struct node{
           string name; 
		    string gender; 
		    int hsc_mark; 
		    float parent_income; 
		    long int aadhar_no; 
		    long int account_no;
            struct node *next;
        }*top,*p,*temp;
    public:
        scholarship(){
            top=NULL;
            p=NULL;
            temp=NULL;
        }
        void PUSH(string n, char g, int h, float pc, long int adh, long int acc);
        void display();
        int POP();
};
int main(){
    scholarship a;
   a.PUSH("rani",'f',566,720000,908667576,6745459);
   a.PUSH("madhu",'f',543,767658,876764435,9877685);
   a.PUSH("teddy",'f',543,767658,876764435,9877685);
   a.PUSH("kavya",'f',543,767658,876764435,9877685);
   a.PUSH("teddy",'f',543,767658,876764435,9877685);
    a.display();
    cout<<"\nPopped data:"<<a.POP();
    cout<<"\nPopped data:"<<a.POP();
    cout<<"\nPopped data:"<<a.POP();
    a.display();
}
void scholarship::PUSH(string n, char g, int h, float pc, long int adh, long int acc){
    //temp=(struct node*)malloc(sizeof(struct node));
    temp=new struct node;
    temp->name = n;
    temp->gender = g;
    temp->hsc_mark = h;
    temp->parent_income = pc;
    temp->aadhar_no = adh;
    temp->account_no = acc;
    if(top==NULL){
    	
        temp->next=NULL;
        top=temp;
        return;
    }
    temp->next=top;
    top=temp;
}
void scholarship::display(){
    if(top==NULL){
        cout<<"\nSorry Stack is empty; can't print";
        return;
    }
    p=top;
    cout<<"\nThe stack contents are:\n";
    while(p!=NULL){
      cout<<"NAME :"<< p->name<<'\t'<<"-->GENDER: "<<p->gender<<"\t-->HSC Mark:"<<p->hsc_mark<<"\t-->Parent Income: "<<p->parent_income<<
	  "<-->Account Number:"<<p->account_no<<"<-->Aadhar Number:"<<p->aadhar_no<<endl;
      p=p->next;
    }
}
int scholarship::POP(){
    if(top==NULL){
        cout<<"\nSorry Stack is empty; can't print";
        return -1;
    }
    p=top;
    int x=p->hsc_mark;
    top=top->next;
    delete p;
    return x; }
    
    /*The stack contents are:
NAME :teddy     -->GENDER: f    -->HSC Mark:543 -->Parent Income: 767658<-->Account Number:9877685<-->Aadhar Number:876764435
NAME :kavya     -->GENDER: f    -->HSC Mark:543 -->Parent Income: 767658<-->Account Number:9877685<-->Aadhar Number:876764435
NAME :teddy     -->GENDER: f    -->HSC Mark:543 -->Parent Income: 767658<-->Account Number:9877685<-->Aadhar Number:876764435
NAME :madhu     -->GENDER: f    -->HSC Mark:543 -->Parent Income: 767658<-->Account Number:9877685<-->Aadhar Number:876764435
NAME :rani      -->GENDER: f    -->HSC Mark:566 -->Parent Income: 720000<-->Account Number:6745459<-->Aadhar Number:908667576

Popped data:543
Popped data:543
Popped data:543
The stack contents are:
NAME :madhu     -->GENDER: f    -->HSC Mark:543 -->Parent Income: 767658<-->Account Number:9877685<-->Aadhar Number:876764435
NAME :rani      -->GENDER: f    -->HSC Mark:566 -->Parent Income: 720000<-->Account Number:6745459<-->Aadhar Number:908667576
https://github.com/emweb/wt/releases
*/
