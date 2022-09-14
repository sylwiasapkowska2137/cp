#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int,int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 52;
const LL MOD = 1e9+7;
int n;
LL p1[MAX][MAX], pw[MAX][MAX], pp[MAX][MAX];

void kwadrat(){
	for (int i = 1; i<=n; i++) for (int j = 1; j<=n; j++) pp[i][j] = 0;
	
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			for (int k = 1; k<=n; k++){
				pp[i][j] += p1[i][k]*p1[k][j];
				if (pp[i][j]>=MOD) pp[i][j]%=MOD;
			}
		}
	}
	
	for (int i = 1; i<=n; i++) for (int j = 1; j<=n; j++) p1[i][j] = pp[i][j];
}

void wymnoz(){
	for (int i = 1; i<=n; i++) for (int j = 1; j<=n; j++) pp[i][j] = 0;
	
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			for (int k = 1; k<=n; k++){
				pp[i][j] += pw[i][k]*p1[k][j];
				if (pp[i][j]>=MOD) pp[i][j]%=MOD;
			}
		}
	}
	
	for (int i = 1; i<=n; i++) for (int j = 1; j<=n; j++) pw[i][j] = pp[i][j];
}


void power(LL w){
	for (int i = 1; i<=n; i++) for (int j = 1; j<=n; j++) pw[i][j] = (i==j);
	while (w){
		if (w&1) wymnoz();
		kwadrat();
		w/=2;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	LL k;
	cin >> n >> k;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++) cin >> p1[i][j];
	}
	power(k);
	LL ans = 0LL;
	//cerr << "\n";
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			ans += pw[i][j];
			if (ans >= MOD) ans%=MOD;
			//debug(pw[i][j]);
		}
		//cerr << "\n";
	}
	cout << ans << "\n";
	return 0;
}
