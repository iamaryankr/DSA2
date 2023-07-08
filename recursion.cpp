#include<iostream>
using namespace std;
void func(int n){  
    if(n>0){
        func(n-1);
        cout<<n<<endl; //prints while returning (head recursion)
    }
}
int fun1(int n){
    if(n>0) return fun1(n-1)+n;
    return 0;
}
//use of static or global variables
int fun2(int n){
    static int x=0;  //code maintains a single copy of it
    if(n>0) {
        x++;
        return fun1(n-1)+x;
    }
    return 0;
}
void fun3(int n){
    if(n>0){
        cout<<n;
        fun3(n-1);
        fun3(n-1); //tree recursion
    }
}
//indirect recursion
void funB(int n);
void funA(int n){
    if(n>0){cout<<n; funB(n-1);}
}
void funB(int n){
    if(n>1){cout<<n; funA(n/2);}
}
//nested recursion
int fun4(int n){
    if(n>100) return n-10;
    else return fun4(fun4(n+11));
}
int sumn(int n){
    if(n==0) return 0;
    else return sumn(n-1)+n;
}
int pow(int m,int n){
    if(n==0) return 1;
    else return pow(m,n-1)*m;
}


int main(){
    //func(7);
    //cout<<fun1(7)<<endl<<fun2(7);
    //fun3(6);
    //funA(5);
    //cout<<fun4(95);
    //cout<<sumn(10);
    cout<<pow(3,0);

}