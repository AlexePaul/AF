#include <bits/stdc++.h>

using namespace std;

ifstream fin("lesbulan.in");
ofstream fout("lesbulan.out");

vector<vector<int> >edges;
vector<int> visited;
vector<int> length;

int n,m,t;
bool ok;
void reset(){
	ok = true;
	edges.clear();
	edges.resize(n+1);
	visited.clear();
	visited.resize(n+1);
	length.clear();
	length.resize(n+1);
}

void DFS(int node, int father = -1){
	visited[node] = true;
	for(int i = 0; i < edges[node].size(); ++i){
		if(!visited[edges[node][i]]){
			length[edges[node][i]] = max(length[edges[node][i]], length[node] + 1);
			DFS(edges[node][i], node);
		}
		else if(edges[node][i] != father && visited[edges[node][i]] == 1){
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
			edges[x].push_back(y);
			edges[y].push_back(x);
		}

		for(int j = 1; j <= n; ++j){
			if(!visited[j])
				DFS(j);
			if(ok == false)
				break;
		}
		int lengthMax = INT_MIN;
		for(int i = 1; i <= n; ++i){
			if(length[i] > lengthMax)
				lengthMax = length[i];
		}
		if(ok == false || lengthMax > 2)
			fout << 0 << '\n';
		if(ok == true && lengthMax < 3)
			fout << 1 << '\n';
	}
}