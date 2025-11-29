#include <iostream>

using namespace std;

char bases_letters[] = "0123456789ABCDEF";

void tranlate_nubmer_to_other_base(int current_number, int need_base);

int main()
{
    int number, need_base;

    cout << "Enter number to translate: ";
    cin >> number;

    cout << "Enter need base: ";
    cin >> need_base;
    tranlate_nubmer_to_other_base(number, need_base);
}

void tranlate_nubmer_to_other_base(int current_number, int need_base) {

    if (current_number < need_base) {
        cout << bases_letters[current_number];
        return;
    }

    tranlate_nubmer_to_other_base(current_number / need_base, need_base);

    cout << bases_letters[current_number % need_base];
}