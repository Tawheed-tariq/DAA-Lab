#include<iostream>
using namespace std;
bool search(int *arr, int n, int key);
int main(){
    int n = 7, arr[n] = {1,2,3,4,5,6}, key = 5, result;
    int res = search(arr, n , key);
    if(res == 1)
	    cout << "found" << endl;
    else
	    cout << "not found"<< endl;
	return 0;
}

bool search(int *arr, int n, int key){
    for(int i =0 ; i < n; i++){
        if(*(arr+i) == key)
            return 1;
    }
    return 0;
}