#include<bits/stdc++.h>
using namespace std;



void bubbleSort(int arr[], int n){
    for(int i=1;i<=n-1;i++){         //no. of iterations
        for(int j=0;j<n-i;j++){      //going till n-1 for 1st iteration
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
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
    bubbleSort(arr,n);
    cout<<"After sorting: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}