#include <iostream>
using namespace std;

void quickSort(int input[], int start, int end) {
  if (start >= end) {
    return;
  }
  int pivot = input[start + (end - start) / 2];
  int i = start - 1;
  int j = end + 1;
  for (int k = 0; (k < end - start + 1) && (i < j ); k++) {
    cout << "i:" << i << " :j" << j << " ";
    if (input[k] < pivot) {
      i++;
      std::swap(input[k], input[i]);
    } else {
      j--;
      std::swap(input[k], input[j]);
    }
    for (size_t l = 0; l < 10; l++) {
      cout << input[l] << " ";
    }
    cout << endl;
  }
}
int main() {
  int inp[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  quickSort(inp, 0, 9);
}
