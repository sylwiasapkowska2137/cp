#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define ULL unsigned LL
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

LL P1 = 59, P2 = 313, M1 = 1e9+7, M2 = 1e9+9;
struct A{
	LL h1, h2;
	int len;
};

bool cmp(A a, A b){
	if (a.len == b.len){
		if (a.h1 == b.h1) return (a.h2 < b.h2);
		return a.h1 < b.h1;
	}
	return a.len < b.len;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector <int> a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	vector <LL> hash1(n+1), hash2(n+1), hash3(n+2), hash4(n+2), pot1(n+1), pot2(n+1);
	hash1[0] = 0;
	hash2[0] = 0;
	pot1[0] = 1;
	pot2[0] = 1;
	for (int i = 1; i<=n; i++){
		pot1[i] = (pot1[i-1]*P1)%M1;
		pot2[i] = (pot2[i-1]*P2)%M2;
		hash1[i] = (hash1[i-1]+a[i]*pot1[i]+M1)%M1;
		hash2[i] = (hash2[i-1]+a[i]*pot2[i]+M2)%M2;
	}
	hash3[n+1] = 0;
	hash4[n+1] = 0;
	for (int i = n; i>=1; i--){
		hash3[i] = (hash3[i+1]+a[i]*pot1[n-i+1]+M1)%M1;
		hash4[i] = (hash4[i+1]+a[i]*pot2[n-i+1]+M2)%M2; 
	}
	vector <A> ans;
	for (int k = 1; k<=n; k++){
		cerr << k << "\n";
		for (int i = 1; i+k-1<=n; i+=k){
			int a1 = i;
			int b1 = i+k-1;
			LL s1 = (hash1[b1]-hash1[a1-1]+M1)%M1;
			s1 = (s1*pot1[n-b1])%M1;
			debug(s1);
			cerr << "\n";
		}
	}
	return 0;
}
