#include <iostream>
#include <locale.h>
using namespace std;


int match_numbers(int* first_number, int* second_number, int len) {
    for (int i = 0; i < len; i++) {
        if (*(first_number + i) > *(second_number + i))
            return 1;
        if (*(second_number + i) > *(first_number + i))
            return 2;
    }
    return 0;
}


int main(void)
{
    setlocale(LC_ALL, "Russian");
    
    srand(time(0));

    const int m=5, n=4;



    int L[m][n] = {
    {1,0,1,0},
    {0,1,1,0},
    {1,0,1,0},
    {0,0,1,1},
    {0,1,1,0}  
    };

    int* matrix_ptr = &L[0][0];

    for (int i = 0; i < m - 1; i++) {
        int* current_row = matrix_ptr + i * n;

        for (int j = i + 1; j < m; j++) {
            int* match_row = matrix_ptr + j * n;

            if (match_numbers(current_row, match_row, n)==0) {
                for (int k = 0; k < n; k++) {
                    *(match_row + k) = -1;
                }
            }
        }
    }

    for (int i = 0; i < m - 1; i++){
  
        for (int j = 0; j < m - i - 1; j++){
            int* first_number = matrix_ptr + j * n;
            int* second_number = matrix_ptr + (j + 1) * n;


            if (match_numbers(first_number, second_number, n) == 1) {
                for (int k = 0; k < n; k++) {
                    int temp = *(first_number + k);
                    *(first_number + k) = *(second_number + k);
                    *(second_number + k) = temp;
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int* row = matrix_ptr + i * n;
        if (*row != -1) {
            for (int j = 0; j < n; j++) {
                cout << *(row + j) << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
