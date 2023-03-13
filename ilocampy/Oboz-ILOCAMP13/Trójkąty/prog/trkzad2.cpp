#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, d;
bool res;

vector <int> V;

bool Solve(int a, int b, int c);

int main()
{
    for(int i = 0; i < 4; i++)
    {
        V.push_back(0);
        scanf("%d", &V[i]);
    }
    sort(V.begin(), V.end());
    res |= Solve(V[0], V[1], V[2]);
    res |= Solve(V[1], V[2], V[3]);
    puts( res ? "TAK" : "NIE" );
}

bool Solve(int a, int b, int c)
{
    return (a + b > c && a + c > b && b + c > a);
}