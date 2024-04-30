#include <iostream>
using namespace std;
struct Item
{
    int weight;
    int value;
    double density;
};
void swapItems(Item &item1, Item &item2)
{
    Item temp = item1;
    item1 = item2;
    item2 = temp;
}
void sortItemsByDensity(Item items[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (items[j].density < items[j + 1].density)
            {
                swapItems(items[j], items[j + 1]);
            }
        }
    }
}
double fractionalKnapsack(int capacity, Item items[], int n)
{
    sortItemsByDensity(items, n);
    double totalValue = 0.0;
    for (int i = 0; i < n; ++i)
    {
        if (capacity >= items[i].weight)
        {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            totalValue += (static_cast<double>(capacity) / items[i].weight) * items[i].value;
            break;
        }
    }
    return totalValue;
}
int main()
{
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    Item items[10];
    cout << "Enter the weights and values of the items:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> items[i].weight >> items[i].value;
        items[i].density =
            static_cast<double>(items[i].value) / items[i].weight;
    }
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    double result = fractionalKnapsack(capacity, items, n);
    cout << fixed << "Maximum value in Fractional Knapsack: " << result << endl;
    cout << "NAME : HARSHRAJSINH ZALA" << endl
         << "REGNO : 22BCE2238" << endl;
    return 0;
}