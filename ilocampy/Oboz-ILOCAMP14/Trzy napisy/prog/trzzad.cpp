#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

string s1, s2;

int main () {
    ios_base::sync_with_stdio(0);
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> s1 >> s2;
    int n = s1.length();

    int ind = n - 1;
    while (ind >= 0 && s1[ind] == 'z') {
        ind--;
    }

    if (ind == -1) {
        cout << "NIE" << endl;
        return 0;
    }

    string s3;
    for (int i = 0; i < ind; ++i) {
        s3.pb(s1[i]);
    }
    s3.pb(s1[ind] + 1);
    for (int i = ind + 1; i < n; ++i) {
        s3.pb('a');
    }

    bool key = true;
    for (int i = 0; i < n; ++i) {
        if (s3[i] != s2[i]) {
            key = false;
            break;
        }
    }

    if (key) {
        cout << "NIE" << endl;
        return 0;
    }

    cout << s3 << endl;
    return 0;
}