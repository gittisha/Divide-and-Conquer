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
    int n;
    cout<< "Enter the number of elements:";
    cin>> n;
    cout<< "Enter the elements:";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Input Array:"<<endl;
    obj.printarray(arr,n);
    int k;
    cout<<"Enter the key to search:";
    cin>>k;
    int flag= obj.binary(arr,0,n-1,k);
    if (flag==-1)
        cout<<"the key is not found";
    else
        cout<<"The key is foundin index:"<<flag;
    return 0;
}