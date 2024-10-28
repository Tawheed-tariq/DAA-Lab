#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int power(int a, int n){
    if(n == 0)
        return 1;
    if(n == 1)
        return a;
    int x = power(a, n/2);
    if(n%2 == 0)
        return x*x;
    return x*x*a;
}

int main(){
    int a = 2, n = 10;
    cout << power(a, n);
}
