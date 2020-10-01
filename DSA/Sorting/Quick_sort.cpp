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

int parition(vector<int>&arr,int l,int r)
{
    
   int pivot = arr[r];
   int i=l-1;
   for(int j=l;j<=r-1;j++)
   {
       if(arr[j]<pivot)
       {
           i++;
           swap(arr[i],arr[j]);
       }
       
     
   }
   swap(arr[i+1],arr[r]);
   return i+1;
  
    
}

void quick_Sort(vector<int>&arr,int l,int r)
{
    if(l<r)
    {
        int pi = parition(arr,l,r);
        quick_Sort(arr,l,pi-1);
        quick_Sort(arr,pi+1,r);
    }
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
    quick_Sort(arr,0,arr.size()-1);
    print(arr);
}