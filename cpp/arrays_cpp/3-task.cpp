// в интеренте посмотрел как сделать функцию, которая возвращаяет 2 значения
#include <iostream>
#include <utility>


using namespace std;

pair<int, int> lastNumber(int num) {
    return pair<int, int>(num % 10, num / 10);
}

int main()
{
    int num, A,B,C,D;
    for (int i = 1000; i <= 9999; i++) {
        num = i;
        auto p1 = lastNumber(num);
        A = p1.first;
        num = p1.second;

        auto p2 = lastNumber(num);
        B = p2.first;
        num = p2.second;;
        
        auto p3 = lastNumber(num);
        C = p3.first;
        num = p3.second;
        
        auto p4 = lastNumber(num);
        D = p4.first;
        num = p4.second;

        if (A != B && A != C && A != D && B != C && B != D && D != C)
            cout << i << endl;
    }
}
