#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "
#define LL long long
#define pb push_back

const int MAX = 1e6+7;
vector <int> graf[MAX];
int rep[MAX], ile[MAX];
LL res = 0LL;

int Find(int a){
	if (a == rep[a]) return a;
	rep[a] = Find(rep[a]);
	return rep[a];
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a != b) {
		rep[b] = a;
		ile[a]+=ile[b];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, a, b;
	cin >> n;
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	for (int i = 1; i<=n; i++){
		rep[i] = i;
		ile[i] = 1;
	}
	for (int i = 1; i<=n; i++){
		for (auto x: graf[i]){
			if (x < i) Union(i, x); //wieksza, mniejsza
		}
		res+=ile[i];
		//for (int i = 1; i<=n; i++)debug(ile[i]);
		//cerr << "\n";
	}
	cout << res;
	return 0;
}
