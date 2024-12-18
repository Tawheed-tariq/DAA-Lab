#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int s, int e){
    int pivot = arr[s], count= 0;
    for(int i = s+1; i <= e; i++){
        if(arr[i] <= pivot)
            count++;
    }
    //taking pivot to its right position
    int pivotIndex = count +s;
    swap(arr[pivotIndex], arr[s]);

    //making left side of pivot <= pivot and right side of pivot >= pivot
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    if(s >= e)
        return;
    int p = partition(arr, s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int main(){
    int arr[10] = {5,3,6,1,7,8,2,4,9,0}, n= 10;
    quickSort(arr,0,n-1);
    for(int i =0; i < n; i++){
        cout << arr[i] << "\t";
    }
}