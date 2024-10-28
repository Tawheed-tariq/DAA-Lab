#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int start, int end, int key){
    int mid = start + (end- start)/2;
    if(start > end)
        return -1;
    if(arr[mid] == key)
        return mid;
    else if(arr[mid] > key)
        return binary_search(arr, 0, mid-1, key);
    else 
        return binary_search(arr, mid+1, end, key); 
}

int main(){
    int n = 6,key = 8;
    int arr[] = {1,2,4,6,8,9};
    cout << binary_search(arr,0, n, key);
}