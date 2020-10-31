// Stack used-: Bitwise Operation and Number Theory
#include <bits/stdc++.h>
using namespace std;
 
void Solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	vector<int> dp(50, 0);
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < 30; j ++) {
			dp[j] += a[i] % 2;
			a[i] /= 2;
		}
	}
	long long num = 0;
	long long mul = 1;
	for(int i = 0; i < 50; i ++) {
		if(i) {
			dp[i] += (dp[i-1]/2);
		}
		if(dp[i]) num += mul;
		mul *= 2LL;
	}
	cout << num << "\n";
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int test_case = 1;
	cin >> test_case;
	for(int i = 1; i <= test_case; i ++) {
		Solve();
	}
	
	return 0;
}  
