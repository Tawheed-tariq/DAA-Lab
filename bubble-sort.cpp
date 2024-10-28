#include<iostream>
using namespace std;
void swap(int *, int *);
void bubble_sort(int *, int);
int main(){
    int n = 5 , arr[5] = {1, 5,2,6,3};
    bubble_sort(arr, n);
    for(int i = 0; i< n; i++){
        cout << arr[i] << "\t";
    }

}

void bubble_sort(int arr[], int n){
    bool swapped = false;
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j< i; j++){
            if(arr[j] > arr[j+1]){
                swap((arr+j), (arr+j+1));
                swapped = true;
                }
        }
        if(swapped == false)//already sorted
            break;
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

