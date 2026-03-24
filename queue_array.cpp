//Write an OOP in C++ for array based implementation of Queue
//Name :  KALAIVANI S M
//Class : II-ECE-A
//Roll.No : 23BEC010
//Problem Statement : Paperless Scholarship for students
#include<iostream>
#define max 10
using namespace std;
class Scholarship{
    private:
        struct node{
           string name; 
		    string gender; 
		    int hsc_mark; 
		    float parent_income; 
		    long int aadhar_no; 
		    long int account_no;
        
        }s[max];
        int front;
        int rear;
    public:
        Scholarship(){
            front=-1;
            rear=-1;
        }
        void ENQUEUE(string n, char g, int h, float pc, long int adh, long int acc);
        void display();
        int DEQUEUE();
};
int main(){
    Scholarship a;
    a.ENQUEUE("rani",'f',566,720000,908667576,6745459);
   a.ENQUEUE("madhu",'f',543,767658,876764435,9877685);
   a.ENQUEUE("teddy",'f',543,767658,876764435,9877685);
   a.ENQUEUE("kavya",'f',543,767658,876764435,9877685);
   a.ENQUEUE("teddy",'f',543,767658,876764435,9877685);
    a.display();
    cout<<"\nDequeued data:"<<a.DEQUEUE();
    cout<<"\nDequeued data:"<<a.DEQUEUE();
   
    a.display();
}
void Scholarship::ENQUEUE(string n, char g, int h, float pc, long int adh, long int acc){
    if(rear==max-1){
        cout<<"\nSorry queue overflow; can't insert";
        return;
    }
    if(front==-1)
        ++front;
    ++rear;
    s[rear].name=n;
    s[rear].gender=g;
    s[rear].hsc_mark=h;
    s[rear].parent_income=pc;
    s[rear].aadhar_no=adh;
    s[rear].account_no=acc;
    
}
void Scholarship::display(){
    if(front==-1){
        cout<<"\nSorry queue Underflow; can't print";
        return;
    }
    cout<<"\nThe queue contents are:\n";
    for(int i=front;i<=rear;i++)
    cout<<"NAME :"<< s[i].name<<"\t"<<"-->GENDER: "<<s[i].gender<<"\t-->HSC Mark:"<<s[i].hsc_mark<<"\t\t-->Parent Income: "<<s[i].parent_income<<"\t-->Account Number:"<<s[i].account_no<<"\t-->Aadhar Number:"<<s[i].aadhar_no<<endl;
}
int Scholarship::DEQUEUE(){
    if(front==-1){
        cout<<"\nSorry queue Underflow; can't print";
        return -1;
    }
    int x=s[front].hsc_mark;
    ++front;
    if(front==rear+1)
        front=rear=-1;
    return x;
}
/*The queue contents are:
NAME :rani      -->GENDER: f    -->HSC Mark:566         -->Parent Income: 720000        -->Account Number:6745459       -->Aadhar Number:908667576
NAME :madhu     -->GENDER: f    -->HSC Mark:543         -->Parent Income: 767658        -->Account Number:9877685       -->Aadhar Number:876764435
NAME :teddy     -->GENDER: f    -->HSC Mark:543         -->Parent Income: 767658        -->Account Number:9877685       -->Aadhar Number:876764435
NAME :kavya     -->GENDER: f    -->HSC Mark:543         -->Parent Income: 767658        -->Account Number:9877685       -->Aadhar Number:876764435
NAME :teddy     -->GENDER: f    -->HSC Mark:543         -->Parent Income: 767658        -->Account Number:9877685       -->Aadhar Number:876764435

Dequeued data:566
Dequeued data:543
The queue contents are:
NAME :teddy     -->GENDER: f    -->HSC Mark:543         -->Parent Income: 767658        -->Account Number:9877685       -->Aadhar Number:876764435
NAME :kavya     -->GENDER: f    -->HSC Mark:543         -->Parent Income: 767658        -->Account Number:9877685       -->Aadhar Number:876764435
NAME :teddy     -->GENDER: f    -->HSC Mark:543         -->Parent Income: 767658        -->Account Number:9877685       -->Aadhar Number:876764435
*/