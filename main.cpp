#include<iostream>
#include<vector>

using namespace std;


vector<bool> sieve(100001, true);

void sieve_init() {
	sieve[0] = false;
	sieve[1] = false;
	for (int i = 2; i < 100001; i++) {
		if (sieve[i]) {
			for (int j = 2 * i; j < 100001; j += i) {
				sieve[j] = false;
			}
		}
	}
} 

int diff_next_prime(int i) {
	for (int j = i; j < 100001; j++) {
		if (sieve[j]) {
			return j - i;
		}
	}
	return 100003 - i;
}


int main() {
	int n, m;
	cin >> n >> m;
	sieve_init();

	vector<int> csum(m, 0);
	int mrsum = 0;

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		a = diff_next_prime(a);
		csum[i] += a;
		mrsum += a;
	}

	cerr << mrsum << '\n';

	n--;
	for (int j = 0; j < n; j++) {
		int rsum = 0;
		for (int i = 0; i < m; i++) {
			int a;
			cin >> a;
			a = diff_next_prime(a);
			csum[i] += a;
			rsum += a;
		}

		if (rsum < mrsum) mrsum = rsum;
		cerr << mrsum << '\n';
	}

	for (int e : csum) {
		if (e < mrsum) mrsum = e;
	}

	cout << mrsum;
	
}
