//Double Linked list based implementation of list ADT
//Name:S.M.KALAIVANI
//RollNo:23bec010
//Class:II-ECE
//Section:A
//Problem Statement: Paperless Scholarship in India 
#include<iostream>
#include<string>
using namespace std;
class PaperlessScholarship{
	private:
	    struct data{
	      string name;
	      string gender;
	      int hsc_mark;
	      float parent_income;
	      long int aadhar_no;
	      long int account_no;
		  struct data *nxt,*prev;
		  }*head,*p,*temp,*tail;
	public:
		PaperlessScholarship()
		{
			head=NULL;
			p=NULL;
			temp=NULL;
			tail=NULL;
		}
		void insert(string,string,int,float,long int,long int);
		void display();
	};
int main(){
	PaperlessScholarship ps;
	ps.insert("Meera","F",490,40000,603220304050,005235672642);
	ps.insert("Priya","F",485,50000,603220306542,105233172642);
	ps.insert("Nisha","F",480,60000,603220306871,100646573208);
	ps.insert("Keerthy","F",475,70000,603220302006,640687463077);
	ps.insert("Madhu","F",491,30000,603220309076,3049846505987);
	ps.display();
	return 0;
}	
void PaperlessScholarship::insert(string name,string gender,int hsc_mark,float parent_income,long int aadhar_no,long int account_no)
{
	temp= new struct data;
	temp->name=name;
	temp->gender=gender;
	temp->hsc_mark=hsc_mark;
	temp->parent_income=parent_income;
	temp->aadhar_no=aadhar_no;
	temp->account_no=account_no;
	temp->nxt=NULL;
	temp->prev=NULL;
	if(head==NULL){
		head=temp;
		return;
	}
	p=head;
	while(p->nxt!=NULL)
	   p=p->nxt;
	p->nxt=temp;
	temp->prev=p;
	tail=temp;
	}
	
void PaperlessScholarship::display(){
	if(head==NULL)
    {  
         cout<<"Sorry.The list is empty.";
		return;
	}
	p=head;  
	cout<<"NAME"<<"\t"<<"GENDER"<<"\t"<<"HSC MARK\t"<<"PARENT INCOME"<<"\t"<<"AADHAR NO."<<"\t"<<"ACCOUNT NO."<<"\n";
	while(p!=NULL){
	    cout<<p->name<<"\t"<<p->gender<<"\t"<<p->hsc_mark<<"\t\t"<<p->parent_income<<"\t\t"<<p->aadhar_no<<"\t"<<p->account_no<<"\t"<<"\n";
	    p=p->nxt;
	    
	}
}	