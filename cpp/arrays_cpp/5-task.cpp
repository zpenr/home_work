#include <iostream>
#include <utility>


using namespace std;

bool ChangeCell(int A[10][10], int row, int column, int cnt) {
    if (A[row][column] == cnt+1) {
        return true;
    }
    return false;
}

bool CheckCell(int A[10][10], int row, int column, int cnt) {
    bool Flag = false;
    if (row > 0 && row < 9 && column > 0 && column < 9) {
        Flag = ChangeCell(A, row + 1, column, cnt) 
            || ChangeCell(A, row, column + 1, cnt) 
            || ChangeCell(A, row -1 , column, cnt) 
            || ChangeCell(A, row, column - 1, cnt) 
            || ChangeCell(A, row - 1, column - 1, cnt) 
            || ChangeCell(A, row - 1, column + 1, cnt) 
            || ChangeCell(A, row + 1, column + 1, cnt) 
            || ChangeCell(A, row + 1, column - 1, cnt);
        return Flag;
    } 

    if (row == 0 && column == 0){
        Flag = ChangeCell(A, row + 1, column, cnt) 
            || ChangeCell(A, row, column + 1, cnt) 
            || ChangeCell(A, row + 1, column + 1, cnt);
        return Flag;
    }
    if (row == 9 && column == 0) {
        Flag = ChangeCell(A, row - 1, column, cnt) 
            || ChangeCell(A, row, column + 1, cnt) 
            || ChangeCell(A, row - 1, column + 1, cnt);
        return Flag;
    }
    if (row == 0 && column == 9) {
        Flag = ChangeCell(A, row + 1, column, cnt) 
            || ChangeCell(A, row, column - 1, cnt) 
            || ChangeCell(A, row + 1, column - 1, cnt);
        return Flag;
    }
    if (row == 9 && column == 9) {
        Flag = ChangeCell(A, row - 1, column, cnt) 
            || ChangeCell(A, row, column - 1, cnt) 
            || ChangeCell(A, row - 1, column - 1, cnt);
        return Flag;
    }

    if (row == 0 && column > 0 && column < 9) {
        Flag = ChangeCell(A, row + 1, column, cnt) 
            || ChangeCell(A, row, column + 1, cnt) 
            || ChangeCell(A, row + 1, column + 1, cnt) 
            || ChangeCell(A, row, column - 1, cnt) 
            || ChangeCell(A, row + 1, column - 1, cnt);
        return Flag;
    }
    if (row > 0 && row < 9 && column == 0) {
        Flag = ChangeCell(A, row + 1, column, cnt) 
            || ChangeCell(A, row, column + 1, cnt) 
            || ChangeCell(A, row + 1, column + 1, cnt) 
            || ChangeCell(A, row - 1, column, cnt) 
            || ChangeCell(A, row - 1, column + 1, cnt);
        return Flag;
    }
    if (row == 9 && column > 0 && column < 9) {
        Flag = ChangeCell(A, row - 1, column, cnt) 
            || ChangeCell(A, row, column - 1, cnt) 
            || ChangeCell(A, row - 1, column - 1, cnt) 
            || ChangeCell(A, row, column + 1, cnt) 
            || ChangeCell(A, row - 1, column + 1, cnt);
        return Flag;
    }
    if (row > 0 && row < 9 && column == 9) {
        Flag = ChangeCell(A, row - 1, column, cnt) 
            || ChangeCell(A, row, column - 1, cnt) 
            || ChangeCell(A, row - 1, column - 1, cnt) 
            || ChangeCell(A, row + 1, column, cnt) 
            || ChangeCell(A, row + 1, column - 1, cnt);
        return Flag;
    }
}


int main()
{
    int A[10][10] = { 
        {1,1,0,0,0,0,0,0,1,1},
        {1,1,1,1,1,0,0,1,1,1},
        {0,1,1,1,1,0,0,1,1,0},
        {0,0,0,0,0,0,0,0,1,0},
        {0,0,1,1,1,1,1,0,0,0},
        {0,0,1,1,1,1,1,0,1,0},
        {0,0,1,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,0,0,0,0,0,1},
        {1,1,1,1,0,0,0,0,1,1} 
    };
    int cnt = 0, cntOfZeros = 0;
    bool Flag = true, Flag2 = true;
    int checkRow = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (A[i][j] == 1) {
                cnt++;
                A[i][j] = cnt + 1;

                for (int k = 0; k < 10; k++) {
                    for (int p = 0; p < 10; p++) {
                        if (CheckCell(A,k,p,cnt) && A[k][p] == 1) 
                            A[k][p] = cnt + 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "number of polygons: " << cnt;
}
