#include <iostream>
#include <utility>
#include <cstdlib>

using namespace std;




int main()
{
    int A[100], random;
    
    for (int i = 0; i < 100; i++) {
        random = rand() % 100;
        if (random % 2 == 0)
            A[i] = 0;
        else
            A[i] = random;
        cout << A[i] << ' ';
    }
    cout << endl;
    int maxLen = 0, cnt = 0;

    for (int i = 0; i < 100; i++) {
        if (A[i] == 0)
            cnt++;
        else
            cnt = 0;
        if (cnt > maxLen)
            maxLen = cnt;
    }
    cout << maxLen;
}
