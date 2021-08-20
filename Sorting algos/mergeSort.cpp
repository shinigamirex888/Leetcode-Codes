#include<bits/stdc++.h>

using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B)
{
    if (A.size() == 0 || B.size() == 0)
        return A.size() == 0 ? B : A;

    int n = A.size();
    int m = B.size();
    vector<int> ans(n + m, 0);

    cout << ("Merging these two arrays ") << endl;
    cout << ("left array -> ");
    print(A);
    cout << ("right array -> ");
    print(B);

    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (A[i] < B[j])
            ans[k++] = A[i++];
        else
            ans[k++] = B[j++];
    }

    while (i < n)
        ans[k++] = A[i++];
    while (j < m)
        ans[k++] = B[j++];

    return ans;
}

vector<int>ms(vector<int>&arr,int lo,int hi){
    if(lo==hi){
        vector<int>v;
        v.push_back(arr[lo]);
        return v;
    }
    int mid=(lo+hi)/2;
    vector<int>a=ms(arr,lo,mid);
    vector<int>b=ms(arr,mid+1,hi);
    vector<int>final=mergeTwoSortedArrays(a,b);
    return final;
}
vector<int> mergeSort(vector<int> &arr)
{
    int lo=0;
    int hi=arr.size()-1;
    vector<int>ans=ms(arr,lo,hi);
    return ans;
    
}

int main()
{
    int n, m;
    cout<<"Enter Size of the array"<<endl;
    cin >> n;
    vector<int> A(n, 0);
    cout<<"Enter the array elements one by one"<<endl;
    input(A);

    vector<int> ans = mergeSort(A);
    cout << "Sorted Array -> ";
    print(ans);
    return 0;
}