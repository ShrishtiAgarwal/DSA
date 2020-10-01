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

void merge(vector<int>&arr,int l,int m,int r)
{
    int n1=m-(l+1);
    int n2=r-m;
    int i=0,j=0,k=l;
    int arr1[n1];
    int arr2[n2];
    for( i=0;i<n1;i++)
        arr1[i]=arr[l+i];
    for (j = 0; j < n2; j++) 
        arr2[j] = arr[m + 1 + j];
        
   i=0,j=0,k=l;
    while(i<n1&&j<n2)
    {
        if (arr1[i] <= arr2[j]) { 
            arr[k] = arr1[i]; 
            i++; 
        } 
        else { 
            arr[k] = arr2[j]; 
            j++; 
        } 
        k++; 
    }
    
    while (i < n1) { 
        arr[k] = arr1[i]; 
        i++; 
        k++; 
    } 
  
   
    while (j < n2) { 
        arr[k] = arr2[j]; 
        j++; 
        k++; 
    }
    
}

void merge_Sort(vector<int>&arr,int l,int r)
{
    if(l<r)
    {
          int m = l + (r - l) / 2; 
        merge_Sort(arr,l,m);
        merge_Sort(arr,m+1,r);
        merge(arr,l,m,r);
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
    merge_Sort(arr,0,arr.size()-1);
    print(arr);
}