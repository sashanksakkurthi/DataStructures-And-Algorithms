#include <iostream>
#include <vector>

using namespace std;

int partition(int v[], int start, int end)
{

  int pivot = v[start];
  int i = start, j = end;

  while (i < j)
  {
    while (pivot >= v[i])
    {
      i++;
    }
    while (pivot < v[j])
    {
      j--;
    }
    if (i < j)
    {
      swap(v[i], v[j]);
    }
  }
  swap(v[start], v[j]);
  return j;
}

void QuickSort(int v[], int start, int end)
{
  if (start < end)
  {
    int pi = partition(v, start, end);
    QuickSort(v, start, pi - 1);
    QuickSort(v, pi + 1, end);
  }
}

int main()
{
  int size;
  cin >> size;
  int v[size];
  for (int i = 0; i < size; ++i)
  {
    cin >> v[i];
  }
  QuickSort(v, 0, size - 1);
  for (auto i : v)
  {
    cout << i << endl;
  }
}
