#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pii pair<int, int>
#define pb push_back
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 1e6+7;
int tab[MAX], freq[MAX], cnt, a[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, val, ans = 0;
	LL suma = 0LL;
	cin >> n >> m;
	cnt = n-m;
	vector <int> arr(m);
	for (int i = 0; i<m; i++){
		cin >> arr[i];
		suma+=(LL)arr[i];
		if (suma > (LL)n){
			cout << 0;
			return 0;
		}
	}
	for (int i = 0; i<m; i++){
		cin >> val;
		tab[val] = arr[i];
	}
	for (int i = 0; i<suma; i++){
		cin >> a[i];
		freq[a[i]]++;
		if (freq[a[i]]-1 == tab[a[i]]) cnt--;
		if (freq[a[i]] == tab[a[i]]) cnt++;
	}
	if (cnt == n) ans++;
	for (int i = suma; i<n; i++){
		cin >> a[i];
		freq[a[i-suma]]--;
		if (freq[a[i-suma]] == tab[a[i-suma]]) cnt++;
		if (freq[a[i-suma]]+1 == tab[a[i-suma]]) cnt--;
		freq[a[i]]++;
		if (freq[a[i]]-1 == tab[a[i]]) cnt--;
		if (freq[a[i]] == tab[a[i]]) cnt++;
		if (cnt == n) ans++;
	}
	cout << ans;
	return 0;
}
/*
7 1                                                  
2 
4 
3 3 1 4 4 6 6
*/
