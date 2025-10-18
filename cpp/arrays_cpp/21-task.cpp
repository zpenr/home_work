#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    int A[] = {1,3,4,6,1,23,6,6,32,1,12,4,5,6,1,23};
    int lenOfA = sizeof(A) / sizeof(A[0]);
    sort(A,A+lenOfA);
    int median = (lenOfA - 1) / 2;
    cout << "Index: " <<median<< "\tNumner: "<<A[median];
    return 0;
}
