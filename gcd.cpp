// find gcd of an array 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int gcd2(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int gcd(int arr[], int s, int e){
    if(e-s == 0)
        return arr[s];
    if(e-s == 1){
        int ans = gcd2(arr[0], arr[1]);
        return ans;
    }
    int mid = s + (e-s)/2;
    int a = gcd(arr, mid, e );
    int b = gcd(arr, s, mid);
    return gcd2(a, b);
}

int main(){
    int arr[] = {12,3, 36, 1};
    cout << gcd(arr, 0, 1);
}