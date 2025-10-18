#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;
int main()
{
    int n, ptr=0, left=0, right=0, top=0, bottom=0;
    cout << "Enter n ";
    cin >> n;
    
    int* A = new int[n*n];

    int** spiral = new int* [n];
    for (int i = 0; i < n; i++) 
        spiral[i] = new int[n];
  
    for (int i = 0; i < n * n ; i++) {
        A[i]= rand()%100;
    }

    sort(A,A+n*n);
    
    
    while (ptr != n * n) {
        for (int i = left; i < n - right && ptr != n * n; i++) {
            spiral[top][i] = A[ptr++];
        }
        
        top++;
        for (int i = top; i < n - bottom && ptr != n * n; i++) {
            spiral[i][n - right-1] = A[ptr++];
        }
        
        right++;
        for (int i = n-right-1; i >= left && ptr != n * n; i--) {
            spiral[n-bottom-1][i] = A[ptr++];
        }
      
        bottom++;
        for (int i = n-bottom-1; i >= top && ptr != n * n; i--) {
            spiral[i][left] = A[ptr++];
        }
        
        left++;
    }
    cout << "Spiral Matrix:"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << spiral[i][j] << '\t';
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        delete[] spiral[i];
    delete[] spiral;
    delete[] A;
    return 0;
}
