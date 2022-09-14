#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

struct elem{
	int st, nd, index;
};

bool cmp(elem a, elem b) {return a.st < b.st;}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<elem>a(n+1);
	vector<LL>pref(n+1), lewo(n+1), prawo(n+1), x(n+1), y(n+1);
	for (int i = 1; i<=n; i++){
		cin >> a[i].st >> a[i].nd;
		a[i].index = i;
	}
	sort(a.begin(), a.end(), cmp);
	pref[0] = 0;
	for (int i = 1; i<=n; i++) pref[i] = pref[i-1]+a[i].st;
	prawo[1] = pref[n]-n*a[1].st;
	for (int i = 2; i<=n; i++) prawo[i] = prawo[i-1]-(n-i+1)*(a[i].st-a[i-1].st);
	//for (int i = 1; i<=n; i++) debug(prawo[i]);
	//cerr << "\n";
	lewo[1] = 0;
	for (int i = 2; i<=n; i++) lewo[i] = lewo[i-1] + (i-1) * (a[i].st-a[i-1].st);
	for (int i = 1; i<=n; i++) x[a[i].index] = prawo[i]+lewo[i];
	for (int i = 1; i<=n; i++) swap(a[i].st, a[i].nd);
	sort(a.begin(), a.end(), cmp);
	pref[0] = 0;
	for (int i = 1; i<=n; i++) pref[i] = pref[i-1]+a[i].st;
	prawo[1] = pref[n]-n*a[1].st;
	for (int i = 2; i<=n; i++) prawo[i] = prawo[i-1]-(n-i+1)*(a[i].st-a[i-1].st);
	lewo[1] = 0;
	for (int i = 2; i<=n; i++) lewo[i] = lewo[i-1] + (i-1) * (a[i].st-a[i-1].st);
	//cerr << "\n";
	for (int i = 1; i<=n; i++) y[a[i].index] = prawo[i]+lewo[i];
	//cerr << "\n";
	LL ans = 0LL;
	for (int i = 1; i<=n; i++) ans = max(ans, x[i]+y[i]);
	cout << ans << "\n";
	return 0;
}


