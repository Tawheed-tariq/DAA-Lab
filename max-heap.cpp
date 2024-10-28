#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// 1 based indexing
class heap{
    public:
    int size;
    int *arr;
    heap(){
        size = 0;
        arr = new int[100000];
    }
    void insetion(int info){
        size++;
        int index = size;
        arr[size] = info;
        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }

//nodes after n/2 of array are leaf nodes so traverse from 
//n/2 to 0 and heapify every element 
    void heapify(int i ){
        int largest = i, left = 2*i , right = 2*i +1;

        if(left <= size && arr[left] > arr[largest]){
            largest = left;
        }
        if(right <= size && arr[right] > arr[largest]){
            largest = right;
        }
        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }
};


int main(){
    heap h;
    int x;
    while(1){
        cin >> x;
        if(x == -1)
            break;
        h.insetion(x);
    }
    cout << endl;
    for(int i = 1; i <= h.size; i++){
        cout << h.arr[i] << " ";
    }
    return 0;
}
    