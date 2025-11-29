#include <iostream>
#include <ctime>

int generator(char sign, int range);
void answer_checker(int right_answer, int user_unswer, int* score);
void select_difficult(int* range);

using namespace std;
int main()
{
    char sign;
    int user_answer, right_answer, range, score = 0, expression_cnt = 0;
    select_difficult(&range);
    cout << "Enter sign: ";
    cin >> sign;
    
    while (!cin.fail()) {
        cout << "Enter letter to end\n";
        right_answer = generator(sign, range);
        
        cin >> user_answer;
        if (!cin.fail()) {
            expression_cnt++;
            answer_checker(right_answer, user_answer, &score);
        }
    }

    cout << "Right answers: " << score << " mistakes: " << expression_cnt - score;
    if (expression_cnt)
        cout << " accuracy: " << score * 100 / expression_cnt << '%';
}

void select_difficult(int* range) {

    int difficulty_choice;

    cout << "Select difficulty level:" << endl;
    cout << "1. Easy   (numbers 1-10)" << endl;
    cout << "2. Medium (numbers 1-50)" << endl;
    cout << "3. Hard   (numbers 1-100)" << endl;

    cin >> difficulty_choice;

    switch (difficulty_choice) {
    case 1:
        *range = 10;
        break;
    case 2:
        *range = 50;
        break;
    case 3:
        *range = 100;
        break;
    default:
        cout << "Invalid choice. Default \'Easy\' difficult (1-10)." << endl;
        *range = 10;
        break;
    }
}

int generator(char sign, int range) {

    srand(time(NULL));

    int a = rand() % range + 1;
    int b = rand() % range + 1;
    int ans;
    switch (sign) {
        case '+':
            ans = a + b;
            cout << a << '+' << b << " = ";
            return ans;
        case '-':
            ans = a - b;
            cout << a << '-' << b << " = ";
            return ans;
        case '*':
            ans = a * b;
            cout << a << '*' << b << " = ";
            return ans;
        case '/':
            a = (rand() % range + 1) * b;
            ans = a / b;
            cout << a << '/' << b << " = ";
            return ans;
        default:
            cout << "the wrong sign";
    }
    
}

void answer_checker(int right_answer, int user_answer, int* score) {
    if (user_answer == right_answer) {
        cout << "Correct!" << endl;
        (*score)++;
    }
    else {
        cout << "Wrong! Correct answer: " << right_answer << endl;
    }
}