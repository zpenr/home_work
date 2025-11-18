#include <iostream>

using namespace std;
int main(void) {
	float n = 2.5;
	
	int p = *((int*)&n);
	int exp = ((p&0x7F800000)>>23)-127;
	int matisa = (p & 0x7FFFFF) | 0x800000;
	cout << "exp: " << exp << endl;
	cout << "matisa: " << matisa << endl;
	
    return 0;
}