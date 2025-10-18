#include <iostream>

using namespace std;
int main()
{
    int M[] = { 1,0,0,1,1,1,1,1 };
    int lenOfM = sizeof(M) / sizeof(M[0])-1;
    if (M[lenOfM] == 0) {
        M[lenOfM] = 1;
        for (int i = 0; i <= lenOfM; i++) {
            cout << M[i];
        }
        
        return 1;
    }

    for (int i = lenOfM; i >= 0; i--) {
        if (M[i]==1) {
            M[i] = 0;
        }
        else {
            M[i] = 1;
            for (int j = 0; j <= lenOfM; j++) {
                cout << M[j];
            }
            
            return 0;
        }
    }
}
