#include<bits/stdc++.h>
using namespace std;



void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){         
        for(int j=i-1;j>=0;j--){      //comparing the elements from i-1
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
            }else{
                break;
            }
        }
    }
}


int main(){
    int arr[]={2,5,4,7,1,3,6,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Before sorting: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    insertionSort(arr,n);
    cout<<"After sorting: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}