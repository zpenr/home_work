#include <iostream>
#include <bitset>

using namespace std;

char count_controll_sum(long long int board){
    char controll_sum = 0;
    
    long long int temp = board & 0x5555555555555555;
    controll_sum += (__builtin_popcountll(temp) % 2);
    
    temp = board & 0x3333333333333333;
    controll_sum += (__builtin_popcountll(temp) % 2) * 2;
    
    temp = board & 0x0f0f0f0f0f0f0f0f;
    controll_sum += (__builtin_popcountll(temp) % 2) * 4;
    
    temp = board & 0x00ff00ff00ff00ff;
    controll_sum += (__builtin_popcountll(temp) % 2) * 8;
    
    temp = board & 0x0000ffff0000ffff;
    controll_sum += (__builtin_popcountll(temp) % 2) * 16;
    
    temp = board & 0x00000000ffffffff;
    controll_sum += (__builtin_popcountll(temp) % 2) * 32;
    
    return controll_sum;
}

void print_board(long long int board) {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            int cell_number = row * 8 + col;
            int bit_position = 63 - cell_number;
            int bit_value = (board >> bit_position) & 1;
            cout  << bit_value << '\t';
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    long long int board = 0b1110001011010101000001001110000010101000001100110101000011110010;
    int troll_cell = 46;
    cout << "start board\n";
    print_board(board);
    
    char controll_sum = count_controll_sum(board);
    
    cout << "controll sum before = " << bitset<6>(controll_sum) << ' ' << (int)controll_sum<< endl;
    char coin_to_flip = controll_sum ^ troll_cell;
    cout << "coin to flip " << bitset<6>(coin_to_flip)<< ' ' <<(int)coin_to_flip<< endl;
    long long int new_board = board;

    new_board = board ^ (1LL << (63-coin_to_flip));
    
    cout << "\nboard after flip\n";
    print_board(new_board);
    char new_controll_sum = count_controll_sum(new_board);
    
    cout << "number of troll cell = "<< bitset<6>(new_controll_sum) <<' '<<(int)new_controll_sum<< endl;
    
    return 0;
}
