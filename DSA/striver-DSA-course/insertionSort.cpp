#include <bits/stdc++.h>
using namespace std;
void insertionSort(int A[], int n)
{
  for(int i = 1; i < n ; i ++ ){
    int CurEle = A[i];
    int j = i;
    while(j > 0 && A[j-1] > CurEle){
      A[j] = A[j-1];
      j--;
    }
    A[j] = CurEle;
  }
}

int main(){
  int N;
  cin >> N;
  vector<int>A(N,0);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  insertionSort(A.data(),A.size());
  for (int i = 0; i < N; i++) {
    cout << A[i] << " ";
  }

}

