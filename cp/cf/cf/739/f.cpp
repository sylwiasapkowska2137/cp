#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)

vector<int>digits;
set<int>used;
int k;
int pref;

int count(int rem, bool equal){
	if (!rem) return pref;
	int tocheck = 0;
	int p = digits.size()-rem;
	rep(i, 0, 10){
		if (equal && i < digits[p]){ //nie chcemy dodac za malej liczby, gdy prefiks wciaz sie zgadza
			continue;
		}
		if (used.size() == k && used.find(i) == used.end()) { //nie mozemy dodac k+1-szej liczby
			continue;
		}
		if (tocheck>=2) { //nie oplaca nam sie sprawdzac wiecej niz dwóch najmniejszych liczb
			continue;
		}
		tocheck++;
		//ale to juz sprawdzamy
		pref *= 10; pref+=i;
		bool was = used.count(i);
		if (!was)used.insert(i);
		int res = count(rem-1, equal&&(i == digits[p]));
		if (!was) used.erase(i);
		pref/=10;
		if (res!=-1) return res;
	}
	return -1;
}

void solve(){
	LL n;
	cin >> n >> k;
	digits.clear();
	while (n){
		digits.pb(n%10);
		n/=10;
	}
	reverse(digits.begin(), digits.end());
	used.clear();pref = 0;
	int res = count(digits.size(), true);
	if (res == -1){
		cout << "1";
		rep(i, 0, digits.size())cout << "0";
		cout << "\n";
	} else cout << res << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}

