#include <iostream>
using namespace std;
int binarySearch(int *arr, int n, int x){
    int l = 0, r = n-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(arr[mid] == x){
         return mid;
        }
        else if(arr[mid] < x){
             l = mid + 1;
        }
        else{
             r = mid - 1;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the number of elements";
    cin>>n;
    int arr[n];
    cout<<"Enter the List of elements Seperated by space";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int element;
    cout<<"Enter the element to be searched";
    cin>>element;
    int index=binarySearch(arr,n,element);
    if(index==-1){
        cout<<"Element not found";
    }else{
        cout<<"Element found at index "<<index;
    }
    return 0;
}
