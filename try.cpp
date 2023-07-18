#include<iostream>
using namespace std;
int swap(int A, int B){
    int temp=0;
    temp=B;
    B=A;
    A=temp;
    cout<<A<<" "<<B;
}
int main(){
    int length=7; int size=10;
    int A[size]={5,6,7,8,2,1,4};
    for(int i=0;i<length;i++){ cout<<A[i]<<" "; }

    int index;
    cout<<"enter the index to delete: ";
    cin>>index;
    for(int i=index; i<length-1;i++){ A[i]=A[i+1]; }
    length--;
    for(int i=0;i<length;i++){ cout<<A[i]<<" "; }
    cout<<endl;

    swap(6,5);
    int key;
    cout<<"enter the key to be found "<<endl;
    cin>>key;
    for(int i=0;i<length; i++){
        if(key==A[i]){
            swap (A[i],A[i-1]);
        }
        cout<< i-1;
    }



return 0;
}