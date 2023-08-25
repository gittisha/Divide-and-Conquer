#include <iostream>
using namespace std;

class QuickSort {
public:
    int n, *arr;

    QuickSort(int size) {
        n = size;
        arr = new int[n];
    }

    ~QuickSort() {
        delete[] arr;
    }

    void getdata();
    void display();
    int partition(int a[], int l, int r);
    void qsort(int a[], int l, int r);
    void swap(int *a, int *b);
};

void QuickSort::getdata() {
    cout << "Enter array Elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void QuickSort::display() {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void QuickSort::swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int QuickSort::partition(int a[], int l, int r) {
    int pivot = a[l];
    int i = l + 1;

    for (int j = l + 1; j <= r; j++) {
        if (a[j] < pivot) {
            swap(&a[i], &a[j]);
            i++;
        }
    }
    swap(&a[l], &a[i - 1]);
    return (i - 1);
}

void QuickSort::qsort(int a[], int l, int r) {
    if (l < r) {
        int j = partition(a, l, r);
        qsort(a, l, j - 1);
        qsort(a, j + 1, r);
    }
}

int main() {
    int size;
    cout << "Enter number of elements: ";
    cin >> size;
    QuickSort q(size);
    q.getdata();

    cout << "Array before sort: ";
    q.display();

    q.qsort(q.arr, 0, q.n - 1);

    cout << "Array after sort: ";
    q.display();

    return 0;
}
