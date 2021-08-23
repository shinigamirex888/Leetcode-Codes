#include<bits/stdc++.h>
using namespace std;



bool isGreater(vector<int> & arr, int j, int i) {
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


void insertionSort(vector<int> &arr, int n){
   for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(isGreater(arr,j,j+1)){
                swap(arr,j,j+1);
            }else{
                break;
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
    insertionSort(arr,n);
    cout<<"After sorting: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}