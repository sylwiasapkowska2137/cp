#include <bits/stdc++.h>

using namespace std;

const int nax = 1e6 + 5;
int child[nax][26];
bool is_end[nax];
int nxt = 1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> in(n);
    vector<vector<int>> paths(n);
    for (int who = 0; who < n; ++who) {
        string &s = in[who];
        cin >> s;
        reverse(s.begin(), s.end());
        int node = 0;
        for (char ch : s) {
            paths[who].push_back(node);
            if (child[node][ch - 'a'] == 0) child[node][ch - 'a'] = nxt++;
            node = child[node][ch - 'a'];
        }
        is_end[node] = true;
    }
    int answer = 0;
    for (int who = 0; who < n; ++who) {
        string &s = in[who];
        set<char> suffix;
        for (int i = (int)s.length() - 1; i >= 0; --i) {
            suffix.insert(s[i]);
            int node = paths[who][i];
            for (char ch : suffix)
                answer += is_end[child[node][ch - 'a']];
        }
    }
    cout << answer - n; // subtract pairs (s[i], s[i])
}