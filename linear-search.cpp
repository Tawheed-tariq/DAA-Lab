#include<iostream>
#include<vector>
using namespace std;

bool search(vector<int> &arr, int key);

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int key = 5;
    bool res = search(arr, key);
    if(res)
        cout << "found" << endl;
    else
        cout << "not found" << endl;
    return 0;
}

bool search(vector<int> &arr, int key){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == key)
            return true;
    }
    return false;
}