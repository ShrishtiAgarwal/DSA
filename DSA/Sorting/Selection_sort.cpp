#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void selection_Sort(vector<int>arr)
{
    for(int i=0;i<arr.size();i++)
    {
        int min_index=i;
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[j]<arr[min_index])
            min_index=j;
        }
        swap(arr[min_index],arr[i]);
        
    }
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
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
    selection_Sort(arr);
}