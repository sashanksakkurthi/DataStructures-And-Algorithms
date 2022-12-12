#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item
{
  int value;
  int weight;
};

int compare(item a, item b)
{
  return a.value / a.weight > b.value / b.weight;
}

double fractionalKnapSack(int capacity, vector<item> items)
{
  sort(items.begin(), items.end(), compare);
  double totalValue = 0;
  for (item i : items)
  {
    if (capacity == 0)
      break;
    
    int amount = min(capacity, i.weight);

    totalValue += amount * i.value / i.weight;

    // remove amount from capacity
    capacity -= amount;
  }
  return totalValue;
}

int main()
{
  vector<item> items = {{60, 10}, {100, 20}, {120, 30}};
  int capacity = 50;
  cout << "Maximum value: " << fractionalKnapSack(capacity, items) << endl;
  return 0;
}
