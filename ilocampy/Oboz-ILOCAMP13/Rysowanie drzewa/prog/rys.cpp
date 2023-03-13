#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long double LD;

const int maxN = 1505;
const LD Eps = 1e-8;

inline bool IsZero(LD &x){
	return (x >= -Eps) && (x <= Eps);
}

vector<int> Adj[maxN];
int sizetree[maxN];
bool vis[maxN];

void dfs(int v){
	vis[v] = true;
	for(int i = 0; i < Adj[v].size(); i++){
		if(!vis[Adj[v][i]]){
			dfs(Adj[v][i]);
			sizetree[v] += sizetree[Adj[v][i]];
		}
	}
}

int n, a, b, minx;
LD xi[maxN], yi[maxN];
int wh;
int match[maxN], wsp[maxN];

bool sort_compare(int a, int b){
	LD t1 = atan2l(yi[a]-yi[wh], xi[a]-xi[wh]);
	LD t2 = atan2l(yi[b]-yi[wh], xi[b]-xi[wh]);
	//printf("compare(%d,%d); t1=%Lf, t2=%Lf, diff=%Lf\n", a, b, t1, t2, t1-t2);
	t1 -= t2;
	while(t1 < 0) t1 += M_PIl*2;
	while(t1 > M_PIl*2) t1 -= M_PIl*2;
	return (t1 > M_PIl);
}


void dfs_sort(int v, int by, int from, int to, int pnt){
	//printf("dfs_sort(v=%d, by=%d, wsp[by]=%d, from=%d, to=%d, pnt=%d)\n", v, by, wsp[by], from, to, pnt);
	
	if(from == to){
		match[wsp[by]] = v;
		return;
	}
	
	match[wsp[by]] = v;
	//printf("M");
	//for(int i = 1; i <= n; i++) printf("%d ", match[i]);
	//printf("\n");
	
	swap(wsp[from], wsp[by]);
	//for(int i = from; i <= to; i++) printf("%d ", wsp[i]);
	//printf("\n");
	
	wh = wsp[from];
	sort(wsp+from+1, wsp+to+1, sort_compare);
	//for(int i = from+1; i <= to; i++) printf("%d ", wsp[i]);
	//printf("\n");
	
	int apos = from+1;
	for(int i = 0; i < Adj[v].size(); i++){
		if(Adj[v][i] == pnt) continue;
		int s = sizetree[Adj[v][i]];
				
		dfs_sort(Adj[v][i], apos, apos, apos+s-1, v);
		apos += s;
	}
}


int main(){
	scanf("%d", &n);
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &a, &b);
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	//czytamy wspolrzedne, szukamy punktu o najmniejszym x
	minx = 1;
	for(int i = 1; i <= n; i++){
		scanf("%Lf%Lf", &xi[i], &yi[i]);
		if(xi[i] < xi[minx]) minx = i;
		
		wsp[i] = i; vis[i] = false; sizetree[i] = 1; match[i] = -1;
	}
	dfs(1);
	//for(int i = 1; i <= n; i++) printf("%d ", sizetree[i]);
	//printf("\n");
	
	dfs_sort(1, minx, 1, n, 1);
	
	for(int i = 1; i <= n; i++) printf("%d ", match[i]);
	printf("\n");
}

