//rozwiązanie powolne (z dowodu tw. Savitcha): O(???)
//KF
#include <iostream>
#include <vector>
#include <limits>

struct Random {
	using rand_t = uint64_t;
	rand_t a, b, s;
	
	Random(rand_t a, rand_t b, rand_t s):
		a(a), b(b), s(s) {}

	rand_t next() {
		s = s * a + b;
		return s;
	}
};

using graph_t = std::vector<std::vector<bool>>;

struct Output {
	unsigned cnt;
	bool nonzero;
	unsigned buf;

	Output(unsigned q): cnt((4 - q%4) % 4), nonzero(false), buf(0) {}

	void out(bool ans) {
		cnt ++;
		buf = 2 * buf + ans;
		if(cnt == 4) push();
	}

	static char letter(unsigned x) {
		if(x < 10) return '0' + x;
		else return 'A' + (x - 10);
	}

	void push() {
		cnt = 0;
		if(buf != 0) nonzero = true;
		if(nonzero) std::cout << letter(buf);
		buf = 0;
	}

	void end() {
		if(!nonzero) std::cout << '0';
	}
};

bool check(unsigned u, unsigned v, unsigned long long k, graph_t const& G, unsigned n) {
	if(k == 0) return u==v;
	if(k == 1) return G[u][v];
	unsigned long long s = k >> 1;

	for(unsigned i = 0; i < n; i++) {
		if(check(u, i, s, G, n) && check(i, v, k - s, G, n)) return true;
	}

	return false;
}

int main() {
	unsigned n, m;
	std::cin >> n >> m;

	graph_t G(n, std::vector<bool>(n, false));

	for(unsigned i=1; i<=m; i++) {
		unsigned a, b;
		std::cin >> a >> b;
		G[a][b] = true;
	}

	unsigned q;
   	unsigned long long S, A, B, L;
	std::cin >> q >> S >> A >> B >> L;
	
	Random R(A, B, S);
	Output O(q);
	for(unsigned i=0; i < q; i++) {
		unsigned u = R.next() % n;
		unsigned v = R.next() % n;
		unsigned long long k = R.next() % L;

		O.out(check(u, v, k, G, n));
	}

	O.end();
	std::cout << std::endl;
}
