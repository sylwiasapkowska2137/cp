// O(q n^3 log L) - sprytne potęgowanie macierzy (zapisujemy k w systemie o podstawie T)
// KF
const unsigned T = 1<<14;

#include <bits/stdc++.h>

using namespace std;

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

struct Matrix {
	vector<vector<bool>> M;
	unsigned n;

	Matrix(unsigned n): M(n, vector<bool>(n, false)), n(n) {}

	static Matrix const I(unsigned n) {
		Matrix M(n);
		for(unsigned i = 0; i < n; i++) M[i][i] = true;

		return M;
	}

	vector<bool>& operator[] (int idx) {
		return M[idx];
	}

	vector<bool> const& operator[] (int idx) const {
		return M[idx];
	}

	Matrix const operator * (Matrix const& other) const {
		assert(n == other.n);

		Matrix res(n);

		for(unsigned i = 0; i < n; i++)
				for(unsigned k = 0; k < n; k++)
			for(unsigned j = 0; j < n; j++)
					res[i][j] = res[i][j] || (M[i][k] && other[k][j]);

		return res;
	}

	friend ostream& operator << (ostream& out, Matrix const& M) {
		for(unsigned i = 0; i < M.n; i++) {
			for(unsigned j = 0; j < M.n; j++)
				out << "01"[M[i][j]];
			out << endl;
		}
		return out;
	}
};

const unsigned long long MAX_L = 1000000000000000000LL;

constexpr unsigned sLOG(unsigned long long n, unsigned base) {
	return base > n ? 1 : (1 + sLOG(n/base, base));
}

const unsigned R = sLOG(MAX_L, T);

vector<Matrix> mem[R];

void preproc(Matrix const& M) {
	unsigned const& n = M.n;
	Matrix base = M;
	for(unsigned _ = 0; _ < R; _++) {
		vector<Matrix> &vec = mem[_];
		vec.push_back(Matrix::I(n));

		for(unsigned i = 1; i < T; i++) {
			vec.push_back(vec.back() * base);
		}

		base = base * vec.back();
	}
}

Matrix const getM(int const n, long long unsigned k) {
	Matrix M = Matrix::I(n);

	for(unsigned p = 0; k > 0; p++) {
		M = M * mem[p][k % T];
		k /= T;
	}

	return M;
}

int main() {
	unsigned n, m;
	std::cin >> n >> m;

	Matrix M(n);

	for(unsigned i=1; i<=m; i++) {
		unsigned a, b;
		std::cin >> a >> b;

		M[a][b] = true;
	}

	preproc(M);

	unsigned q;
	long long unsigned A, B, S, L;
	std::cin >> q >> S >> A >> B >> L;

	Random R(A, B, S);
	Output O(q);
	for(unsigned i=0; i < q; i++) {
		unsigned u = R.next() % n;
		unsigned v = R.next() % n;
		unsigned long long k = R.next() % L;

		Matrix P = getM(n, k);

		O.out(P[u][v]);
	}

	O.end();
	std::cout << std::endl;
}
