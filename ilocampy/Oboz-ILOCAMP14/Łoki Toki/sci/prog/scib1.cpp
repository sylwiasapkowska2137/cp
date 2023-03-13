//wzorcówka na LL (zamiast ULL)
//KF
#include <iostream>
#include <vector>
#include <limits>

struct Random {
	using rand_t = int64_t;
	rand_t a, b, s;
	
	Random(rand_t a, rand_t b, rand_t s):
		a(a), b(b), s(s) {}

	rand_t next() {
		s = s * a + b;
		return s;
	}
};

struct Seq {
	const static unsigned FALSE;

	unsigned n;
	std::vector<unsigned> set;
	std::vector<unsigned> subsets;
	unsigned sep;

	Seq(unsigned n): n(n), set(1<<n, FALSE) {}

	bool add_subset(unsigned x) {
		if(set[x] == FALSE) {
			set[x] = subsets.size();
			subsets.push_back(x);
			return true;
		} else {
			sep = set[x];
			return false;
		}
	}

	unsigned get_mask(unsigned long long length) {
		if(length < sep) return subsets[length];
		unsigned offset = sep + ((length - sep) % (subsets.size() - sep));
		return subsets[offset];
	}
};

const unsigned Seq::FALSE = std::numeric_limits<unsigned>::max();

using graph_t = std::vector<unsigned>;

unsigned next_mask(graph_t const& G, unsigned n, unsigned mask) {
	unsigned new_mask = 0;
	for(unsigned i = 0; i < n; i++) {
		if(mask & (1 << i)) new_mask |= G[i];
	}

	return new_mask;
}

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

int main() {
	unsigned n, m;
	std::cin >> n >> m;

	graph_t G(n, 0);

	for(unsigned i=1; i<=m; i++) {
		unsigned a, b;
		std::cin >> a >> b;
		G[a] |= 1 << b;
	}

	std::vector<Seq> seqs;

	for(unsigned i=0; i<n; i++) {
		seqs.emplace_back(n);
		Seq& seq = seqs.back();
		unsigned mask = 1 << i;
		while(seq.add_subset(mask))
			mask = next_mask(G, n, mask);
	}

	unsigned q;
   	/*unsigned*/ long long S, A, B, L;
	std::cin >> q >> S >> A >> B >> L;
	
	Random R(A, B, S);
	Output O(q);
	for(unsigned i=0; i < q; i++) {
		unsigned u = (n + R.next() % n) % n;
		unsigned v = (n + R.next() % n) % n;
		unsigned long long k = (L + R.next() % L) % L;

		unsigned m = seqs[u].get_mask(k);
		O.out(m & (1 << v));
	}

	O.end();
	std::cout << std::endl;
}
