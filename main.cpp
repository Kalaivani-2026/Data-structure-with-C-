#include<iostream>
#include<cmath>
   using namespace std;
   class Quadratic
   {
     private:
        float a,b,c;
     public:
        void GettingCoeff()
        {
           cout<<"ENTER A:";
           cin>>a;
           cout<<"ENTER B:";
           cin>>b;
           cout<<"ENTER C:";
           cin>>c;
        }
        void Roots()
        {
           float r1,r2,d,rp,ip;
           d=b*b-4*a*c;
           if(d>0)
           {
              r1=(-b+sqrt(d))/(2*a);
              r2=(-b-sqrt(d))/(2*a);
              cout<<"ROOTS ARE REAL AND DISTINCT"<<endl;
              cout<<"Root 1="<<r1<<endl;
              cout<<"Root 2="<<r2<<endl;
           }
           else if(d==0)
           {
              cout<<"ROOTS ARE REAL AND EQUAL"<<endl;
              r1=-b/(2*a);
              cout<<"Root 1=Root 2="<<r1<<endl;
           }
           else{
              rp=-b/(2*a);
              ip=sqrt(-d)/(2*a);
              cout<<"Root 1="<<rp<<"+"<<ip<<"i"<<endl;
               cout<<"Root 2="<<rp<<"-"<<ip<<"i"<<endl;
           }
        }
  };
  int main()
  {
     Quadratic q;
     q.GettingCoeff();
     q.Roots();
     return 0;
  }