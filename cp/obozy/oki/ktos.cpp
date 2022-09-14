#include <bits/stdc++.h>
using namespace std;
struct dane {
    int ojciec;
    int masa;
    int max_iq;
    int min_iq;
};

vector<int> masa, iq;
vector<dane> ojciec;

dane findd(int v) {
    if(ojciec[v].ojciec==v) {
        return ojciec[v];
    }
    dane ojc = findd(ojciec[v].ojciec);
    ojciec[v].ojciec = ojc.ojciec;
    return ojciec[v];
}

void unionn(int a, int b) {
    findd(a);
    findd(b);
    if(ojciec[a].ojciec==ojciec[b].ojciec) {
        return;
    }
    a = ojciec[a].ojciec;
    b = ojciec[b].ojciec;
    ojciec[a].masa += ojciec[b].masa;
    ojciec[a].max_iq = max(ojciec[a].max_iq, ojciec[b].max_iq);
    ojciec[a].min_iq = min(ojciec[a].min_iq, ojciec[b].min_iq);
    ojciec[b].ojciec = ojciec[a].ojciec;
}

int main() {
    int n;
    cin >> n;

    masa.resize(n);
    iq.resize(n);
    ojciec.resize(n);

    for(int i=0; i<n; i++) {
        cin >> masa[i] >> iq[i];
        ojciec[i].ojciec = i;
        ojciec[i].masa = masa[i];
        ojciec[i].max_iq = iq[i];
        ojciec[i].min_iq = iq[i];
    }

    string polecenie;

    while(cin>>polecenie) {
        if(polecenie=="JOIN") {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            unionn(a, b);
        }
        if(polecenie=="IQ_MIN") {
            int a;
            cin >> a;
            a--;
            dane ojc = findd(a);
            cout << ojciec[ojc.ojciec].min_iq << "\n";
        }
        if(polecenie=="IQ_MAX") {
            int a;
            cin >> a;
            a--;
            dane ojc = findd(a);
            cout << ojciec[ojc.ojciec].max_iq << "\n";
        }
        if(polecenie=="MASA") {
            int a;
            cin >> a;
            a--;
            dane ojc = findd(a);
            cout << ojciec[ojc.ojciec].masa << "\n";
        }
        /*for(int i=0; i<n; i++) {
            findd(i);
            cout << "ojciec[" << i+1 << "]:\n";
            cout << "ojciec: " << ojciec[i].ojciec+1 << "\n";
            cout << "masa: " << ojciec[i].masa << "\n";
            cout << "min_iq: " << ojciec[i].min_iq << "\n";
            cout << "max_iq: " << ojciec[i].max_iq << "\n";
            cout << "\n-------------------\n\n\n";
        }*/
    }

    return 0;
}
