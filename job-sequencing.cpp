#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Job
{
    char id;
    int dead;
    int profit;
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comparison);

    int len = -1;
    for(int i =0; i < n; i++){
        if(arr[i].dead > len){
            len = arr[i].dead;
        }
    }
    unordered_map<int, bool> mp;
    int result[len];
    for(int i = len-1; i >= 0; i--){
        result[i] = -1;
        for(int j = 0; j < n; j++){
            if(arr[j].dead > i){
                if(mp.find(j) == mp.end()){
                    result[i] = j;
                    mp[j] = true;
                    break;
                }
            }
        }

    }

    for (int i = 0; i < len; i++)
    {
        cout << arr[result[i]].id << " ";
    }
}

int main()
{
    Job arr[] = {{'A', 2, 100}, {'B', 1, 19}, {'C', 2, 27}, {'D', 1, 25}, {'E', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs\n";
    printJobScheduling(arr, n);
    return 0;
}

