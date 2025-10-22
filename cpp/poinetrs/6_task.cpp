#include <iostream>
#include <locale.h>
using namespace std;
int main(void)
{
  setlocale(LC_ALL, "Russian");

  

  const int MAX_LEN = 1000;

  int x[1000];
for (int i = 0; i < 512; i++) *(x+i) = i + 1;
for (int i = 512; i < 1000; i++) *(x+i) = 0;
  int* ptr = &x[0];
  
  
  int left = 0;
  int right= MAX_LEN-1;
  int mid;
  bool flag_right = false;
  
    for (int i = 0; i<=10; i++){
        mid = (left+right)/2;
        if (*(ptr + mid) == 0){
            right = mid - 1;
            continue;
        }
        else if (*(ptr + mid) != 0){
            left = mid + 1;
        }
        
    }
    
    cout<< mid+1;



    return 0;
}
