#include<iostream>
using namespace std;
class Merge{
    public:
        int n, p, q, mid, *arr;
        Merge(int size);
        void getdata();
        void merge(int *arr, int p, int q, int mid);
        void Mergesort(int *arr, int p, int q);
        void display();
};
Merge::Merge(int size) : n(size), p(0), q(n - 1), arr(new int[n]) {}

void Merge::getdata(){
    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
}

void Merge::merge(int *arr, int p, int q, int mid){
    int i, j, k;
    i=p, j=mid+1, k=0;
    int temp[q-p+1];
    while(i<=mid && j<=q){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            k++; i++;
        }
        else{
            temp[k]=arr[j];
            k++; j++;
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
        k++; i++;
    }
    while(j<=q){
        temp[k]=arr[j];
        k++; j++;
    }
    for(i=p; i<=q; i++)
        arr[i]=temp[i-p];
}
void Merge::Mergesort(int *arr, int p, int q){
    int mid;
    if(p<q){
        mid=(p+q)/2;
        Mergesort(arr, p, mid);
        Mergesort(arr, mid+1, q);
        merge(arr, p, q, mid);
    }
}
void Merge::display(){
    cout<<"Before sorting: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    Mergesort(arr, 0, n-1);
    
    cout<<"After Sorting: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    Merge m(size);
    m.getdata();
    m.display();
    return 0;
}