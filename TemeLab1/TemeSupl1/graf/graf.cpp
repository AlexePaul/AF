#include <bits/stdc++.h>

using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

vector<int> lengthX;
vector<int> lengthY;
vector<int> frecv;
vector<int> ans;
vector< vector<int> > edges;
int n,m,x,y,u,v;

void bfs(int node, vector<int>& length){
	queue<int> q;
	q.push(node);
	fill(length.begin(), length.end(), INT_MAX);
	length[node] = 0;
	while(!q.empty()){
		int f = q.front();
		for(int i = 0; i < edges[f].size(); ++i){
			if(length[edges[f][i]] > length[f] + 1){
				q.push(edges[f][i]);
				length[edges[f][i]] = length[f] + 1;
			}
		}
		q.pop();
	}
}

int main(){
	fin >> n >> m >> u >> v;

	edges.resize(n+1);
	frecv.resize(n+1);
	
	for(int i = 0; i < m; ++i){
		fin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	lengthX.resize(n+1);
	lengthY.resize(n+1);

	bfs(u, lengthX);
	bfs(v, lengthY);

	for(int i = 1; i <= n; ++i){
		if(lengthY[i]+lengthX[i] == lengthY[u]){
			frecv[lengthY[i]]++;
		}
	}
	
	for(int i = 1; i <= n; ++i){
		if(lengthY[i]+lengthX[i] == lengthY[u] && frecv[lengthY[i]] == 1)
			ans.push_back(i);
	}
	fout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++){
		fout << ans[i] << ' ';
	}

}