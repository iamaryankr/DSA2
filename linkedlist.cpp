#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};
class LinkedList{
    private:
        Node *first;
    public:
        LinkedList(){
            first=NULL;
        }
        LinkedList(int A[],int n);
        ~LinkedList();

        void Display();
        void Insert(int index, int x);
        int countNodes();
        int sumdata();
        int Maxdata();
        Node LSearch(int key);
        int Delete(int index);
        int length();
        bool isSorted();
        void RemoveDuplicate();
        void Reverse1();


};

LinkedList:: LinkedList(int A[],int n){
    Node *last,*t;
    first= new Node;
    first->data=A[0];
    first->next=NULL;
    last = first;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data = A[i];
        t->next = NULL;
        last = t;
    }
}
LinkedList:: ~LinkedList(){
    Node *p=first;
    while(first){
        first= first->next;
        delete p;
        p= first;
    }
}

void LinkedList:: Display(){
    Node *p=first;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int LinkedList::countNodes(){
    int c=0;
    Node *p=first;
    while(p){
        c++;
        p=p->next;
    }
    return c;
}

int LinkedList:: sumdata(){
    int sum=0;
    Node *p=first;
    while(p){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int LinkedList:: Maxdata(){
    int max= INT32_MIN;
    Node *p=first;
    while(p){
        if(p->data > max)  max=p->data;
        p=p->next;
    }
    return max;
}

Node LinkedList:: LSearch(int key){
    Node *p=first;
    while(p){
        if(p->data == key) return *p;
        else p=p->next;
    }
    return ;
}

int LinkedList:: length(){
    Node *p=first;
    int len;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}


void LinkedList:: Insert(int index,int x){
    Node *t, *p=first;
    if(index<0 && index > length())  return ;
    t=new Node;
    t->data = x;
    t->next = NULL;

    if(index == 0){
        t->next= first;
        first=t;
    }
    else{
        for(int i=0;i<index-1;i++)  
               p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

int LinkedList:: Delete(int index){
    Node *p=NULL,*q=NULL;
    int x=-1;
    if(index<1 || index > length()) return -1;
    if(index==1){
        p=first;
        first=first->next;
        x=p->data;
        delete p;
    }
    else{
        p=first;
        for(int i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x;
}

bool LinkedList:: isSorted(){
    int x= INT32_MIN;
    Node *p=first;
    while(p){
        if(p->data < x)  return false;
        x=p->data;
        p=p->next;
    }
    return true;
}

void LinkedList:: RemoveDuplicate(){
    Node *p=first;
    Node *q=first->next;
    while(q){
        if(p->data != q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next = q->next;
            delete q;
            q=p->next;
        }
    }
    
}

void LinkedList:: Reverse1(){
    int *A, i=0;
    Node *p=first;
    Node *q=p;
    A=new int[countNodes()];
    A=(int *)malloc(sizeof(int)*countNodes(p));
    while(q){
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q){
        q->data=A[i];
        q=q->next;
        i--;
    }
}
