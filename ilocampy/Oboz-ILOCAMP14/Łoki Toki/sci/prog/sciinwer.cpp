#include "oi.h"
#include <cstdlib>
#include <iostream>
#include <set>
#include <tuple>

using namespace std;

using edge = pair<unsigned, unsigned>;

const unsigned MIN_N = 1, MAX_N = 20;
const unsigned MIN_M = 0;
const unsigned MIN_Q = 1, MAX_Q = 10000000;

void ensure(bool b, const char* c) {
	if(b) return;
	printf("%s\n", c);
	exit(1);
}

int main() {
	oi::Scanner inf(stdin, oi::PL);

	unsigned n = inf.readUInt(MIN_N, MAX_N);
	inf.readSpace();
	unsigned m = inf.readUInt(MIN_M, n * (n - 1));
	inf.readEoln();

	set<edge> E;

	for(unsigned i = 0; i < m; i++) {
		unsigned u = inf.readUInt(0, n);
		inf.readSpace();
		unsigned v = inf.readUInt(0, n);
		inf.readEoln();
		ensure(u != v, "pętla w grafie");
		
		ensure(!E.count({u, v}), "powtarzające się krawędzie");
		E.emplace(u, v);
	}

	unsigned q = inf.readUInt(MIN_Q, MAX_Q);
	inf.readSpace();
	unsigned long long S = inf.readULL();
	inf.readSpace();
	unsigned long long A = inf.readULL();
	inf.readSpace();
	unsigned long long B = inf.readULL();
	inf.readSpace();
	unsigned long long L = inf.readULL();
	inf.readEoln();
	inf.readEof();

	(void) A;
	(void) B;
	(void) S;

	cout << "ok";
	if(L <= 100) cout << " L <= 100";
	if(q <= 10000) cout << " q <= 10000";
	cout << endl;
	return 0;
}
