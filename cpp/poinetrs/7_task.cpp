#include <iostream>
#include <locale.h>
using namespace std;
int main(void)
{
    setlocale(LC_ALL, "Russian");
    
    srand(time(0));

    int n;

    cout << "Введите длинну массива: ";
    cin >> n;

    int* K = new int[n];


    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        *(K + i) = rand() % 10;
        cout << *(K + i) << ' ';
    }
    cout << endl;
//РЕШЕНИЕ БЕЗ НОВОГО МАССИВА
/*    for (int i = 1; i < n; i++) {
        if (*(K + i) != *K) {
            for (int j = i+1; j < n; j++) {
                if (*(K + i) == *(K + j)) {
                    *(K + j) = *K;
                }
            }
        }
    }


    int i = 1, Last_valid_Index = 0;

    bool Flag = true;

    while (Flag) {
        if (*(K+i) != *K)
            i++;
        if (*(K + i) == *K) {
            Last_valid_Index = i;
            while (*(K + i)==*K) {
                i++;
                if (i == n-1) {
                    Flag = false;
                    break;
                }
            }
            *(K + Last_valid_Index) = *(K + i);
            *(K + i) = *K;
            i = Last_valid_Index;
        }
        i++;
    }
    for (int i = 0; i < Last_valid_Index; i++) {
        cout << *(K+i) << ' ';
    }*/

//РЕШЕНИЕ С НОВЫМ МАССИВОМ
    int* set = new int[n];
    int len_of_set = 0;
    bool flag;
    for (int i = 0; i < n; i++) {
        flag = true;
        for (int j = 0; j < len_of_set; j++) {
            if (*(set + j) == *(K + i)) {
                flag = false;
                break;
            }
        }
        if (flag) 
            *(set + len_of_set++) = *(K + i);
        
    }

    for (int i = 0; i < len_of_set; i++) {
        cout << *(set + i) << ' ';
    }
    return 0;
}
