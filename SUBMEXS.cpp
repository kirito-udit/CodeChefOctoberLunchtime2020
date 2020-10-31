// Tech-Stack used -: Greedy & DFS
/*  the maximum MEXMEX value i.e. ai 
  of a node that it can have, is equal to the size of its subtree.
  So now, finda path from the root to a leaf such that the sum of the size of the subtree of nodes is maximum and that will be our answer.
  */
#include <bits/stdc++.h>
using namespace std;
 int N;
long long ans;
vector<long long> subtree;
vector<vector<int>> graph;

long long computeSubtree(int node, int parent) {
	subtree[node] = 1;
	for(auto i : graph[node]) {
		if(i == parent) continue;
		subtree[node] += computeSubtree(i, node);
	}
	return subtree[node];
}

void dfs(int node, int parent, long long sum_of_sub_of_ansector) {
	long long value = sum_of_sub_of_ansector + subtree[node];
	int child = 0;
	for(auto i : graph[node]) {
		if(i == parent) continue;
		child ++;
		dfs(i, node, value);
	}
	if(child == 0) {
		ans = max(ans, value); // Here checking for the leaf, though there is no need for checking for the leaf as the value for the leaf will be greater.
	}
}
 
void Solve() {
	cin >> N;
	ans = 0;
	graph.clear();
	subtree.assign(N+1, 0);
	graph.resize(N+1);
	for(int i = 2; i <= N; i ++) {
		int a = i, b;
		cin >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	computeSubtree(1, 0);
	dfs(1, 1, 0);
	cout << ans << "\n";
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
