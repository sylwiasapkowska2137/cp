#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define debug(x) cerr << x << " "
#define pii pair<int,int>
#define st first
#define nd second
#define pb push_back

bool ok(LL a, LL b, LL c, LL d, LL x, LL y){
	if (a == c && b == d) return 1;
	LL n = d-b+1;
	LL m = c-a+1;
	//debug(n);
	//debug(m);
	LL wyzej = x-a;
	LL nizej = c-x;
	LL lewo = y-b;
	LL prawo = d-y;
	/*
	debug(a);
	debug(b);
	debug(c);
	debug(d);
	cerr << "\n";
	debug(wyzej);
	debug(nizej);
	debug(lewo);
	debug(prawo);
	cerr << "\n";
	cerr << "\n";*/
	bool ans = 0;
	if (wyzej){
		if ((double)wyzej/(double)m == 0.75) {
			//debug("a");
			ans |= ok(x, b, c, d, x, y);
		}
	}
	if (nizej){
		if ((double)nizej/(double)n == 0.75) {
			//debug("b");
			ans |= ok(a, b, x, d, x, y);
		}
	}
	if (lewo){
		if ((double)lewo/(double)n == 0.75) {
			//debug("c");
			ans |= ok(a, y, c, d, x, y);
		}
	}
	if (prawo){
		if ((double)prawo/(double)n == 0.75) {
			//debug("d");
			ans |= ok(a, b, c, y, x, y);
			
			
		}
	}
	return ans;
}

void solve(){
	LL n, m, x, y;
	cin >> n >> m >> x >> y;
	x++;
	y++;
	if (ok(1, 1, n, m, x, y)) cout << "Tak\n";
	else cout << "Nie\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}
