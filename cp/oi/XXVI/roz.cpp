#include <vector>
#include <cstdint>
using namespace std;
#define int long long

vector<int>t;
int n, ptr = 1;

void inicjuj(int32_t nn){
    n = nn;
    t.assign(n+1, 0);
}

int sum(int r){
    int ans = 0;
    for (; r >= 0; r = (r&(r+1))-1){
        ans += t[r];
    }
    return ans;
}

int sum(int l, int r){return sum(r) - sum(l-1);}

void add(int pos, int dif) { 
	for (; pos < t.size(); pos |= pos + 1) {
        t[pos] += dif;
    }
}

int query(int pos) { //[0, pos)
    pos++;
    int res = 0;
    for (; pos > 0; pos &= pos - 1) res += t[pos-1];
    return res;
}

void koryguj(int32_t idx, int32_t delta){
    idx = (ptr - idx - 1 + n) % n + 1;
    add(idx, delta);
}

void dodaj(int32_t k){
    add(ptr, -sum(ptr, ptr)+k);
    ptr = ptr%n+1;
}

int suma(int32_t i){
    if (ptr - 1 >= i) return sum(ptr-i, ptr-1);
    return sum(ptr-1) + sum(n-ptr+i, n);
}

/*
void solve(){
    inicjuj(3);
    dodaj(-6);
    cout << suma(1) << "\n";
    dodaj(5);
    // koryguj(2, 10);
    cout << suma(3) << "\n";
    cout << suma(1) << "\n";
    dodaj(2);
    dodaj(3);
    cout << suma(2) << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
*/