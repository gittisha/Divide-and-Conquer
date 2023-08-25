#include<iostream>
using namespace std;
class QuickSort{
	private:
		int *arr;
		int n;
		int lb;
		int ub;
	public:
		QuickSort(int size){
			n=size;
			arr=new int[n];
		}
		~QuickSort(){
			delete []arr;
		}
		void getdata();
		int arr_partition(int *arr,int lb,int ub);
		void Qsort(int *arr,int lb,int ub);
		void display();
		void swap(int *a,int *b);
};
void QuickSort::getdata(){
	cout<<"Enter the array elements: "<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
}
void QuickSort::display(){
	for(int i=0;i<n;i++)
		cout<<" "<<arr[i];
	Qsort(arr,0,n-1);	
}
void QuickSort::swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
int QuickSort::arr_partition(int a[],int lb,int ub){
	int pivot,i,j;
	pivot=a[ub];
	swap(&a[lb],&a[ub]);
	i=lb;
	j=ub;
	while(i<j){
		while(a[i]<=pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j)
			swap(&a[i],&a[j]);		
	}
	swap(&a[j],&a[lb]);
	return(j);
}
void QuickSort::Qsort(int a[],int lb,int ub){
	int j;
	if(lb<ub){
		j=arr_partition(a,lb,ub);
		Qsort(a,lb,j-1);
		Qsort(a,j+1,ub);
	}
}
int main(){
	int size;
	cout<<"Enter the size of the array : ";
	cin>>size;
	QuickSort obj(size);
	obj.getdata();
	cout<<"Array before sorting: "<<endl;
	obj.display();
	cout<<endl<<"Array after sorting: "<<endl;
	obj.display();
	return 0;
}
