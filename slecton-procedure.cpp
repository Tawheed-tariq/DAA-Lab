// using selection procdeure and divide and conquer having input array of n unsorted elements and k as integer less than n find the kth smallest element in the array

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int s, int e){
    int pivot = arr[e];
    int i = s-1;
    for(int j = s; j < e; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[e]);
    return i+1;
}

int kthSmallest(vector<int> &arr, int s, int e, int k){
    if(s <= e){
        int p = partition(arr, s, e);
        if(p == k-1)
            return arr[p];
        else if(p > k-1)
            return kthSmallest(arr, s, p-1, k);
        else
            return kthSmallest(arr, p+1, e, k);
    }
    return -1;
}

int main(){
    int n = 15;
    vector<int> arr = {12,2,34,23,56, 78, 3,0,1,43,90,87,65,34,13};
    int k = 5;
    cout << kthSmallest(arr, 0, n-1, k);
}
