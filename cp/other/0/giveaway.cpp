#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int S = 710, MAX = 1e5+2137;
vector<int>tab;
vector<int>blocks[S];
int sq;

void binsearch(int blok, int val, int nowy){
	int start = 0, koniec = blocks[blok].size()-1;
	while (start <= koniec){
		int m = (start+koniec)/2;
		if (blocks[blok][m] == val){
			blocks[blok][m] = nowy;
			return;
		} else if (blocks[blok][m]>val)	koniec = m-1;
		else start = m+1;
	}
}

void update(){
	int a, b;
	cin >> a >> b;
	int num = (a-1)/sq;
	binsearch(num, tab[a-1], b);
	tab[a-1] = b;
	sort(blocks[num].begin(), blocks[num].end());
}

void query(){
	int a, b, c;
	cin >> a >> b >> c;
	a--;b--;
	int ans = 0, left = a/sq, right = b/sq;
 	if (left == right){
		for (int i = a; i<=b; i++) if (tab[i]>=c) ans++;
	} else {
		if (a%sq!=0) left++;
		int i;
		for (i = a; i<left*sq; i++) if (tab[i]>=c) ans++;
		while(i+sq-1<b){
			int num = i/sq;
			ans+= blocks[num].end()-lower_bound(blocks[num].begin(), blocks[num].end(), c);
			i+=sq;
		}
		while (i<=b) {
			if(tab[i]>=c) ans++;
			i++;
		}
	}
	cout << ans << "\n";	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q, type;
	cin >> n;
	sq = sqrt(n);
	tab.resize(n);
	for (int i = 0; i<n; i++) {
		cin >> tab[i];
		blocks[i/sq].pb(tab[i]);
	}
	cin >> q;
	int cnt = ceil((double)n/sq);
	for (int i = 0; i<=cnt; i++) sort(blocks[i].begin(), blocks[i].end());
	while(q--){
		cin >> type;
		if (type) update();
		else query();
	}
	return 0;
}
