#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 1e5+7, K = 30;
const LL MOD = 1e9+7;
LL freq[MAX];
struct node{
	int syn[2] = {-1, -1};
	node() {}
};
vector<node>tab;

void add(int x){
	int v = 0;
	//debug(x);
	for (int i = K; i>=0; i--){
		bool a = x&(1<<i);
		if (tab[v].syn[a]==-1){//nie istnieje, to stwórzmy go :))
			tab[v].syn[a] = tab.size();
			node elem;
			tab.pb(elem);
		}
		v = tab[v].syn[a];
	}
}


int Find(int x){
	int v = 0;
	int res = 0;
	for (int i = K; i>=0; i--){
		res*=2;
		bool a = x&(1<<i);
		if (tab[v].syn[a] == -1){
			v = tab[v].syn[a^1];
			//cerr << (a^1);
			res += (a^1);
		} else {
			v = tab[v].syn[a];
			//cerr << a;
			res += a;
		}
	}
	//cerr << "\n";
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, b;
	cin >> n >> m;
	vector<int>a(n);
	freq[0] = 1;
	node elem;
	tab.pb(elem);
	for (int i = 0; i<n; i++){
		cin >> a[i];
		for (int j = 100000; j>=a[i]; j--){
			freq[j]+=freq[j-a[i]];
			freq[j] = freq[j]%MOD;
		}
	}
	//for (int i = 0; i<30; i++) debug(freq[i]);
	for (int i = 0; i<=100000; i++){
		if (freq[i]) add(i);
	}
	int tmp = 0;
	/*
	for (auto x: tab){
		debug(tmp);
		debug(x.syn[0]);
		debug(x.syn[1]);
		cerr << "\n";
		tmp++;
	}*/
	while (m--){
		cin >> b;
		int x = Find(b);
		cout << x << " " << freq[x] << "\n";
	}
	return 0;
}
