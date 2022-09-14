#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "

const int MAX = 5e5+7;
const LL POT1 = 313, MOD1 = 1e9+7;
//, POT2 = 269, MOD2 = 1e9+9;
int z[MAX], start[MAX];
LL hash1[MAX], pot1[MAX], ans[MAX];

bool warunek(int m, int p){
	int r = start[m]+m-1;
	int len = m-p;
	LL hl1 = (hash1[start[m]+len-1]-hash1[start[m]-1]*pot1[len])%MOD1;
	//LL hl2 = (hash2[l+len-1]-hash2[l-1]*pot2[len])%MOD2;
	LL hr1 = (hash1[r]-hash1[r-len]*pot1[len])%MOD1;
	//LL hr2 = (hash2[r]-hash2[r-len]*pot2[len])%MOD2;
	hl1 = (hl1+MOD1)%MOD1;
	hr1 = (hr1+MOD1)%MOD1;
	//if (hl1 == hr1 && hl2 == hr2) return 1;
	if (hl1 == hr1) return 1;
	return 0;
}

int binsracz(int start, int koniec, int p){
	int ans = start, m;
	while (start <= koniec) {
		m = (start+koniec) / 2;
		if (warunek(m, p)) {
			start = m+1;
			ans = m;
		} else 	koniec = m - 1;
	} return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, val;
	char c;
	string s;
	cin >> n;
	
	for (int i = 1; i<=n; i++){
		cin >> z[i] >> c;
		if (z[i] == 1) s += c;
		else s = c+s;
	}
	s = "#"+s;
	start[n] = 1;
	for (int i = n-1; i>0; i--){
		start[i] = start[i+1];
		if (z[i+1] == 2) start[i]++;
	}
	pot1[0] = 1;
	for (int i = 1; i<=n; i++){ 
		pot1[i] = (pot1[i-1]*POT1)%MOD1;
		//pot2[i] = (pot2[i-1]*POT2)%MOD2;
		//pot1[i] = (pot1[i]+MOD1)%MOD1;
		//pot2[i] = (pot2[i]+MOD2)%MOD2;
		hash1[i] = ((POT1 * hash1[i-1])+s[i]+MOD1)%MOD1;
		//hash2[i] = ((POT2 * hash2[i-1])+s[i]+MOD2)%MOD2;
		//hash1[i] = (hash1[i]+MOD1)%MOD1;
		//hash2[i] = (hash2[i]+MOD2)%MOD2;
	}
	for (int i = 1; i<=n; i++){
		val = binsracz(i, n, i);
		ans[i]++;
		ans[val+1]--;
	}
	for (int i = 1; i<=n; i++){
		ans[i] += ans[i-1];
		cout << ans[i] << "\n";
	}
	return 0;
}
