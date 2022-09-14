#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define pii pair <int, int>
#define pb push_back
#define st first
#define nd second
#define debug(x) cerr << x << " "

vector <pii> ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s;
	int n, m, suma = 0, a;
	cin >> n >> m >> s;
	
	for (int i = 0; i<=2*n; i++) ans.pb({-1,-1});
	for (int i = 0; i<n; i++){
		if (s[i]=='T') suma+=2;
		else suma++;
	}
	int start = 0, koniec = n-1, sum = suma, one = -1, two = -1;
	while (sum > 0){
		ans[sum] = {start, koniec};
		if (s[start] == 'T')start++;
		else if (s[koniec] == 'T')koniec--;
		else {
			start++;
			koniec--;
		}
		sum -= 2;
	}

	for (int i = 0; i<n; i++){
		if (s[i]=='W'){
			one = i;
			break;
		}
	}
	for (int i = n-1; i>=0; i--){
		if (s[i] == 'W'){
			two = i;
			break;
		}
	}
	if (one < (n-1)-two){ //ucinamy poczatek
		start = one+1;
		koniec = n-1;
		sum = suma - 2*one - 1;
	} else { //ucinamy koniec
		koniec = two-1;
		start = 0;
		sum = suma - 2*(n-two-1) - 1;
	}
	while (sum > 0){
		ans[sum] = {start, koniec};
		if (s[start] == 'T')start++;
		else if (s[koniec] == 'T')koniec--;
		else {
			start++;
			koniec--;
		}
		sum -= 2;
	}
	//for (auto x: ans) cerr << x.st << " " << x.nd << "\n";
	while (m--){
		cin >> a;
		if (ans[a].st == -1 or ans[a].nd == -1) cout << "NIE\n";
		else cout << ans[a].st + 1 << " " << ans[a].nd +1 << "\n";
	}
	return 0;
}
