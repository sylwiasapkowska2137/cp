#include <cstdio>
#include <iostream>

using namespace std;

int a, b, c, d;
bool res;

bool Solve(int a, int b, int c);

int main()
{
    scanf("%d %d %d %d", &a, &b, &c, &d);
    res |= Solve(a, b, c);
    res |= Solve(a, b, d);
    res |= Solve(a, c, d);
    res |= Solve(b, c, d);
    puts( res ? "TAK" : "NIE" );
}

bool Solve(int a, int b, int c)
{
    return (a + b > c && a + c > b && b + c > a);
}