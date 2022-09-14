#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

vector<int>a, zero;

LL solve(int l, int r){
	LL pos = 1, neg = 0;
	for (int i = l; i<=r; i++){
		a[i]*=a[i-1];
		if (a[i] == 1) pos++;
		else neg++;
	}
	LL ans = pos*neg;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	LL n, x;
	cin >> n;
	a.resize(n+2);
	a[0] = 1;
	a[n+1] = 1;
	zero.pb(0);
	for (int i = 1; i<=n; i++){
		cin >> x;
		if (x > 0) a[i] = 1;
		else if (x < 0) a[i] = -1;
		else {
			a[i] = 1;
			zero.pb(i);
		}
	}
	zero.pb(n+1);
	//cerr << "\n";
	LL neg = 0LL, pos = 0LL;
	for (int i = 1; i<(int)zero.size(); i++){
		//debug(zero[i-1]+1);
		//debug(zero[i]-1);
		//cerr << "\n";
		int l = zero[i-1]+1;
		int r = zero[i]-1;
		LL x = solve(l, r);
		LL len = r-l+1;
		len = (len*(len+1));
		len/=2;
		pos += (len-x);
		neg += x;

	}
	LL all = n*(n+1)/2;
	all = all-neg-pos;
	cout << neg << " " << all << " " << pos << "\n";
	return 0;
}



