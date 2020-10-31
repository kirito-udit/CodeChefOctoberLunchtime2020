// Prerequisite-: Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

const int maxA = 1e5+1;

vector<int> spf(maxA, -1);

void computeSPF() {
	spf[1] = 1;
	for(int i = 2; i < maxA; i ++) {
		if(spf[i] == -1) {
			for(int j = i; j < maxA; j += i) {
				if(spf[j] == -1) spf[j] = i;
			}
		}
	}
}

void Solve() {
	int N;
	cin >> N;
	vector<int> marking(N, 0); // difference array, for marking restricted index.
	vector<pair<int, int>> prime_range(maxA, {-1, -1});
	for(int i = 0; i < N; i ++) {
		int x;
		cin >> x;
		while(x > 1) {
			int prime = spf[x];
			if(prime_range[prime].first != -1) {
				prime_range[prime].second = i;
			}
			else prime_range[prime] = {i, i};
			x /= prime;
		}
	}
	
	// Now marking the indexes with difference array which can't be answer;
	for(int i = 2; i < maxA; i ++) {
		if(prime_range[i].first == -1) continue;
		int L = prime_range[i].first;
		int R = prime_range[i].second;
		// All the index from [L, R-1] can't be the "l" as the answer
		marking[L] ++;
		marking[R] --;
	}
	for(int i = 1; i < N; i ++) {
		marking[i] += marking[i-1];
	}
	for(int i = 0; i < N; i ++) {
		if(marking[i]) continue;
		cout << i+1 << "\n";
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	computeSPF();

	int test_case;
	cin >> test_case;
	for(int i = 1; i <= test_case; i ++) {
		Solve();
	}
}
