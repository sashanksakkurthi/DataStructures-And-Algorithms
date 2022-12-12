#include <iostream>

using namespace std;

int knapSack(int profit[], int weight[], int W, int n)
{
  if (n == 0 || W == 0)
  {
    return 0;
  }
  if (weight[n - 1] > W)
  {
    return knapSack(profit, weight, W, n - 1);
  }
  else
  {
    return max(profit[n - 1] + knapSack(profit, weight, W - weight[n - 1], n - 1), knapSack(profit, weight, W, n - 1));
  }
}

int main()
{
  
}
