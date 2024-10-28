// create an array of n elements and then use min heapity and max heapity to create a min heap and max heap respectively.

#include <iostream>
#include <vector>
using namespace std;

void min_heapify(vector<int> &arr, int i, int n){
    int smallest = i, left = 2*i, right = 2*i + 1;
    if(left <= n && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right <= n && arr[right] < arr[smallest]){
        smallest = right;
    }
    if(smallest != i){
        swap(arr[i], arr[smallest]);
        min_heapify(arr, smallest, n);
    }
}

void max_heapify(vector<int> &arr, int i, int n){
    int largest = i, left = 2*i, right = 2*i + 1;
    if(left <= n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        max_heapify(arr, largest, n);
    }
}


int main(){
    int n = 10;
    vector<int> arr = {12,2,34,23,56, 78, 3,0,1,43};
    for(int i = n/2; i >= 1; i--){
        min_heapify(arr, i, n);
    }
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = n/2; i >= 1; i--){
        max_heapify(arr, i, n);
    }
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
}
