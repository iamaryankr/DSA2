#include<iostream>
using namespace std;

class Term{
    public:
        int coeff, exp;
};
class Polynomial{
    public:
        int n; 
        Term *terms;
        void Create(Polynomial *p);
        void Display(Polynomial *p);
        Polynomial *add(Polynomial *p2);
};
void Polynomial:: Create(Polynomial *p){
    int i;
    cout<<"number of terms"<<endl;
    cin>> p->n;
    p->terms = new Term[p->n];
    cout<<"enter terms"<<endl;
    for(int i=0;i<p->n;i++){
        cin>>p->terms[i].coeff>> p->terms[i].exp;
    }
}
void Polynomial:: Display(Polynomial *p){
    int i;
    for(i=0;i<p->n;i++){
        cin>>p->terms[i].coeff>> p->terms[i].exp;
    }
}




int main(){
}