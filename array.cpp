#include<iostream>
using namespace std;
class Array{
    public:
         int A[10];
         int size;
         int length;
};
void Display( Array arr){
         int i;
         cout<<"elements are: ";
         for(i=0;i<arr.length;i++){
         cout<<arr.A[i]<<" ";
    }
}
void swap(int *x,int *y){
         int temp=*x;
         *x=*y;
         *y=temp;
}
int LinearSearch(struct Array *arr,int key){
         int i;
         for(i=0;i<arr->length;i++){
              if(key==arr->A[i]){
                  swap(&arr->A[i],&arr->A[0]);
                  return i;
                 }
         }
    return -1;
}

int LBinarySearch(Array arr,int key){
    int l=0;
    int h=arr.length-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(key==arr.A[mid]) return mid;
        else if(key>arr.A[mid]) l=mid+1;
        else h=mid-1;
    }
    return -1;
}

int RBinarySearch(int A[],int l, int h, int key){
     int mid=0;
     while(l<=h){
           mid=(l+h)/2;
           if(key==A[mid])  return mid;
           else if(key<A[mid]) return RBinarySearch(A,l,mid-1,key);
           else return RBinarySearch(A,mid+1,h,key);
     }
   return -1;
}
int Get(Array arr,int index){
    if(index>=0 && index<arr.length)
         return arr.A[index];
return -1;
}
void Set(Array arr, int x, int index){
    if(index>=0 && index<arr.length)
         arr.A[index]=x;   
}
int Max(Array arr){
    int max=arr.A[0];
    for (int i = 0; i<arr.length; i++){
        if(arr.A[i]>max) 
             max=arr.A[i];     
    }
    return max;
}
int Sum(Array arr){
    int sum=0;
    for(int i=0;i<arr.length;i++){
        sum+=arr.A[i];
    }
    return sum;
}
void Reverse(Array &arr){
    int *B=new int[arr.length];
    int i,j;
    for(i=arr.length-1,j=0;i>=0,j<arr.length;i--,j++){
        B[j]=arr.A[i];
    }
    for(i=0;i<arr.length;i++)
        arr.A[i]=B[i];

}
void Reverse2(Array &arr){
    int i,j;
    for(i=0,j=arr.length-1;i<j;i++,j--){
        swap(&arr.A[i],&arr.A[j]);
    }
}
void Leftshift(Array &arr){
    for(int i=0;i<arr.length-1;i++){
        arr.A[i]=arr.A[i+1];
    }
        arr.A[arr.length-1]=0;
}
void RotateArray(Array &arr){
    int t;
    t=arr.A[0];
    for(int i=0;i<arr.length-1;i++){
        arr.A[i]=arr.A[i+1];
    }
    arr.A[arr.length-1]=t;

}
bool isSorted(Array arr){
    for(int i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1])
            return true;
     }
    return false;
}


int main(){
        Array arr={{2,3,9,16,18,21,28,32,35},10,9};

        //cout<<RBinarySearch(arr.A,0,8,16);
        //Display(arr);  
        //Reverse2(arr);
        //Leftshift(arr);
        //RotateArray(arr);
        Display(arr);
        cout<<isSorted(arr);
 




        return 0;
}

