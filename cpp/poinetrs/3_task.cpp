#include <iostream>
#include <locale.h>

using namespace std;
int main(void)
{
    setlocale(LC_ALL, "Russian");

    const int MAX_LEN = 80;

    char x[MAX_LEN];
    char* ptr = &x[0];

    int counters_of_numbers[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int* ptr_to_number = &counters_of_numbers[0];
    char currentChar;
    std::cout << "Введите строку для обработки:\n";
    std::cin.getline(x, MAX_LEN, '\n');
    
    for (int i = 0; i < MAX_LEN; i++) {
        currentChar = *(ptr + i);
        if (currentChar =='\0')
            break;
        if (currentChar - '0' >= 0 && currentChar - '0' <= 9) {
            (*(ptr_to_number + (currentChar - '0')))++;
        }
    }
        

    int max_number;
    int max_number_of_numbers = 0;
    for (int i = 0; i < 10; i++) {
        if (max_number_of_numbers < *(ptr_to_number + i)) {
            max_number = i;
            max_number_of_numbers = *(ptr_to_number + i);
        }
    }
    if (max_number_of_numbers == 0) {
        cout << "В строке нет цифр";
        return 1;
    }
    cout << "Цифра, которая встречается чаще всего - "<< max_number;


    return 0;
}

