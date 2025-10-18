#include <iostream>
#include <climits>
#include <cstdlib>


using namespace std;

int main()
{
  int A[100];
  for (int i = 0; i < 100; i++) {
    A[i] = rand() % 5;
  }

  for (int i = 0; i < 100; i++) {
    cout << A[i] << ' ';
  }
  cout << endl;
  int i = 0, FirstZeroIndex = 0 ;
  
  bool Flag = true;

  while (Flag) {
    if (A[i] != 0)
      i++;
    if (A[i] == 0) {
      FirstZeroIndex = i;
      while (!A[i]) {
        i++;
        if (i == 99) {
          Flag = false;
          break;
        }
      }
      A[FirstZeroIndex] = A[i];
      A[i] = 0;
      i = FirstZeroIndex;
    }
    i++;
  }

  for (int i = 0; i < 100; i++) {
    cout << A[i] << ' ';
  }
}
