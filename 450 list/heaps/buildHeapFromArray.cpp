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

int main()
{
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    buildHeap(arr, n);
    printHeap(arr, n);
    return 0;
}
