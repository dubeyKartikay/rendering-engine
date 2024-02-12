#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>& A) {
  int N = A.size();
  for (int i = 0; i < N - 1; i++) {
    int minIndex = i;
    for(int j = i + 1 ; j < N; j++){
      if(A[j]<A[minIndex]){
        minIndex = j;
      }
    }
    swap(A[minIndex],A[i]);
  }
}

int main(){
  int N;
  cin >> N;
  vector<int>A(N,0);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  selectionSort(A);
  for (int i = 0; i < N; i++) {
    cout << A[i] << " ";
  }

}
