//AVL Tree
/*
---------------------------------------------------------------------------------------------------------------------------------
EX:05
DATE:16.10.2024
BINARY SEARCH TREE IMPLEMENTATION
---------------------------------------------------------------------------------------------------------------------------------
*/
//Name:KALAIVANI S M
//RollNo:23bec010
//Class:II-ECE
//Section:A
//Problem Statement:paperfree scholarship
#include<iostream>
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
        struct paperfree *left;
        struct paperfree *right;
        int height;
       }*root,*temp;
           struct paperfree* createpaperfree(string, char, int, float, long int, long int);
        struct paperfree* insert(struct paperfree *, string, char, int, float, long int, long int);
        void preorder(struct paperfree *);
        void postorder(struct paperfree *);
        void inorder(struct paperfree *);
        struct paperfree* maximum(struct paperfree *);
        struct paperfree* minimum(struct paperfree *);
        struct paperfree* Delete(struct paperfree*,string, char, int, float, long int, long int);
        struct paperfree* SRR(struct paperfree *);
        struct paperfree* SRL(struct paperfree *);
        int height (struct paperfree *);
        int max(int,int);
    public:
        scholarship(){
           root=NULL; temp=NULL;
        }
        void insert(string, char, int, float, long int, long int);
        void preorder();
        void postorder();
        void inorder();
        int maximum();
        int minimum();
        void Delete(string);
};

int main(){
    scholarship b;
     b.insert("Meera", 'F', 490, 40000, 603220304050, 5235672642);
    b.insert("Priya", 'F', 485, 50000, 603220306542, 105233172642);
    b.insert("Nisha", 'F', 480, 60000, 603220306871, 100646573208);
    b.insert("Keerthy", 'F', 475, 70000, 603220302006, 640687463077);
    b.insert("Madhu", 'F', 491, 30000, 603220309076, 3049846505987);

    cout<<"\nThe Preorder sequence:";
    b.preorder();
    cout<<"\nThe Postorder sequence:";
    b.postorder();
    cout<<"\nThe Inorder sequence:";
    b.inorder();
    cout<<"\nThe maximum element in the scholarship:"<<b.maximum();
    cout<<"\nThe minimum element in the scholarship:"<<b.minimum();
    b.Delete(madhu);
    cout<<"\nThe Inorder sequence:";
    b.inorder();
    b.Delete(keerthy);
    cout<<"\nThe Inorder sequence:";
    b.inorder();
    return 0;
 }
 
void scholarship::insert( string n, char g, int h, float pc, long int adh, long int acc){
    root=insert(root,n);
    root=insert(root,g);
    root=insert(root,h);
    root=insert(root,pc);
    root=insert(root,adh);
    root=insert(root,acc);
}
void scholarship::preorder(){
    preorder(root);
}
void scholarship::postorder(){
    postorder(root);
}
void scholarship::inorder(){
    inorder(root);
}
int scholarship::maximum(){
    return(maximum(root)->data);
}
int scholarship::minimum(){
    return(minimum(root)->data);
}
void scholarship::Delete(string n){
    root=Delete(root,n);
}

scholarship::paperfree* scholarship::createpaperfree(string n, char g, int h, float pc, long int adh, long int acc){
    temp= new struct paperfree;
     temp->name = n;
    temp->gender = g;
    temp->hsc_mark = h;
    temp->parent_income = pc;
    temp->aadhar_no = adh;
    temp->account_no = acc;
    temp->left=NULL;
    temp->right=NULL;
    temp->right=0;
    return temp;
}

