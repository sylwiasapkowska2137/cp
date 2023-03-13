#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXABC = 1000000 + 7;
const int MAXN = 500000 + 7;
const int INF = 1000000000 + 7;

int n;
int lowestCnt, mediumCnt, highestCnt, sameCnt;
int lowest = -INF, medium = -INF, highest = -INF;

vector <int> Res;
vector <int> V[MAXN];

bool SolveMedium(int);
bool SolveLowest(int);

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
        if(medium == V[i][1]) mediumCnt++;
        else if(medium < V[i][1])
        {
            medium = V[i][1];
            mediumCnt = 1;
        }
        
        if(lowest == V[i][2])
        {
            lowest++;
            sameCnt += (V[i][1] == V[i][2]);
        }
        else if(lowest < V[i][2])
        {
            lowest = V[i][2];
            lowestCnt = 1;
            sameCnt = (V[i][1] == V[i][2]);
            if(highest == V[i][0]) highestCnt++;
            else if(highest < V[i][0])
            {
                highest = V[i][0];
                highestCnt = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if( SolveMedium(i) && SolveLowest(i) ) Res.push_back(i); 
    }
    printf("%d\n", (int)Res.size());
    for(int i = 0; i < Res.size(); i++)
    {
        printf("%d ", Res[i]);
    }
}

bool SolveMedium(int i)
{
    if(V[i][0] > medium) return true;
    if(V[i][0] < medium) return false;
    
    return (mediumCnt == 1 && V[i][1] == medium) ? true : false;
}

bool SolveLowest(int i)
{
    if(V[i][1] > lowest) return true;
    if(V[i][1] < lowest) return false;
    
    if(lowestCnt == sameCnt && V[i][1] == V[i][0])
    {
        if(highest < V[i][0]) return true;
        if(highest > V[i][0]) return false;
        
        return (highestCnt == 1) ? true : false;
    }
    
    return false;
}