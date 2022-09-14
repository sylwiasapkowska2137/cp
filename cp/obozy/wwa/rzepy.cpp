#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define pii pair<int,int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

vector<int>tab;
vector<LL>pref, power(50);
int n, A, B;
LL wynik;
const int MAX = 107, S = 2007, INF = 1e9+7;
bool dp[MAX][MAX];
int DP[S];

bool check(int bit){
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++) dp[i][j] = 0;
	}
	dp[0][0] = 1;
	for (int a = 1; a<=n; a++){
		for (int b = a; b<=n; b++){
			LL suma = pref[b]-pref[a-1];
			if ((suma&wynik)==suma){
				for (int j = 1; j<=n; j++){
					dp[b][j] |= dp[a-1][j-1];
				}
			}
		}
	}	
	bool ans = 0;
	for (int i = A; i<=B; i++) ans|=dp[n][i];
	return ans;
}

bool check2(){
	for (int i = 1; i<=n; i++) DP[i] = INF;
	DP[0] = 0;
	for (int a = 1; a<=n; a++){
		for (int b = a; b<=n; b++){
			LL suma = pref[b]-pref[a-1];
			if ((suma&wynik)==suma) DP[b] = min(DP[b], DP[a-1]+1);
		}
	}
	//debug(wynik);
	//cerr << "\n";
	//for (int i = 1; i<=n; i++) debug(DP[i]);
	//cerr << "\n";
	return (DP[n]<=B);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> A >> B;
	
	
	tab.resize(n+1);
	pref.resize(n+1);
	pref[0] = 0;
	power[0] = 1;
	for (int i = 1; i<=45; i++)	power[i] = power[i-1]*(LL)2;
	for (int i = 1; i<=n; i++) {
		cin >> tab[i];
		pref[i] = pref[i-1]+(LL)tab[i];
	}
	
	if (n <= 100){
		wynik = power[43]-1;
		for (int bit = 42; bit>=0; bit--){
			wynik-=power[bit];
			if (!check(bit)) wynik+=power[bit];
		}
		cout << wynik << "\n";
	} else {
		wynik = power[43]-1;
		for (int bit = 42; bit>=0; bit--){
			wynik-=power[bit];
			if (!check2()) wynik+=power[bit];
		}
		cout << wynik << "\n";
		
	}	
	return 0;
}
