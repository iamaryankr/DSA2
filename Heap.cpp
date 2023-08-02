#include<iostream>
#include<vector>
using namespace std;

void InsertA(int A[],int n){
    int i=n;
    int temp = A[n];
    while( i>0 && temp > A[i%2 == 0 ? (i/2)-1 : i/2]){
        A[i] = A[i%2 == 0 ? (i/2)-1 : i/2];
        i = i%2 == 0 ? (i/2)-1 : i/2;
    }
}



int main(){

}