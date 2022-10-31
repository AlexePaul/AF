#include <bits/stdc++.h>

using namespace std;

ifstream fin("lesbulan.in");
ofstream fout("lesbulan.out");

vector<vector<int> >edges;
vector<int> visited;

int n,m,t;
bool ok;

void reset(){
	ok = true;
	edges.clear();
	edges.resize(n+1);
	visited.clear();
	visited.resize(n+1);
}

void removeLeaves(){
	map <int, int> leaves;
	vector<int> aux;
	for(int i = 0; i < n; ++i){
		if(edges[i].size() == 1){
			leaves[i] = 1;
		}
	}
	for(int i = 0; i < n; ++i){
		if(leaves[i] == 0){
			for(int j = 0; j < edges[i].size(); ++j)
				if(leaves[edges[i][j]] == 0){
					aux.push_back(edges[i][j]);
				}
			edges[i] = aux;
			aux.clear();
		}
		else{
			edges[i].clear();
		}
	}
}

void DFS(int node, int father = -1){
	visited[node] = true;
	for(int i = 0; i < edges[node].size(); ++i){
		if(!visited[edges[node][i]])
			DFS(edges[node][i], node);
		else if(edges[node][i] != father){
			ok = false;
		}
	}
}

int main(){
	fin >> t;
	for(int i = 0; i < t; ++i){
		fin >> n >> m;
		reset();
		for(int j = 0; j < m; ++j){
			int x, y;
			fin >> x >> y;
			edges[x-1].push_back(y-1);
			edges[y-1].push_back(x-1);
		}

		for(int j = 0; j < n; ++j)
			if(!visited[j])
				DFS(j);

		removeLeaves();
		removeLeaves();

		bool k = true;
		
		for(int i = 0; i < n; ++i){
			if(edges[i].size() > 2){
				k = false;
				break;
			}
		}

		if(k == true && ok == true)
			fout << 1 << '\n';
		else
			fout << 0 << '\n';
	}
}