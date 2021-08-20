#include<bits/stdc++.h>
using namespace std;



void selectionSort(int arr[], int n){
     for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        swap(arr[i],arr[mini]);
    }
}


int main(){
    int arr[]={2,5,4,7,1,3,6,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Before sorting: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    selectionSort(arr,n);
    cout<<"After sorting: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}