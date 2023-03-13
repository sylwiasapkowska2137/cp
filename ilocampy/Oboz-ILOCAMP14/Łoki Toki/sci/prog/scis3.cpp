// O(q n^3 log L) - sprytniejsze potęgowanie macierzy (spamiętujemy A^k dla k <= 10000)
// KF

const unsigned T = 10001;

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

vector<Matrix> mem;

Matrix const pot(Matrix const& M, long long unsigned k, unsigned n) {
	if(k < T) return mem[k];
	if(k % 2 == 0) return pot(M * M, k / 2, n);
	return M * pot(M, k - 1, n);
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

	mem.push_back(Matrix::I(n));
	for(unsigned i = 1; i < T; i++) {
		mem.push_back(M * mem.back());
	}

	unsigned q;
	long long unsigned A, B, S, L;
	std::cin >> q >> S >> A >> B >> L;

//	for(unsigned x = 0; x < 10; x++) {
//		cout << pot(M, x, n) << endl;
//	}

	Random R(A, B, S);
	Output O(q);
	for(unsigned i=0; i < q; i++) {
		unsigned u = R.next() % n;
		unsigned v = R.next() % n;
		unsigned long long k = R.next() % L;

//		cerr << u << " " << v << " " << k << endl;
		Matrix P = pot(M, k, n);

		O.out(P[u][v]);
	}

	O.end();
	std::cout << std::endl;
}
