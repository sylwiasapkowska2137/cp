#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000007;

int Calc(long long x, map<long long, bool>&m, long long bound) {
	if(m[x] || bound == 0)
		return 0;
	int result = 1;
	if(x * 2 <= bound)
		result += Calc(x * 2, m, bound);
	if(x * 3 <= bound)
		result += Calc(x * 3, m, bound);
	m[x] = true;
	return result;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	map<long long, bool>m1, m2;
	
	int l, r; cin >> l >> r;
	int Left = Calc(1, m1, l - 1);
	int Right = Calc(1, m2, r);
	
	cout << Right - Left;
	
	return 0;
}


