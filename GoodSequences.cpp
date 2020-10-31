#include <bits/stdc++.h>
using namespace std;
 
void Solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n+2, -1); // I have made the array large so I doesn't have to handle edge cases.
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	int ans = 2; // considering the contribution of 0th element and (n+1)th element which is -1. (when I will print the answer I will reduce 2 from it to negate its effect).
				 // just done it to make the implementation easy.
	for(int i = 1; i <= n; i ++) {
		ans += (a[i] != a[i-1]);
	}
	while(q --) {
		int x, y;
		cin >> x >> y;
		if((a[x] == a[x-1]) && (a[x] == a[x+1])) {
			if(y != a[x]) ans += 2;
		}
		else if((a[x] != a[x-1]) && (a[x] == a[x+1])) {
			if(y != a[x]) ans ++;
			if(y == a[x-1]) ans --;
		}
		else if((a[x] == a[x-1]) && (a[x] != a[x+1])) {
			if(y != a[x]) ans ++;
			if(y == a[x+1]) ans --;
		}
		else {
			if(y == a[x-1]) ans --;
			if(y == a[x+1]) ans --;
		}
		a[x] = y;
		cout << ans-2 << "\n";
	}
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
