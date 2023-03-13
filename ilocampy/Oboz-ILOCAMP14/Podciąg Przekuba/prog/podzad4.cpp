#include <bits/stdc++.h>
using namespace std;

int k;
int n, m;
int w;

int tabn[2007];
int tabm[2007];

vector <short int> rzu;
short int dp[20000007];
short int z[20000007];

short int nast[2007][2007];

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

inline short int& dpp(int i, int j, int l)
{
	j--;
	l--;
	return dp[i*(w+1)*(k+1)+j*(k+1)+l];
}

inline short int& zz(int i, int j, int l)
{
	j--;
	l--;
	return z[i*(w+1)*(k+1)+j*(k+1)+l];
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
	w=min((n+m+k)/k, max(n, m)+1);
	for (int i=0; i<=n; i++)
		for (int j=1; j<=w; j++)
			for (int l=1; l<=k; l++)
				dpp(i, j, l)=zz(i, j, l)=-1;
	for (int i=1; i<=k; i++)
		dpp(0, 1, i)=0;
	for (int i=1; i<=k; i++)
		nast[m+1][i]=m+1;
	for (int i=m; i; i--)
	{
		for (int j=1; j<=k; j++)
			nast[i][j]=nast[i+1][j];
		nast[i][tabm[i]]=i;
	}
	
	for (int i=0; i<=n; i++)
	{
		for (int j=1; j<=w; j++)
		{
			for (int l=1; l<=k; l++)
			{
				if (dpp(i, j, l)==-1)
					continue;
				dpp(i, j, l)=nast[dpp(i, j, l)+1][l]-1;
				if (tabn[i+1]!=l && i!=n)
				{
					if (dpp(i, j, l)>dpp(i+1, j, l))
					{
						dpp(i+1, j, l)=dpp(i, j, l);
						zz(i+1, j, l)=1;
					}
				}
				else
				{
					for (int zm=1; zm<=k; zm++)
					{
						if (i<n)
						{
							if (dm(dpp(i, j, l))>dpp(i+1, j+1, zm))
							{
								dpp(i+1, j+1, zm)=dm(dpp(i, j, l));
								zz(i+1, j+1, zm)=s+l;
							}
						}
						else
						{
							if (dm(dpp(i, j, l))>dpp(i, j+1, zm))
							{
								dpp(i, j+1, zm)=dm(dpp(i, j, l));
								zz(i, j+1, zm)=2*s+l;
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
			if (dpp(n, i, j)==m)
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
			//printf("w [%d][%d][%d][%d]  jest %d\n", vi, vj, vl, (int)dp[vi][vj][vl], z[vi][vj][vl]);
			if (zz(vi, vj, vl)>=2*s)
			{
				wek.push_back(vl);
				vl=zz(vi, vj, vl)-2*s;
				vj--;
				continue;
			}
			if (zz(vi, vj, vl)>=s)
			{
				wek.push_back(vl);
				vl=zz(vi, vj, vl)-s;
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
