#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

// Comparison function to sort items by value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    for (const auto& item : items) {
        if (W == 0) break;
        if (item.weight <= W) {
            W -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * ((double)W / item.weight);
            W = 0;
        }
    }
    return totalValue;
}

int main() {
    int W = 50; 
    Item a = {10 , 40};
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};

    double maxValue = fractionalKnapsack(W, items);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}