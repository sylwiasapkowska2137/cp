//Sylwia Sapkowska
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
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
//#define debug(x) cerr << x << " "
#define PI 3.14159265359

const LL MAX = 2002, MOD = 1e9+7, BASE = 2137;
int n, m;
char tab[MAX][MAX];
LL hash_poziomy[MAX][MAX], hash_pionowy[MAX][MAX];
LL inv[MAX];
int p[MAX][MAX], p2[MAX][MAX];

LL power(LL a, LL b){
	LL res = 1LL;
	while (b){
		if (b&1) res = (res*a)%MOD;
		a = (a*a)%MOD;
		b/=2;
	}
	return res;
}

LL inverse(LL num){
	return power(num, MOD-2);
}

void make_hash_pionowy(int lvl){
	LL pot = 1;
	rep(i, 1, n+1){
		hash_pionowy[i][lvl] = (hash_pionowy[i-1][lvl]+tab[i][lvl]*pot)%MOD;
		pot = (pot*BASE)%MOD;
	}
}

void make_hash_poziomy(int lvl){
	LL pot = 1;
	rep(j, 1, m+1){
		hash_poziomy[lvl][j] = (hash_poziomy[lvl][j-1]+tab[lvl][j]*pot)%MOD;
		pot = (pot*BASE)%MOD;
	}
}

LL count_hash_pionowy(int a, int b, int lvl){
	LL hash = (hash_pionowy[b][lvl]-hash_pionowy[a-1][lvl]+MOD)%MOD;
	hash = (hash*inv[a-1])%MOD;
	return hash;
}

LL count_hash_poziomy(int lvl, int a, int b){
	LL hash = (hash_poziomy[lvl][b]-hash_poziomy[lvl][a-1]+MOD)%MOD;
	hash = (hash*inv[a-1])%MOD;
	return hash;
}

bool check(int i, int j, int len){
	LL h1 = count_hash_pionowy(i-len, i+len, j);
	LL h3 = count_hash_poziomy(i, j-len, j+len);
	//i = n-i+1;
	//j = m-j+1;
	//LL h2 = count_hash_pionowy2(i, i+len, j);
	//LL h4 = count_hash_poziomy2(i, j, j+len);
	//debug(i, j, len, h1, h3, h2, h4);
	if (h1 == h3) return 1;
	return 0;
}

void manacher_poziomy(int lvl){
	tab[lvl][0] = '$';
	tab[lvl][m+1] = '#';
	int l = 0, r = -1;
	rep(i, 1, m+1){
		p[lvl][i] = max(0, min(r-i, p[lvl][l+(r-i)]));
		while (tab[lvl][i-p[lvl][i]] == tab[lvl][i+p[lvl][i]]) p[lvl][i]++;
		if (i + p[lvl][i] > r){
			l = i-p[lvl][i];
			r = i+p[lvl][i];
		}
	}
}

void manacher_pionowy(int lvl){
	tab[0][lvl] = '$';
	tab[n+1][lvl] = '#';
	int l = 0, r = -1;
	rep(i, 1, n+1){
		p2[i][lvl] = max(0, min(r-i, p2[l+(r-i)][lvl]));
		while (tab[i-p2[i][lvl]][lvl] == tab[i+p2[i][lvl]][lvl]) p2[i][lvl]++;
		if (i + p2[i][lvl] > r){
			l = i-p2[i][lvl];
			r = i+p2[i][lvl];
		}
	}
}

void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
  
    number = 0;
  
    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;
  
        // extract the next character from the buffer
        c = getchar();
    }
  
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
  
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

void solve(){
	fastscan(n);
	fastscan(m);
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			char c = getchar();
			while (!(c>='A' && c<='Z')) c = getchar();
			tab[i][j] = c;
		}
	}
	
	rep(i, 1, n+1) manacher_poziomy(i);
	rep(i, 1, m+1) manacher_pionowy(i);
	LL pot = 1;
	rep(i, 0, max(n, m)+2){
		inv[i] = inverse(pot);
		pot = (pot*BASE)%MOD;
	}
	
	rep(i, 1, n+1) make_hash_poziomy(i);
	rep(i, 1, m+1) make_hash_pionowy(i);
	
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			int L = 1;
			int R = min(min(min(n-i, m-j), min(i, j)), min(p[i][j]-1, p2[i][j]-1));
			//debug(i, j, L, R);
			int tmp = 0;
			while (R>=L){
				int m = (L+R)/2;
				if (check(i, j, m)){
					tmp = m;
					L = m+1;
				} else R = m-1;
			}
			cout << tmp << " ";
		}
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
