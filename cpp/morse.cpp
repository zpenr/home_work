#include <iostream>


using namespace std;

const int MAX_LEN = 100;

const char letters[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z'
};

const char morze_codes[26][5] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

void from_morze_to_letters(char in_str[], int start_pos, int end_pos);
void from_letters_to_morze(char in_str[], int start_pos, int end_pos);
int space_split(char in_str[], int* start_pos, int* end_pos);
void translator(char in_str[]);
int determiner(char in_str[]);

int main(void)
{
    char in_str[MAX_LEN];
    cin.getline(in_str, MAX_LEN, '\n');
    translator(in_str);
    return 0;
}

int determiner(char in_str[]) {
    char* letter = &in_str[0];
    for (; *letter != 0; letter++) {
        if (*letter == '-' || *letter == '.') 
            return 0;
    }
    return 1;
}

void translator(char in_str[]) {
    int start_pos = 0, end_pos = 0;
    if (determiner(in_str)) {
        while (true) {
            if (space_split(in_str, &start_pos, &end_pos)) {
                from_letters_to_morze(in_str, start_pos, end_pos-1);
            }
            else {
                from_letters_to_morze(in_str, start_pos, end_pos-1);
                break;
            }
        }       
    }
    else {
        while (true) {
            if (space_split(in_str, &start_pos, &end_pos)) {
                from_morze_to_letters(in_str, start_pos, end_pos - 1);
            }
            else {
                from_morze_to_letters(in_str, start_pos, end_pos - 1);
                break;
            }
        }
    }
}

int space_split(char in_str[], int* start_pos, int* end_pos) {

    *start_pos = *end_pos;
    while (in_str[*start_pos] == ' ') {
        (*start_pos)++;
    }
    *end_pos = *start_pos;
    for (*end_pos; in_str[*end_pos] != ' '; (*end_pos)++) {
        if (in_str[*end_pos] == '\0')
            return 0;
    }
    return 1;
}

void from_letters_to_morze(char in_str[], int start_pos, int end_pos) {
    char upper_char;
    int index;
    for (int i = start_pos; i <= end_pos; i++) {
        if (in_str[i] == 0)
            break;
        upper_char = toupper(in_str[i]);
        if (upper_char >= 'A' && upper_char <= 'Z') {
            index = upper_char - 'A';
            cout << morze_codes[index] << ' ';
        }
    }
    for (int i = start_pos; i <= end_pos; i++) {
        cout << in_str[i] << ' ';
    }
    cout << '\n';
}

void from_morze_to_letters(char in_str[], int start_pos, int end_pos) {
    bool flag;
    int k;
    for (int j = 0; j < 25; j++) {
        if (morze_codes[j][end_pos - start_pos+1] == '\0') {
            flag = true;
            k = 0;
            for (int i = start_pos; i <= end_pos; i++, k++) {
                if (in_str[i] != morze_codes[j][k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << letters[j];
                break;
            }
        }
    }
}