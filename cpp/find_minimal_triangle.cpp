#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#define DBL_MAX
using namespace std;

struct point
{
    int x, y, id;
};

bool cmp_x(const point& a1, const point& a2) {
    return a1.x < a2.x || a1.x == a2.x && a1.y < a2.y;
}

bool cmp_y(const point& a1, const point& a2) {
    return a1.y < a2.y;
}

int N;
point* a;
point* temp;
point nearest_pair[3];
double mindist = DBL_MAX;

void upd_id(const point& a1, const point& a2, const point& a3) {
    double dist1 = sqrt((a1.x - a2.x) * (a1.x - a2.x) + (a1.y - a2.y) * (a1.y - a2.y));
    double dist2 = sqrt((a2.x - a3.x) * (a2.x - a3.x) + (a2.y - a3.y) * (a2.y - a3.y));
    double dist3 = sqrt((a1.x - a3.x) * (a1.x - a3.x) + (a1.y - a3.y) * (a1.y - a3.y));
    if (dist1+dist2+dist3 < mindist) {
        mindist = dist1 + dist2 + dist3;
        nearest_pair[0] = a1;
        nearest_pair[1] = a2;
        nearest_pair[2] = a3;
    }
}

void rec(int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i <= r; ++i) {
            for (int j = i + 1; j <= r; ++j)
                for(int z = j+1; z<=r; ++z)
                    upd_id(a[i], a[j], a[z]);
        }
        sort(a + l, a + r + 1, &cmp_y);
        return;
    }


    int m = (l + r) >> 1;
    int midx = a[m].x;
    rec(l, m), rec(m + 1, r);

    merge(a + l, a + m + 1, a + m + 1, a + r + 1, temp, &cmp_y);

    copy(temp, temp + r - l + 1, a + l);

    int strip_size = 0;
    point* strip = new point[r - l + 1];

    for (int i = l; i <= r; ++i) {
        if (abs(a[i].x - midx) < mindist / 2.0) {
            strip[strip_size++] = a[i];
        }
    }

    for (int i = 0; i < strip_size; ++i) {
        for (int j = i + 1; j < strip_size; ++j) {
            if (strip[j].y - strip[i].y >= mindist / 2.0) 
                break;

            for (int k = j + 1; k < strip_size; ++k) {
                if (strip[k].y - strip[i].y >= mindist / 2.0) 
                    break;
                upd_id(strip[i], strip[j], strip[k]);
            }
        }
    }

    delete[] strip;
}

int main()
{
    srand(time(0));
    static int N = 100;
    a = new point[N];
    temp = new point[N];

    for (int i = 0; i < N; ++i) {
        a[i].x = rand() % 1000;
        a[i].y = rand() % 1000;
        a[i].id = i;
    }

    mindist = DBL_MAX;
    sort(a, a + N, cmp_x);
    rec(0, N - 1);

    cout <<fixed<< mindist;
    delete[] a; 
    delete[] temp;
}