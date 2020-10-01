// Insertion Sort Implemented
// Time complexity - O(n^2)
// Space Complexity - O(1)
// Stable sort 
// In Place -> Yes




#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<int>&arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}

void insertion_Sort(vector<int>arr)
{
    for(int i=1;i<arr.size();i++)
    {
       int key=arr[i];
       int j=i-1;
       while(j>=0 && arr[j]>key)
       {
           arr[j+1]=arr[j];
           j=j-1;
       }
       arr[j+1]=key;
    }
    print(arr);
}



int main() 
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertion_Sort(arr);
}