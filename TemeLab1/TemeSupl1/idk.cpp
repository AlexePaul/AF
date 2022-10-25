#include <bits/stdc++.h>

using namespace std;

ifstream fin("idk.in");
ofstream fout("idk.out");

vector< vector<int > > edges;
vector<int> length;
int n,m,t;

void dfs(int node){
	for(int i = 0; i < edges[node].size(); ++i){
		if(length[edges[node][i]] > length[node] + 1){
			length[edges[node][i]] = length[node] + 1;
			dfs(edges[node][i]);
		}
	}
}

int main(){
	fin >> n >> m;
	edges.resize(n+1);
	length.resize(n+1);
	fill(length.begin(), length.end(), INT_MAX);

	for(int i = 0; i < m; ++i){
		int x,y;
		fin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	while(fin >> t){
		length[t] = 0;
		dfs(t);
	}

	for(int i = 1; i <= n; ++i){
		fout << length[i] << ' ';
	}

}