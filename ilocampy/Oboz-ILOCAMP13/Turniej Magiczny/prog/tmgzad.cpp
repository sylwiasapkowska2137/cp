#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXABC = 1000000 + 7;
const int MAXN = 500000 + 7;
const int INF = 1000000000 + 7;

int n;
int medium, medium1Cnt, medium2Cnt, dGood, lowestCnt, highestCnt, lowestSame;
int lowest = -INF, highest = -INF;


vector <int> Res;
vector <int> V[MAXN];

bool SolveWin(int);
bool SolveDraw(int);

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            V[i].push_back(0);
            scanf("%d", &V[i][j]);
        }
        sort(V[i].rbegin(), V[i].rend());
        medium = max(medium, V[i][1]);
        lowest = max(lowest, V[i][2]);
    }
    for(int i = 1; i <= n; i++)
    {
        if(V[i][1] == medium) medium1Cnt++;
        if(V[i][1] == V[i][2] && V[i][2] == lowest)
        {
            lowestSame++;
            if(V[i][0] > highest)
            {
                highest = V[i][0];
                highestCnt = 0;
            }
            if(V[i][0] == highest)
            {
                highestCnt++;
            }
        }
        dGood += ( V[i][0] == medium && V[i][1] == medium && V[i][2] != medium );
        if(V[i][2] == lowest)
        {
            lowestCnt++;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if( V[i][0] == medium && medium1Cnt - (V[i][1] == medium) != 0 )
        {
            if( SolveDraw(i) ) Res.push_back(i); 
        }
        else if( V[i][0] > medium || medium1Cnt - (V[i][1] == medium) == 0 )
        {
            if( SolveWin(i) ) Res.push_back(i); 
        }
    }
    printf("%d\n", (int)Res.size());
    for(int i = 0; i < Res.size(); i++)
    {
        printf("%d ", Res[i]);
    }
}

bool SolveWin(int x)
{
    if( V[x][1] > lowest ) return true;
    if( V[x][1] < lowest ) return false;
    
    if( lowestCnt - (V[x][2] == lowest)  == 0 ) return true;
    else if( V[x][1] == V[x][2] && lowestSame == lowestCnt)
    {
        if(highestCnt - (V[x][0] == highest) == 0 ) return true;
        return false;
    }
    return false;
}

bool SolveDraw(int x)
{
    return ( V[x][0] == V[x][1] && V[x][1] == V[x][2] && medium1Cnt == dGood + 1);
}