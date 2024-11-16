#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

pair<int, int> findMaxMin(const vector<int>& arr) {
    if (arr.empty()) {
        throw invalid_argument("Array is empty");
    }

    int maxVal = INT_MIN;
    int minVal = INT_MAX;

    for (int num : arr) {
        if (num > maxVal) {
            maxVal = num;
        }
        if (num < minVal) {
            minVal = num;
        }
    }

    return {maxVal, minVal};
}

int main() {
    vector<int> arr = {3, 5, 1, 8, 2, 9, 4};
    try {
        pair<int, int> result = findMaxMin(arr);
        cout << "Maximum: " << result.first << endl;
        cout << "Minimum: " << result.second << endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}