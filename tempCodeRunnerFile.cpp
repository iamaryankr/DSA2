#include<iostream>
using namespace std;

template <class T>
void Print(T& vec, int n, string s){
    cout<<s << ": ["<<flush;
    for(int i=0; i<n ; i++){
        cout<< vec[i] << flush;
        if(i < n-1){
            cout<<", "<<flush;
        }
    }
    cout<<"]"<<endl;
}
void Swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//bubble sort
void Bubblesort(int A[],int n){
    int flag = 0;   //use of flag to make it adaptive
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(A[j] > A[j+1]){
                Swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) return ;
    }
}

//insertion sort
void Insertionsort(int A[], int n){
    for(int i=1; i<n; i++){
        int j= i-1;
        int x= A[i];
        while(j>-1 && A[j]>x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1]=x;
    }
}

//selection sort
void SelectionSort(int A[],int n){
    for(int i=0; i<n-1; i++){
        int j; int k ;
        for(j=k=1; j<n; j++){
            if(A[j] < A[k]) {
                k=j;
            }
        }
        Swap(&A[i], &A[k]);
    }
}

//Quick Sort
int PartitionReursion(int A[],int low, int high){
    int pivot = A[low];
    int i = low; int j = high;
    do{
        do{
            i++;
        }
        while(A[j] <= pivot);
        do{
            j--;
        }
        while(A[j] > pivot);

        if(i < j){ Swap(&A[i], &A[j]);  }
    }
    while(i < j);

    Swap(&A[low], &A[j]);
    return j;
}

void QuickSortRecursion(int A[], int low, int high){
    if(low < high){
        int j = PartitionReursion(A,low,high);
        QuickSortRecursion(A,low,j);
        QuickSortRecursion(A,j+1,high);
    }
}


int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low+1;
    int j = high;

    while(true){
        while(i <= j && A[i] <= pivot){
            i++;
        }
        while(i <= j && A[i] >= pivot){
            j--;
        }
        if(j < i) break;
        else Swap(&A[i], &A[j]);
    }
    Swap(&A[low], &A[j]);
    return j;
}

void QuickSort(int A[], int low, int high){
    if(low < high){
        int p = partition(A, low, high);
        QuickSort(A, low, p-1);
        QuickSort(A, p+1, high);
    }
}





int main() {
 
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n, "\t\tA");
 
    Bubblesort(A, n);
    Print(A, n, " Sorted A");


    int B[] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1};
    Print(B, sizeof(B)/sizeof(A[0]), "       B");
 
    Insertionsort(B, sizeof(B)/sizeof(B[0]));
    Print(B, sizeof(B)/sizeof(B[0]), "Sorted B");


    int C[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n1 = sizeof(C)/sizeof(C[0]);
    Print(C, n1, "\t\tC");
 
    SelectionSort(C, n1);
    Print(C, n1, " Sorted C");

    int A1[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, 32767};
    int n2 = sizeof(A1)/sizeof(A1[0]);
    Print(A1, n2-1, "\t\tA");
 
    QuickSortRecursion(A1, 0, n2-1);
    Print(A1, n2-1, " Sorted A1");
    cout << endl;
 
    return 0;
}