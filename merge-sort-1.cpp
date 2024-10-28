// merge sort using divide and conquer

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int s, int e){
    //divide arr in two parts
    int mid = s + (e-s)/2;
    int len1 = mid - s +1, len2 = e-mid;
    int *first_arr = new int[len1];
    int *second_arr = new int[len2];
    
    
    //add elements in arrays
    int mainArray_index = s;
    for(int i = 0; i < len1; i++){
        first_arr[i] = arr[mainArray_index++];
    }
    for(int i =0; i < len2; i++){
        second_arr[i] = arr[mainArray_index++];
    }

    //merge two sorted arrays
    int index1 = 0, index2 = 0;
    mainArray_index = s;
    while(index1 < len1 && index2 < len2){
        if(first_arr[index1] < second_arr[index2])
            arr[mainArray_index++] = first_arr[index1++];
        else
            arr[mainArray_index++] = second_arr[index2++];
    }
    while(index1 < len1){
        arr[mainArray_index++] = first_arr[index1++];
    }
    while(index2 < len2){
        arr[mainArray_index++] = second_arr[index2++];
    }
    delete []first_arr;
    delete []second_arr;
}

void mergeSort(vector<int> &arr, int s, int e){
    if(s >= e)
        return;
    int mid = s + (e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1, e);
    merge(arr,s,e);
}

