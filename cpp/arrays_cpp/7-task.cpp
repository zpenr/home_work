#include <iostream>
#include <climits>
#include <cstdlib>


using namespace std;

int main()
{
    int m, n;
    cout << "Enter m and n: ";
    cin >> m >> n;
    int** A = new int* [m];

    for (int i = 0; i < m; i++) {
        A[i] = new int[n];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 100;
        }
    }
    int* MinInRow = new int[m];
    int* MaxInColumn = new int[n];
    
    int min=INT_MAX;
    int max=INT_MIN;

    for (int i = 0; i < m; i++) {
        min = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (A[i][j] < min)
                min = A[i][j];
        }
        MinInRow[i] = min;
    }

    for (int i = 0; i < n; i++) {
        max = INT_MIN;
        for (int j = 0; j < m; j++) {
            if (A[j][i] > max)
                max = A[j][i];
        }
        MaxInColumn[i] = max;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    bool Flag = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == MinInRow[i] && A[i][j] == MaxInColumn[j]) {
                Flag = false;
                cout << "Row: "<<i+1<<'\t' << "Column:" << j+1 << endl;
            }
        }
    }
    if (Flag)
        cout << '0';
}
