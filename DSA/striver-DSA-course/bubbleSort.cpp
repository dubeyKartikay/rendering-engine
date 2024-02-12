#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>& A) {
  int N = A.size();
  for (int i = 0; i < N - 1; i++) {
    for(int j = 0 ; j < N - i - 1; j++){
      if(A[j] > A[j+1]){
        swap(A[j],A[j+1]);
      }
    }
  }
}

int main(){
  int N;
  cin >> N;
  vector<int>A(N,0);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  bubbleSort(A);
  for (int i = 0; i < N; i++) {
    cout << A[i] << " ";
  }

}
