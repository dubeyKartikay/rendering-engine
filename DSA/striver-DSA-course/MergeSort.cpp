#include <cstring>
#include <iostream>

void merge(int arr[], int l, int r){
  int mid = l + (r-l)/2;
  int i = l, j = mid+1;
  int k = 0;
  int * aux_arr = new int[r-l+1];
  while(i <= mid && j <= r){
    if(arr[i] > arr[j]){
      aux_arr[k] = arr[j];
      j++;
    }else{
      aux_arr[k] = arr[i];
      i++;
    }
    k++;
  }
  if(i <= mid ){
    memcpy(aux_arr + k, arr + i, sizeof(int)*(mid-i+1));
  }
  if(j <= r){
    memcpy(aux_arr + k, arr + j, sizeof(int)*(r-j+1));
  }
  memcpy(arr + l, aux_arr, sizeof(int)*(r-l+1));
  free(aux_arr);
}
void mergeSort(int arr[], int l, int r) {
  if(r<=l){
    return;
  }
  int mid = l + (r-l)/2;
  mergeSort(arr, l, mid);
  mergeSort(arr, mid+1, r);
  merge(arr,l,r);
}
using namespace std;
int main(){
  int n;
  cin >> n;
  int  * arr = new int[n];
  for (size_t i = 0; i < n; i++) {
    cin >> arr[i];
  }
  mergeSort(arr, 0, n-1);
  for (size_t i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}
