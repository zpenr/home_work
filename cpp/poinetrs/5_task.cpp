#include <iostream>
#include <locale.h>
using namespace std;
int main(void)
{
  setlocale(LC_ALL, "Russian");

  const int MAX_LEN = 80;

  char x[MAX_LEN];
  char* ptr = &x[0];
  
  cout << "Введите строку для обработки: ";
  cin.getline(x, MAX_LEN, '\n');
  
  int indexes[MAX_LEN];
  int* ptr_to_indexes = &indexes[0];

  int levels[MAX_LEN];
  int* ptr_to_levels = &levels[0];

  char currentChar;
  int current_level=0;
  
  int max_levels[MAX_LEN];
  int* ptr_to_max_levels = &max_levels[0];
  
  for (int i = 0; i < MAX_LEN; i++) {
    currentChar = *(ptr + i);
    if (currentChar == '\0')
      break;
    if (currentChar == '(') {
      *ptr_to_indexes++ = i;
      *ptr_to_levels++ = ++current_level;
      if (current_level > *ptr_to_max_levels)
        *ptr_to_max_levels = current_level;
      continue;
    }
    if (currentChar == ')') {
      *(ptr_to_indexes)++ = i;
      *ptr_to_levels++ = -current_level;
      current_level--;
      if (current_level == 0){
            ptr_to_max_levels++;
        }
    }
        
  }
  *ptr_to_indexes = -1;

  ptr_to_indexes = &indexes[0];
  ptr_to_levels = &levels[0];
  ptr_to_max_levels = &max_levels[0];
  for (int j=0; j < MAX_LEN; j++ ){
    if (*(ptr_to_indexes + j) == -1) 
      break;
        if (*(ptr_to_levels + j) == 1 && j!=0){
            ptr_to_max_levels++;
        }
        if (*(ptr_to_levels + j) == *ptr_to_max_levels) {
      *(ptr + (*(ptr_to_indexes + j))) = '(';
      continue;
    }
    if (*(ptr_to_levels + j) == -(*ptr_to_max_levels)) {
      *(ptr + (*(ptr_to_indexes + j))) = ')';
      continue;
    }

    if (*(ptr_to_levels + j) == *ptr_to_max_levels - 1) {
      *(ptr + (*(ptr_to_indexes + j))) = '[';
      continue;
    }
    if (*(ptr_to_levels + j) == -(*ptr_to_max_levels - 1)) {
      *(ptr + (*(ptr_to_indexes + j))) = ']';
      continue;
    }
    
      if (*(ptr_to_levels + j) >= -(*ptr_to_max_levels - 2) && *(ptr_to_levels + j)<0) {
      *(ptr + (*(ptr_to_indexes + j))) = '}';
      continue;
    }
    if (*(ptr_to_levels + j) <= *ptr_to_max_levels - 2 && *(ptr_to_levels + j)>0) {
      *(ptr + (*(ptr_to_indexes + j))) = '{';
      continue;
    }


  }


  cout << x;

  return 0;
}
