#include <iostream>
#include <locale.h>

using namespace std;

int add_elem_to_stack(char* ptr_to_stack, char elem, int max_len_of_stack){

    for (int i = max_len_of_stack; i >= 0; i--) {
        if (*(ptr_to_stack + i) == '{' || *(ptr_to_stack + i) == '}' || 
            *(ptr_to_stack + i) == '[' || *(ptr_to_stack + i) == ']' || 
            *(ptr_to_stack + i) == '(' || *(ptr_to_stack + i) == ')') {

                *(ptr_to_stack + i + 1) = elem;
                *(ptr_to_stack + i + 2) = '\0';
                return 0;
        }
    }
    *ptr_to_stack = elem;
    *(ptr_to_stack + 1) = '\0';
    return 0;
}

char get_last_elem_from_stack(char* ptr_to_stack, int max_len_of_stack) {
    for (int i = max_len_of_stack; i >= 0; i--) {
        if (*(ptr_to_stack + i) == '{' || *(ptr_to_stack + i) == '}' ||
            *(ptr_to_stack + i) == '[' || *(ptr_to_stack + i) == ']' ||
            *(ptr_to_stack + i) == '(' || *(ptr_to_stack + i) == ')') {

            return *(ptr_to_stack + i);
        }
    }
    return '0';
}

void remove_elem_from_stack(char* ptr_to_stack, int max_len_of_stack) {
    for (int i = max_len_of_stack; i >= 0; i--) {
        if (*(ptr_to_stack + i) == '{' || *(ptr_to_stack + i) == '}' ||
            *(ptr_to_stack + i) == '[' || *(ptr_to_stack + i) == ']' ||
            *(ptr_to_stack + i) == '(' || *(ptr_to_stack + i) == ')') {

            *(ptr_to_stack + i) = '\0';
            break;
        }
    }
}

int main(void){
    setlocale(LC_ALL, "Russian");

    const int MAX_LEN = 80;

    char x[MAX_LEN];
    char* ptr = &x[0];
 
    char stack[MAX_LEN] = "\n";
    char* ptr_to_stack = &stack[0];
    char currentChar;
    cout << "Введите строку для обработки:\n";
    cin.getline(x, MAX_LEN, '\n');
    
    for (int i = 0; i < MAX_LEN; i++) {
        currentChar = *(ptr + i);
        if (currentChar =='\0')
            break;
        if ((get_last_elem_from_stack(ptr_to_stack, MAX_LEN) == '{' && currentChar == '}') ||
            (get_last_elem_from_stack(ptr_to_stack, MAX_LEN) == '(' && currentChar == ')') || 
            (get_last_elem_from_stack(ptr_to_stack, MAX_LEN) == '[' && currentChar == ']')) {
            remove_elem_from_stack(ptr_to_stack, MAX_LEN+1);
            cout << stack << endl;
            continue;
        }

        if (currentChar == '{' || currentChar == '}' ||
            currentChar == '(' || currentChar == ')' ||
            currentChar == '[' || currentChar == ']') {
            add_elem_to_stack(ptr_to_stack, currentChar, MAX_LEN);
            cout << stack << endl;
        }

    }
        
    if (get_last_elem_from_stack(ptr_to_stack, MAX_LEN) == '0')
        cout << "Скобки расставлены корректно";
    else
        cout << "Скобки расставлены некорректно   " << get_last_elem_from_stack(ptr_to_stack, MAX_LEN);
    


    return 0;
}


