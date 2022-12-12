#include <iostream>

using namespace std;

void merge(int arr[],int begin,int mid,int end){
  int n1 = mid-begin+1;
  int n2 = end-mid;
  int temp1[n1];
  int temp2[n2];
  for (int i = 0; i < n1; ++i){
    temp1[i] = arr[begin+i];
  }
  for (int i = 0; i < n2; ++i){
    temp2[i] = arr[mid+1+i];
  }
  int i=0,j=0,k=begin;
  while(n1 > i && n2 > j){
    if(temp1[i] < temp2[j]){
      arr[k] = temp1[i];
      i++;k++;
    }
    else{
      arr[k] = temp2[j];
      j++;k++;
    }
  }
  while(n1 > i){
    arr[k] = temp1[i];
      i++;k++;
  }
  while(n2 > j){
    arr[k] = temp2[j];
      j++;k++;
    }
}

void mergesort(int arr[],int begin,int end){
  if (begin < end){
    int mid = (begin+end)/2;
    mergesort(arr,begin,mid);
    mergesort(arr,mid+1,end);
    merge(arr,begin,mid,end);
  }
}

void print(int arr[],int size){
  for (int i=0;i < size;i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(){
  int size;
  cin >> size;
  int arr[size];
  for (int i = 0; i < size; ++i){
    cin >> arr[i];
  }
  mergesort(arr,0,size-1);
  print(arr,size);
}
