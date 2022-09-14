#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<LD> vld;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x) memset(x, 0, sizeof(x))
#define debug(x) cerr << x << " "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
LL losuj(LL a, LL b){ return a+rng()%(b-a+1);}

LL power(LL a, LL b, LL MOD){
	if (b == 0) return 1LL;
	LL k = power(a, b/2, MOD);
	k = (k*k)%MOD;
	if (b&1) k = (k*a)%MOD;
	return k;
}
bool miller(LL d, LL n){
    LL a = 2 + rng() % (n - 4);
    LL x = power(a, d, n);
    if (x == 1  || x == n-1) return 1;
    while (d != n-1){
        x = (x * x) % n;
        d *= 2;
        if (x == 1) return 0;
        if (x == n-1) return 1;
    }
	return 0;
}

bool prime(LL n, LL k){
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    int d = n-1;
    while (d%2==0) d /= 2;
    for (int i=0; i<k; i++)
         if (!miller(d, n)) return false;
    return true;
}

LL make_number(string s){
	LL num = 0;
	for (auto c: s){
		num*=10;
		num+= (int)(c-'0');
	}
	return num;
}

const int MAX = 1e5+7;
bool is_prime[MAX];

void erasthotenes(){
	rep(i, 0, MAX) is_prime[i] = 1;
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= MAX; i++) {
		if (is_prime[i] && (long long)i * i <= MAX) {
			for (int j = i * i; j <= MAX; j += i)
				is_prime[j] = false;
		}
	}
}

bool is(LL n){
	if(n<2) return false;
	for(LL i=2;i*i*i<=n;++i) if(n%i==0) return false;
	for(int it=0;it<1e5;++it){
		LL i = rng()%(n-1)+1;
		if(__gcd(i,n)!=1) return false;
		if(power(i,n-1,n)!=1) return false;
	}
	return true;
}

void solve(){
	string s; cin >> s;
	//erasthotenes();
	int n = sz(s);
	rep(i, 0, n-1) {
		if (s[i+1] == '0') continue;
		LL a = make_number(s.substr(0, i+1));
		LL b = make_number(s.substr(i+1, n));
		if (is(a) && is(b)) {
			cout << "TAK\n";
			return;
		}
	}
	cout << "NIE\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
