#include <bits/stdc++.h>
using namespace std;
// arr -> given, n -> size of arr, i -> index of assumed root
void heapify(int *arr, int n, int i)
{
    int largest = i;
    int lc = 2 * i + 1;
    int rc = 2 * i + 2;
    if (lc < n && arr[lc] > arr[largest])
        largest = lc;
    if (rc < n && arr[rc] > arr[largest])
        largest = rc;
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int *arr, int n)
{
    // index of last non-leaf node->(n/2)-1;
    int si = (n / 2) - 1;
    for (int i = si; i >= 0; i--)
        heapify(arr, n, i);
}

void printHeap(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void heapSort(int *arr,int n){
    buildHeap(arr,n);
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

void printArray(int* arr, int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    heapSort(arr, n);
    // In ascending order
    cout << "Sorted array not heap array \n";
    printArray(arr, n);
}