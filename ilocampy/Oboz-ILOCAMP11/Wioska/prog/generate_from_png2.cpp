// Przemysław Jakub Kozłowski
// g++ lodepng.cpp generate_from_png.cpp -o generate_from_png
#include "lodepng.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#define FI first
#define SE second
#define MP make_pair
using namespace std;

vector<unsigned char> image;
unsigned width, height;
inline int init(const char *name) {lodepng::decode(image, width, height, name);};
inline int get(int y, int x, int bajt) {return image[(4*((y-1)*width+x-1)+bajt-1)];}

inline int R(int a, int b) {return a+rand()%(b-a+1);}
inline int check(int a, int b)
{
    if(!(1 <= a && a <= height && 1 <= b && b <= width)) return 100;
    if(get(a,b,1) == 255 && get(a,b,2) == 0 && get(a,b,3) == 0) return 1;
    else if(get(a,b,1) == 0 && get(a,b,2) == 0 && get(a,b,3) == 0) return 2;
    else return 10;
}

const pair<int,int> A = MP(1,10000);
const pair<int,int> B = MP(100000000, 1000000000);

int main(int argc, char **argv)
{
    srand(12345);
    init(argv[1]);
    assert(0 < height);
    assert(height == width);

    int n = height;
    int wiox = 0, wioy = 0;

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            if(check(i,j) == 1)
            {
                assert(wiox == 0);
                wiox = j;
                wioy = i;
            }
    assert(wiox != 0 && wioy != 0);

    printf("%d\n", n);
    printf("%d %d\n", wiox, wioy);

    for(int i = 1;i <= n+1;i++)
        for(int j = 1;j <= n;j++)
        {
            int waga = 0;
            if(check(i, j) == 2 || check(i-1, j) == 2)
                waga = R(A.FI, A.SE);
            else
                waga = R(B.FI, B.SE);
            printf("%d", waga);
            if(j != n) printf(" ");
            else printf("\n");
        }

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n+1;j++)
        {
            int waga = 0;
            if(check(i,j) == 2 || check(i, j-1) == 2)
                waga = R(A.FI, A.SE);
            else
                waga = R(B.FI, B.SE);
            printf("%d", waga);
            if(j != n+1) printf(" ");
            else printf("\n");
        }

    return 0;
}
