#include<iostream>
using namespace std;

//Diagonal matrix
class Diagonal{
    private:
         int n;int *A;
    public:
         Diagonal(int n){
            this->n=n;
            A=new int [n];
         }
         void Set(int i,int j,int x);
         int Get(int i,int j);
         void Display();
         ~Diagonal(){
            delete []A;
         }
};
void Diagonal::Set(int i,int j,int x){
    if(i==j) A[i-1]=x;
}
int Diagonal::Get(int i ,int j){
    if(i==j) return A[i-1];
    else return 0;
}
void Diagonal::Display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) cout << A[i-1];
            else cout<<"0";
        }
        cout<<endl;
    }
}

class LTMatrix{
    private:
        int n;
        int *A;
    public:
        LTMatrix(int n){
            this->n=n;
            A= new int [n*(n+1)/2];
        }
        void Display(bool row=true);
        void SetRowMajor(int i,int j,int x);
        void SetColumnMajor(int i,int j,int x);
        int GetRowMajor(int i,int j);
        int GetColumnMajor(int i,int j);
        ~LTMatrix(){
            delete []A;
        }

};
void LTMatrix:: SetRowMajor(int i,int j,int x){
    if(i>=j){
        int index = ((i*(i-1))/2)+ j-1;
        A[index]=x;
    }
}
int LTMatrix:: GetRowMajor(int i,int j){
    if(i>=j){
        int index = ((i*(i-1))/2)+ j-1;
        return A[index];
    }
    else{
        return 0;
    }
}

void LTMatrix:: SetColumnMajor(int i,int j,int x){
    if(i>=j){
        int index = n*(j-1)-(((j-2)*(j-1))/2-(i-j));
        A[index]=x;
    }
}
int LTMatrix:: GetColumnMajor(int i,int j){
    if(i>=j){
        int index = n*(j-1)-(((j-2)*(j-1))/2-(i-j));
        return A[index];
    }
    else{
        return 0;
    }
}
void LTMatrix:: Display(bool row){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i >= j){
                if (row){
                    cout << GetRowMajor(i, j) << " ";
                } else {
                    cout << GetColumnMajor(i, j) << " ";
                }
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
 }



int main(){
    Diagonal d(4);
    d.Set(1,1,3);
    d.Set(2,2,5);
    d.Set(3,3,4);
    d.Set(0,0,7);
    d.Display();

     LTMatrix rm(4);
    rm.SetRowMajor(1, 1, 1);
    rm.SetRowMajor(2, 1, 2);
    rm.SetRowMajor(2, 2, 3);
    rm.SetRowMajor(3, 1, 4);
    rm.SetRowMajor(3, 2, 5);
    rm.SetRowMajor(3, 3, 6);
    rm.SetRowMajor(4, 1, 7);
    rm.SetRowMajor(4, 2, 8);
    rm.SetRowMajor(4, 3, 9);
    rm.SetRowMajor(4, 4, 10);
 
    rm.Display();
    cout << endl;
 
    LTMatrix cm(4);
    cm.SetColumnMajor(1, 1, 1);
    cm.SetColumnMajor(2, 1, 2);
    cm.SetColumnMajor(2, 2, 3);
    cm.SetColumnMajor(3, 1, 4);
    cm.SetColumnMajor(3, 2, 5);
    cm.SetColumnMajor(3, 3, 6);
    cm.SetColumnMajor(4, 1, 7);
    cm.SetColumnMajor(4, 2, 8);
    cm.SetColumnMajor(4, 3, 9);
    cm.SetColumnMajor(4, 4, 10);
 
    cm.Display(false);
 

}