#include <bits/stdc++.h>
using namespace std;

// Define an item with value and weight
struct Item {
    int value;
    int weight;
};

// Comparator function to sort items by value/weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // sort in descending order
}

double fractionalKnapsack(int W, vector<Item> &items) {
    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;

    for (auto it : items) {
        if (W == 0) break; // knapsack is full

        if (it.weight <= W) {
            // take whole item
            W -= it.weight;
            totalValue += it.value;
        } else {
            // take fraction of item
            totalValue += it.value * ((double)W / it.weight);
            W = 0;
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> items(n);

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter maximum weight of knapsack: ";
    cin >> W;

    double maxValue = fractionalKnapsack(W, items);
    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}
