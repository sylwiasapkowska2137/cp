#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pb push_back
#define st first
#define nd second
#define pii pair<int, int>

vector<int>liczby, pierwsze;
const int MAX = 16666670;
const LL N = 1e9;
vector<bool>prime(MAX, 1);

void sito(){
	prime[0] = prime[1] = 0;
	for (int i = 2; i<MAX; i++){
		if (prime[i] && (LL)i*i < MAX){
			pierwsze.pb(i);
			for (int j = i*i; j<MAX; j+=i) prime[j] = 0;
		}
	}
}

int cyfry(LL x){
	int ans = 0;
	while (x){
		ans++;
		x/=10;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	sito();
	//for (auto x: prime) debug(x);
	liczby.pb(1);
	for (int i = 0; i<pierwsze.size(); i++){
		LL p = pierwsze[i];int potega = 1;
		while (p<N){
			if (potega+1 == cyfry(p)) liczby.pb(p);
			p*=pierwsze[i];
			potega++;
		}
	}
	for (int i = 0; i<pierwsze.size(); i++){
		for (int j = 0; j<pierwsze.size(); j++){
			LL p1 = pierwsze[i];
			LL p2 = pierwsze[j];
			LL x = p1*p2;
			if (x<N) if (cyfry(x) == 4) liczby.pb(x);
			x = p1*p1*p2;
			if (x<N) if (cyfry(x) == 6) liczby.pb(x);
			x = p1*p2*p2;
			if (x<N) if (cyfry(x) == 6) liczby.pb(x);
			x = p1*p1*p1*p2;
			if (x<N) if (cyfry(x) == 8) liczby.pb(x);
			x = p1*p2*p2*p2;
			if (x<N) if (cyfry(x) == 8) liczby.pb(x);
			x = p1*p1*p2*p2;
			if (x<N) if (cyfry(x) == 9) liczby.pb(x);
		}
	}
	for (int i = 0; i<pierwsze.size(); i++){
		for (int j = 0; j<pierwsze.size(); j++){
			for (int k = 0; k<pierwsze.size(); k++){
				LL p = pierwsze[i]*pierwsze[j]*pierwsze[k];
				if (p < N)if (cyfry(p) == 8) liczby.pb(p);
				else break;
			}
		}
	}
	sort(liczby.begin(), liczby.end());
	liczby.erase( unique( liczby.begin(), liczby.end() ), liczby.end() );
	//for (auto x: liczby) debug(x);
	int z, a, b;
	cin >> z;
	while (z--){
		cin >> a >> b;
		//znalezc indeks pierwszej liczby wiekszej od b i wiekszej równej a
		
	}
	return 0;
}
