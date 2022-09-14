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

void solve(){
	string s, del;
	cin >> s;
	int n = s.size(), ans = 0, end = 0;
	vector<int>freq(30, 0), occ(30, 0), used(30, 0);
	rep(i, 0, n) freq[s[i]-'a']++;
	rep(i, 0, 30) if (freq[i]) ans++;
	int indeks = n-1;
	while (ans){
		while (used[s[indeks]-'a'] && indeks>0) indeks--;
		del+=s[indeks];
		used[s[indeks]-'a'] = 1;
		int ile = freq[s[indeks]-'a']/ans;
		if (freq[s[indeks]-'a']%ans != 0 || ile == 0){
			cout << "-1\n";
			return;
		}
		occ[s[indeks]-'a'] = ile;
		while (ile && indeks>=0){
			if (s[indeks]==del[del.size()-1]) ile--;
			indeks--;
		}
		ans--;
	}
	reverse(del.begin(), del.end());
	rep(i, 0, 30){
		int j = 0;
		while (j < n && occ[i]>0){
			if (s[j] == i+'a') occ[i]--;
			j++;
		}
		end = max(end, j);
	}
	string a, b, c;
	rep(i, 0, end) a+=s[i];
	rep(i, 0, del.size()){
		c+=a;
		b.clear();
		rep(j, 0, a.size()){
			if (a[j] == del[i]) continue;
			b+=a[j];
		}
		swap(a, b);
	}
	if (s.size()!=c.size()){
		cout << "-1\n";
		return;
	}
	rep(i, 0, n){
		if(s[i]!=c[i]){
			cout << "-1\n";
			return;
		}
	}
	rep(i, 0, end) cout << s[i];
	cout << " " << del << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
