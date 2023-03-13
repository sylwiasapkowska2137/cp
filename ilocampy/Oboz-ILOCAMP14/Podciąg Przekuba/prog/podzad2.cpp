#include <bits/stdc++.h>
using namespace std;

int k;
int n, m;
int w;

int tabn[2007];
int tabm[2007];

vector <short int> rzu;
vector <short int> dp[2007][4007];
vector <short int> z[2007][4007];

short int na[2007][2007];
short int nast[2007][2007];

int dos[2007];

int kol[2007];

int s=10000;

bool mniej(int a, int b)
{
	return nast[1][a]<nast[1][b];
}

inline int dn(int v)
{
	return min(v+1, n);
}

inline int dm(int v)
{
	return min(v+1, m);
}

int main()
{
	scanf("%d", &k);
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tabn[i]);
	scanf("%d", &m);
	for (int i=1; i<=m; i++)
		scanf("%d", &tabm[i]);
	w=(n+m+k)/k;
	rzu.resize(k+2, -1);
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=w+2; j++)
		{
			dp[i][j]=rzu;
			z[i][j]=rzu;
		}
	}
	for (int i=1; i<=k; i++)
		dp[0][1][i]=0;
	for (int i=1; i<=k; i++)
		nast[m+1][i]=m+1;
	for (int i=m; i; i--)
	{
		for (int j=1; j<=k; j++)
			nast[i][j]=nast[i+1][j];
		nast[i][tabm[i]]=i;
	}
	for (int i=1; i<=k; i++)
		na[n+1][i]=n+1;
	for (int i=n; i; i--)
	{
		for (int j=1; j<=k; j++)
			na[i][j]=na[i+1][j];
		na[i][tabn[i]]=i;
	}
	
	for (int i=1; i<=k; i++)
		kol[i]=i;
	
	for (int i=0; i<=n; i++)
	{
		for (int j=1; j<=w; j++)
		{
			for (int l=1; l<=k; l++)
			{
				if (dp[i][j][l]==-1)
					continue;
				dp[i][j][l]=nast[dp[i][j][l]+1][l]-1;
				if (na[i+1][l]!=i+1)
				{
					if (dp[i][j][l]>dp[i+1][j][l])
					{
						dp[i+1][j][l]=dp[i][j][l];
						z[i+1][j][l]=1;
					}
				}
				else
				{
					for (int zm=1; zm<=k; zm++)
					{
						if (i<n)
						{
							if (dm(dp[i][j][l])>dp[i+1][j+1][zm])
							{
								dp[i+1][j+1][zm]=dm(dp[i][j][l]);
								z[i+1][j+1][zm]=s+l;
							}
						}
						else
						{
							if (dm(dp[i][j][l])>dp[i][j+1][zm])
							{
								dp[i][j+1][zm]=dm(dp[i][j][l]);
								z[i][j+1][zm]=2*s+l;
							}
						}
					}
				}
			}
		}
	}
	for (int i=1; 1; i++)
	{
		int ok=0;
		for (int j=1; j<=k; j++)
			if (dp[n][i][j]==m)
				ok=j;
		if (!ok)
			continue;
		
		vector <int> wek;
		printf("%d\n", i);
		
		int vi=n;
		int vj=i;
		int vl=ok;
		
		while(vi)
		{
			if (z[vi][vj][vl]>=2*s)
			{
				wek.push_back(vl);
				vl=z[vi][vj][vl]-2*s;
				vj--;
				continue;
			}
			if (z[vi][vj][vl]>=s)
			{
				wek.push_back(vl);
				vl=z[vi][vj][vl]-s;
				vj--;
				vi--;
				continue;
			}
			vi--;
		}
		wek.push_back(vl);
		reverse(wek.begin(), wek.end());
		for (int j=0; j<i; j++)
			printf("%d ", wek[j]);
		printf("\n");
		break;
	}
	return 0;
}
