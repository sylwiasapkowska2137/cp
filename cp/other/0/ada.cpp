#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define debug(x) cerr << x << " "

const int MAX = 2e5+69, S = 900;
vector<int>tab, ans, last;
int freq[MAX], cnt, mo_time, L, R, T;
struct q { int l, r, t, i;};
struct u {int pos, prev, curr; };
vector<q> query;
vector<u> update;

bool mo_comparator(q a, q b){
	if (a.l/S == b.l/S) {
		if (a.r/S == b.r/S) return a.t < b.t;
		return a.r < b.r;
	} return a.l < b.l;	
}

void push(int v){
	//debug(v);
	freq[v]++;
	if (freq[v] == 1) cnt++;
	else if (freq[v] == 2) cnt--;
}

void pop(int v){
	//debug(v);
	freq[v]--;
	if (freq[v] == 1) cnt++;
	else if (freq[v] == 0) cnt--;
}

void update2(int t){
	if (L <= update[t].pos && update[t].pos <= R){
		pop(update[t].prev);
		tab[update[t].pos] = update[t].curr;
		push(update[t].curr);
	} else tab[update[t].pos] = update[t].curr;
}

void rollback(int t){
	if (L <= update[t].pos && update[t].pos <= R){
		pop(update[t].curr);
		tab[update[t].pos] = update[t].prev;
		push(update[t].prev);
	} else tab[update[t].pos] = update[t].prev;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, t, type, a, b, ile = 0;
	cnt = 0; mo_time = 0, L = 0, R = -1, T = 0;
	cin >> n >> t;
	tab.resize(n);
	last.resize(n);
	for (int i = 0; i<n; i++) {
		cin >> tab[i];
		last[i] = tab[i];
	}
	for (int i = 0; i<t; i++){
		cin >> type >> a >> b;
		if (type == 1){
			u upd;
			upd.pos = a;
			upd.prev = last[a];
			upd.curr = b;
			update.pb(upd);
			last[a] = b;
			mo_time++;
		} else {
			q que;
			que.i = ile;
			que.l = a;
			que.r = b;
			que.t = mo_time;
			query.pb(que);
			ile++;
		}
	}
	ans.assign(ile, -1);
	sort(query.begin(), query.end(), mo_comparator);
	for (auto x: query){
		//debug(x.l);
		//debug(x.r);
		//debug(x.t);
		//cerr << "\n";
		while (T < x.t) update2(T++);
		while (T > x.t) rollback(--T);
		while (R < x.r) push(tab[++R]);
		while (L > x.l) push(tab[L--]);
		while (R > x.r) pop(tab[R--]);
		while (L < x.l) pop(tab[++L]);
		ans[x.i] = cnt;
	}
	for (int i = 0; i<ile; i++) cout << ans[i] << "\n";
	return 0;
}
