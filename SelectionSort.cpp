#include <iostream>
#include <algorithm>

using namespace std;

void swap(int *i, int *j)
{
  int temp = *i;
  *i = *j;
  *j = temp;
}

void selectionSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int max = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[max])
      {
        max = j;
      }
      if (max != i)
      {
        swap(&arr[i], &arr[max]);
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  selectionSort(arr, n);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}
