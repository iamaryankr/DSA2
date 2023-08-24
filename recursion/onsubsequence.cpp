#include<bits/stdc++.h>
using namespace std;

//printing all subsequences
void PrintF(int ind, vector<int> &ds, int arr[], int n){
    if(ind==n) {
        for(auto it: ds){
            cout<<it<<" ";
        }
        if(ds.size()==0) cout<<"{ }";

        cout<<endl;
        return ;
    }
    
    //take case
    ds.push_back(arr[ind]);
    PrintF(ind+1, ds, arr, n);
    ds.pop_back();
    //not take case
    PrintF(ind+1, ds, arr, n);
}
int main(){
    int arr[]= {3,1,2};
    int n = 3;
    vector<int> ds;
    PrintF(0, ds, arr, n);
    return 0;
}