#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

int dp[11][10][100];

void init(){
	for (int i = 0; i<10; i++) dp[1][i][i] = 1;
	
}


bool binsearch(int start, int koniec, int x){
	while (koniec-start>1){
		int m = (start+koniec)/2;
		if (f(x, m) <= m) start = m;
		else koniec = m-1;
	}
	return start;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, res = 0;
	cin >> n;
	for (int suma = 1; suma<100; suma++){
		int l = less(suma)+1;
		int r = less(suma+1);
		if (binsearch(l, r)) res++;
	}
	cout << res << "\n";
	return 0;
}