scholarship::paperfree* scholarship::insert(struct paperfree *T, string n, char g, int h, float pc, long int adh, long int acc){
  int balance;
  if(T==NULL)
       T=createpaperfree(n,g,h,pc,adh,acc);
   else if(>T->h)
       T->right=insert(T->right,h);
   else if(d<T->data)
       T->left=insert(T->left,d);
    //Find & update height of the paperfree
    T->height=1+max (height(T->left),height(T->right));
    //Find balance factor  of the paperfree
    balance = height(T->left)-height(T->right);
     if(balance > 1 && d < T->left->data)
       return SRR(T); //perform SRR
    else if (balance < -1 && d >T->right->data)
       return SRL(T); //perform SRL
    else if(balance > 1 && d > T->left->data){
       T->left = SRL(T->left); //perform SRL  
       return SRR(T); //perform SRR
    }    
    else if(balance < -1 && d < T->right->data){
       T->right = SRR(T->right);//perform SRR
       return SRL(T);//perform SRL
    }
    return T;
}
 
int scholarship::height (struct paperfree *T){
        if (T==NULL)
                 return 0;
        return (T->height);
}
int scholarship::max(int a, int b){
        return (a>b)?a:b;
}
scholarship::paperfree* scholarship::SRR(struct paperfree *y){
    struct paperfree * x = y ->left;
    struct paperfree *T2 = x->right;
    x->right=y;
    y->left=T2;
    x->height = 1+max(height(x->right),height(x->left));
    y->height = 1+max(height(y->right),height(y->left));
    return x;
}
scholarship::paperfree* scholarship::SRL(struct paperfree *x){
    struct paperfree * y = x -> right;
    struct paperfree *T2 = y->left;
    y->left=x;
    x->right=T2;
    x->height = 1+max(height(x->right),height(x->left));
    y->height = 1+max(height(y->right),height(y->left));
    return y;
}
void scholarship::preorder(struct paperfree *T){
  if(T!=NULL){
    cout<<T->data<<" ";     //M
    preorder(T->left);        //L
    preorder(T->right);         //R
 }
}
void scholarship::postorder(struct paperfree *T){
  if(T!=NULL){
    postorder(T->left);        //L
    postorder(T->right);         //R
    cout<<T->data<<" ";     //M
 }
}
void scholarship::inorder(struct paperfree *T){
  if(T!=NULL){
    inorder(T->left);        //L
    cout<<T->data<<" ";     //M
    inorder(T->right);         //R
 }
}
scholarship::paperfree* scholarship::minimum(struct paperfree* T){
    while(T->left!=NULL)
        T=T->left;
    return T;
}
scholarship::paperfree* scholarship::maximum(struct paperfree* T){
    while(T->right!=NULL)
        T=T->right;
    return T;
}
scholarship::paperfree* scholarship::Delete(struct paperfree* T,string n) {
    if (T == NULL) {
        return T;  
    }
    if (d < T->data) 
        T->left = Delete(T->left, d);
     else if (d > T->data) 
        T->right = Delete(T->right, d);
     else {
        // Case 1: paperfree with only one child or no child
        if (T->left == NULL || T->right == NULL) {
            paperfree* temp = T->left ? T->left : T->right;
            // Case 1.1: No child (leaf paperfree)
            if (temp == NULL) {
                temp = T;
                T = NULL;
            } else  // Case 1.2: One child
                *T = *temp;  
            delete temp;
        } else {
            // Case 2: paperfree with two children, get the inorder successor
            paperfree* temp = minimum(T->right);
            T->data = temp->data;
            T->right = Delete(T->right, temp->data);
        }
    }
    // If the tree had only one paperfree, then return
    if (T == NULL)
        return T;
    T->height = 1 + max(height(T->left), height(T->right));
    int balance = height(T->left) - height(T->right);
    // If this paperfree becomes unbalanced, then there are 4 cases
    // Left Left Case
    if (balance > 1 && height(T->left->left) >= height(T->left->right))
        return SRR(T);
    // Left Right Case
    if (balance > 1 && height(T->left->left) < height(T->left->right)) {
        T->left = SRL(T->left);
        return SRR(T);
    }
    // Right Right Case
    if (balance < -1 && height(T->right->right) >= height(T->right->left))
        return SRL(T);
    // Right Left Case
    if (balance < -1 && height(T->right->right) < height(T->right->left)) {
        T->right = SRR(T->right);
        return SRL(T);
    }
    return T;
}