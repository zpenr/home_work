#include <iostream>
#include <locale.h>

using namespace std;
int main(void)
{
    setlocale(LC_ALL, "Russian");

    const int MAX_LEN = 80;

    char x[MAX_LEN];
    char* ptr = &x[0];

    char copyString[MAX_LEN];
    char* ptrCopy = &copyString[0];

    char currentChar;
    cout << "Введите строку для удаления пробелов:\n";
    cin.getline(x, MAX_LEN, '\n');
    
    int i = 0;
    while (*(ptr + i) == ' ')
        i++;
        
    *ptrCopy = *(ptr + i);
    ptrCopy++;
    i++;

    for (i; i < MAX_LEN; i++) {
        currentChar = *(ptr + i);

        if (currentChar == '\0')
            break;

        if (currentChar == ' ' && *(ptrCopy - 1) == ' ') {
            continue;
        }
        *ptrCopy = currentChar;
        ptrCopy++;
    }

    if (*(ptrCopy - 1) == ' ')
        *(ptrCopy-1) = '\0';
    else 
        *(ptrCopy) = '\0';
    cout<<copyString<<'|';



    return 0;
}

