#include <bits/stdc++.h>

using namespace std;

ifstream fin("lesbulan.in");
ofstream fout("lesbulan.out");

vector<vector<int> >edges;
vector<int> length;
vector<int> visited;
int n,m,t;

int DFS(int node){
	stack<int> s;
	int maxi = INT_MIN;
	s.push(node);
	int father = -1;
	length[node] = 0;
	visited[node] = 1;
	while(!s.empty()){
		int f = s.top();
		for(int i = 0 ; i < edges[f].size(); ++i){
			if(visited[edges[f][i]] == true && edges[f][i] != father){
				cout << f << ' ' << edges[f][i] << ' ' << father << '\n';
				return 0;
			}
			if(!visited[edges[f][i]] || length[edges[f][i]] < length[f] + 1){
				visited[edges[f][i]] = 1;
				length[edges[f][i]] = length[f] + 1;
				if(length[edges[f][i]] > maxi)
					maxi = length[edges[f][i]];
				s.push(edges[f][i]);
			}
		}
		s.pop();
		father = f;
	}
	return maxi;
}

void reset(){
	edges.clear();
	edges.resize(n+1);
	visited.clear();
	visited.resize(n+1);
	length.clear();
	length.resize(n+1);
}
int main(){
	fin >> t;
	for(int k = 0; k < t; ++ k){
		fin >> n >> m;
		reset();
		for(int i = 0; i < m; ++i){
			int x, y;
			fin >> x >> y;
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
		for(int i = 1; i <= n; ++i){
			if(!visited[i])
				cout << DFS(i) << ' ';
		}
	}
}