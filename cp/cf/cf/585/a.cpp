#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	LL a1, a2, k1, k2, n;
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	LL mini = max(0LL, min(a1+a2, n-a1*(k1-1)-a2*(k2-1))), maxi = 0;
	if (k1 < k2){
		maxi += min(n/k1, a1);
		n-=(k1*maxi);
		maxi += min(n/k2, a2);
	} else {
		maxi = min(n/k2, a2);
		n-=(k2*maxi);
		maxi += min(n/k1, a1);
	}
	
	cout << mini << " " << min(a1+a2, maxi) << "\n";
	//LL maxi = 
	return 0;
}


