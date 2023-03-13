// JK
#include <cstdio>

const int N = 20, K = N * N * N * 3;
int adj[N];
int path[K+1][N];
int pMod[N][N][N+1];
int pCycle[N][N][N+1];
char ans[2500000];

typedef unsigned long long ull;

ull S, A, B;
ull rand()
{
    S = S * A + B;
    return S;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    while(m--)
    {
	int u, v;
	scanf("%d %d", &u, &v);
	adj[u] |= (1 << v);
    }
    int k = n * n * n * 3;
    for(int i = 0; i < n; i++)
	path[0][i] |= 1 << i;
    for(int i = 0; i < k; i++)
	for(int u = 0; u < n; u++)
	{
	    for(int v = 0; v < n; v++)
		if(path[i][u] & (1 << v))
		    path[i+1][u] |= adj[v];
	    for(int mod = 1; mod <= n; mod++)
		pMod[i%mod][u][mod] |= path[i][u];
	}
    for(int u = 0; u < n; u++)
	for(int c = 1; c <= n; c++)
	    if(path[c][u] & (1 << u))
	    {
		for(int v = 0; v < n; v++)
		    for(int a = 0; a < c; a++)
			if(pMod[a][v][c] & (1 << u))
			    for(int b = 0; b < c; b++)
				pCycle[(a+b)%c][v][c] |= pMod[b][u][c];
	    }
    
    int q;
    ull L;
    scanf("%d %llu %llu %llu %llu", &q, &S, &A, &B, &L);
    for(int i = 0; i < q; i++)
    {
	int u = rand() % n, v = rand() % n;
	ull d = rand() % L;
	bool tak = false;
	if(d <= k)
	    tak = path[d][u] & (1 << v);
	else
	{
	    for(int j = 1; j <= n; j++)
		if(pCycle[d % j][u][j] & (1 << v))
		{
		    tak = true;
		    break;
		}
	}
	if(tak)
	{
	    int bit = q - i - 1;
	    ans[bit / 4] |= 1 << (bit % 4);
	}
    }
    bool nonZero = false;
    for(int i = (q - 1) / 4; i >= 0; i--)
	if(ans[i] || nonZero)
	{
	    nonZero = true;
	    printf("%x", (int)ans[i]);
	}
    puts("");
}
