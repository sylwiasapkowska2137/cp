#include "oi.h"
#include <cassert>
#include <initializer_list>
#include <fstream>
#include <iostream>
#include <set>
using namespace std;

oi::Random rnd(0x21433214);

const std::string ID("sci");

double random01() {
	return rnd.rand() / (double) (1LL << 31);
}

template <typename T>
T random_int(T a, T b) {
	return a + (T) std::floor(random01() * (b + 1 - a));
}

long long unsigned r64() {
	return rnd.randULL();
}

struct edge {
	unsigned u, v;
	edge(unsigned u, unsigned v): u(u), v(v) {}

	bool operator < (edge const& other) const {
		if(u != other.u) return u < other.u;
		return v < other.v;
	}
};

struct Test {
	friend std::ostream& operator << (std::ostream& out, const Test& test) {
		out << test.n << " " << test.edges.size() << endl;	
		for(edge const& e: test.edges) {
			out << e.u << " " << e.v << endl;
		}
		out << test.q << " " << test.S << " " << test.A << " " << test.B << " " << test.L << endl;
		return out;
	}

	Test& operator()(unsigned u, unsigned v) {
		add_edge(u, v);
		return *this;
	}

	Test(unsigned n, unsigned q, long long unsigned L = numeric_limits<long long unsigned>::max()): n(n), q(q), L(L) {
		init_rnd();
	}

protected:
	unsigned n;
	set<edge> edges;

	unsigned q;
	unsigned long long S, A, B, L;

	void init_rnd() {
		S = r64();
		A = r64();
		B = r64();		
	}

	void add_edge(unsigned u, unsigned v) {
		edges.emplace(u, v);
	}
};

long long unsigned const MULL = numeric_limits<long long unsigned>::max();

struct Random : Test {
	Random(unsigned n, unsigned m, unsigned q, long long unsigned L = MULL): Test(n, q, L) {
		for(unsigned _ = 0; _ < m; _++) {
			unsigned u = random_int(0U, n-1);
			unsigned v = random_int(0U, n-1);
			if(u != v) add_edge(u, v);
		}
	}
};

unsigned sum(vector<unsigned> const& v) {
	unsigned res = 0;
	for(unsigned x: v) res += x;
	return res;
}

struct Cycles : Test {
	Cycles(vector<unsigned> lengths, unsigned q, long long unsigned L = MULL): Test(1 + sum(lengths), q, L) {
		unsigned next = 1;
		for(auto l : lengths) {
			add_edge(0, next);

			for(unsigned i = next + 1; i < next + l; i++) {
				add_edge(i-1, i);
			}

			add_edge(next + l - 1, next);

			next += l;
		}
	}
};

struct CyclesPlus : Cycles {
	CyclesPlus(vector<unsigned> lengths, unsigned q, unsigned super, long long unsigned L = MULL): Cycles(lengths, q, L) {
		for(unsigned _ = 0; _ < super; _++) {
			unsigned u = random_int(0U, n-1);
			unsigned v = random_int(0U, n-1);
			if(u != v) add_edge(u, v);
		}
	}
};

void write(std::string name, const Test& test) {
	std::ofstream file(name);
	assert(file.is_open());
	std::cerr << "Writing " << name << std::endl;
	file << test;
}

unsigned test_no = 0;
void write_group(const std::initializer_list<Test>& list) {
	++test_no;
	char letter = 'a';
	bool many_cases = std::distance(list.begin(), list.end()) != 1;
	for(const auto& test : list) {
		write(ID + std::to_string(test_no) +
				(many_cases ? std::string(1, letter++) : "")
			   	+ ".in", test);
	}
}

int main() {
	write_group({
		Test(3, 10000, 100), // 1 -- zero krawędzi, odpowiedź == 0
	});

	write_group({ //2a-k: losowe
		Random(1, 0, 10000, 10),
		Random(14, 100, 1000, 10),
		Random(20, 100, 1000, 10),
		Random(15, 100, 1000, 10),
		Random(20, 100, 1000, 10),
		Random(16, 100, 1000, 10),
		Random(20, 100, 1000, 10),
		Random(17, 100, 1000, 10),
		Random(2, 100, 1000, 10),
		Random(18, 100, 1000, 10),
		Random(19, 100, 1000, 10),
	});
	
	write_group({ //3a-k: losowe
		Random(1, 0, 10000, 100),
		Random(14, 100, 10000, 100),
		Random(20, 100, 10000, 100),
		Random(15, 100, 10000, 100),
		Random(20, 100, 10000, 100),
		Random(16, 100, 10000, 100),
		Random(20, 100, 10000, 100),
		Random(17, 100, 10000, 100),
		Random(2, 100, 10000, 100),
		Random(18, 100, 10000, 100),
		Random(19, 100, 10000, 100),
	});

	write_group({
		Random(16, 250, 10000),
		Random(19, 210, 10000),
		Cycles({2,3,5,7}, 10000),
		CyclesPlus({2,3,5,7}, 3, 10000),
	});

	write_group({
		Random(20, 400, 10000000, 100),
		Random(19, 400, 10000000, 100),
		Cycles({2,3,5,7}, 10000000, 100),
		CyclesPlus({2,3,5,7}, 3, 10000000, 100),
	});

	write_group({
		Random(20, 41, 1000000),
		Random(19, 41, 1000000),
		Random(18, 41, 1000000),
		Cycles({2,3,5,7}, 1000000),
		Cycles({9, 10}, 1000000),
		Cycles({8, 7, 3}, 1000000),
		CyclesPlus({7, 6, 5}, 1, 1000000),
	});

	write_group({
		Random(20, 41, 10000000),
		Random(19, 41, 10000000),
		Random(18, 41, 10000000),
		Cycles({2,3,5,7}, 10000000),
		Cycles({9, 10}, 10000000),
		Cycles({8, 7, 3}, 10000000),
		CyclesPlus({6, 7, 5}, 1, 10000000),
	});
}
