//Write an OOP in C++ for linked list based implementation of Queue
#include<iostream>
#include<string.h>
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
        }*front,*rear,*p,*temp;
    public:
        scholarship(){
            front=NULL;
            rear=NULL;
            p=NULL;
            temp=NULL;
        }
        void ENQUEUE(string n, char g, int h, float pc, long int adh, long int acc);
        void display();
        int DEQUEUE();
        int isempty();
};
int main(){
    scholarship a;
    
   a.ENQUEUE("rani",'f',566,720000,908667576,6745459);
   a.ENQUEUE("madhu",'f',543,767658,876764435,9877685);
   a.ENQUEUE("teddy",'f',543,767658,876764435,9877685);
   a.ENQUEUE("kavya",'f',543,767658,876764435,9877685);
   a.ENQUEUE("teddy",'f',543,767658,876764435,9877685);
    a.display();
    cout<<"\nDequeued data:"<<a.DEQUEUE();
    cout<<"\nDequeued data:"<<a.DEQUEUE();
    cout<<"\nDequeued data:"<<a.DEQUEUE();
    a.display();
    
}
void scholarship::ENQUEUE(string n, char g, int h, float pc, long int adh, long int acc){
    temp=new struct node;
    temp->name = n;
    temp->gender = g;
    temp->hsc_mark = h;
    temp->parent_income = pc;
    temp->aadhar_no = adh;
    temp->account_no = acc;
    temp->next=NULL;
    if(front==NULL){
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}
void scholarship::display(){
    if(front==NULL){
        cout<<"\nSorry Queue is empty; can't print";
        return;
    }
    p=front;
    cout<<"\nThe queue contents are:\n";
    while(p!=NULL){
     cout<<"NAME :"<< p->name<<'\t'<<"-->GENDER: "<<p->gender<<"\t-->HSC Mark:"<<p->hsc_mark<<"\t-->Parent Income: "<<p->parent_income<<
	  "\t-->Account Number:"<<p->account_no<<"\t-->Aadhar Number:"<<p->aadhar_no<<endl;
      p=p->next;
    }
}
int scholarship::DEQUEUE(){
    if(front==NULL){
        cout<<"\nSorry Queue is empty; can't print";
        return -1;
    }
    int x=front->hsc_mark;
    front=front->next;
    return x;
}
/*
The queue contents are:
NAME :rani      -->GENDER: f    -->HSC Mark:566         -->Parent Income: 720000        -->Account Number:6745459       -->Aadhar Number:908667576
NAME :madhu     -->GENDER: f    -->HSC Mark:543         -->Parent Income: 767658        -->Account Number:9877685       -->Aadhar Number:876764435
NAME :teddy     -->GENDER: f    -->HSC Mark:543         -->Parent Income: 767658        -->Account Number:9877685       -->Aadhar Number:876764435
NAME :kavya     -->GENDER: f    -->HSC Mark:543         -->Parent Income: 767658        -->Account Number:9877685       -->Aadhar Number:876764435
NAME :teddy     -->GENDER: f    -->HSC Mark:543         -->Parent Income: 767658        -->Account Number:9877685       -->Aadhar Number:876764435

Dequeued data:566
Dequeued data:543
Dequeued data:543
The queue contents are:
NAME :kavya     -->GENDER: f    -->HSC Mark:543         -->Parent Income: 767658        -->Account Number:9877685       -->Aadhar Number:876764435
NAME :teddy     -->GENDER: f    -->HSC Mark:543         -->Parent Income: 767658        -->Account Number:9877685       -->Aadhar Number:876764435
*/