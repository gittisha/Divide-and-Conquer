#include<iostream>
using namespace std;
class BinarySearch{
    public:
        int binary(int *arr, int lb, int ub, int key){
            if(lb==ub){
                if(key==lb)
                    return lb;
                else
                    return -1;
            }
            if(lb>ub)
                return -1;
            else{
                int mid= (lb+ub)/2;
                if(key==arr[mid])
                    return mid;
                else if(key<arr[mid])
                    return binary(arr, lb, mid-1, key);
                else
                    return binary(arr, mid+1, ub, key);
        }
    }
    int printarray(int *arr, int n){
        for(int i=0; i<n; i++)
            cout<<arr[i]<<" "<<flush;
            cout<<endl;
    }
};
int main(){
    BinarySearch obj;
    int arr[]={12,14,15,16,18,20};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<"Input Array:"<<endl;
    obj.printarray(arr,n);
    int flag= obj.binary(arr,0,n-1,25);
    if (flag==-1)
        cout<<"the key is not found";
    else
        cout<<"The key is foundin index:"<<flag;
    return 0;
}