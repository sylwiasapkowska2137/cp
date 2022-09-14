#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pb push_back
#define st first
#define nd second
#define pii pair <int, int>
#define debug(x) cerr << x << " "

const LL MOD = 1e9+7;
priority_queue <int> q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, qu, s, ptr = 0;
	LL k, res = 0;
	cin >> n >> qu;
	vector <pair <int, LL> > query;
	vector <LL> tab(n);
	for (int i = 0; i<n; i++) cin >> tab[i];
	for (int i = 0; i<qu; i++){
		cin >> k >> s;
		query.pb({s-1, k});
	}
	sort(query.begin(), query.end());
	for (int i = 0; i<n; i++){
		while (query[ptr].st == i){
			q.push(query[ptr].nd);
			ptr++;
		}
		while (!q.empty() && q.top() >= (LL)tab[i]){
			int val = q.top();
			q.pop();
			res += (val/tab[i]);
			val %= tab[i];
			q.push(val);
		}
		res %= MOD;
		//cerr << "\n";
	}
	res %= MOD;
	cout << res << "\n";
	return 0;
}

