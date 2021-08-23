#include<bits/stdc++.h>
using namespace std;


bool isSmaller(vector<int> &arr, int i, int j) {
    cout<<"Comparing " << arr[i] << " and " << arr[j]<<endl;
    if (arr[i] < arr[j]) {
      return true;
    } else {
      return false;
    }
  }


  void swap(vector<int> &arr, int i, int j)
{
    cout << ("Swapping index " + to_string(i) + " and index " + to_string(j)) << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}



void bubbleSort(vector<int>arr, int n){
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<n-i;j++){
            if(isSmaller(arr,j+1,j)){
                swap(arr,j+1,j);
            }
        }
    }
}


int main(){
    int a;
    cout<<"Enter the number of elements "<<endl;
    cin>>a;
    vector<int> arr;
    cout<<"Enter elements you want to sort"<<endl;
    for(int i=0;i<a;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int n=a;
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