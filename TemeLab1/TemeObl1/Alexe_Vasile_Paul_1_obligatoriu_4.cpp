// -> Aplic algoritmul lui Kosaraju
//		> Fac un dfs si pastrez nodurile vizitate intr-o stiva
// 		> fac un dfs pe graful transpus in timp ce scot noduri de pe stiva
// -> O(n+m)

#include <fstream>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

vector<vector<int > >edges;
vector<vector<int > >edgesT;
stack<int> DFSstack;
vector<int> visited;
vector<vector<int> > ans;
int n,m,x,y,k;

void initialDFS(int node){
	visited[node] = 1;
	for(int i = 0; i < edges[node].size(); ++i){
		if(visited[edges[node][i]] == false){
			initialDFS(edges[node][i]);
		}
	}
	DFSstack.push(node);
}

void finalDFS(int node){
	ans[k].push_back(node);
	visited[node] = 1;
	for(int i = 0; i < edgesT[node].size(); ++i){
		if(visited[edgesT[node][i]] == false){
			finalDFS(edgesT[node][i]);
		}
	}

}

int main(){

	fin >> n >> m;
	edges.resize(n+1);
	edgesT.resize(n+1);
	visited.resize(n+1);
	ans.resize(n);

	for(int i = 0; i < m; ++i){
		fin >> x >> y;
		edges[x].push_back(y);
		edgesT[y].push_back(x);
	}
	for(int i = 0; i <= n; ++i){
		if(!visited[i])
			initialDFS(i);
	}

	fill(visited.begin(), visited.end(), 0);

	ans[0].clear();
	
	while(!DFSstack.empty()){
		if(visited[DFSstack.top()] == true)
			DFSstack.pop();
		else{
			finalDFS(DFSstack.top());
			k++;
			ans[k].clear();
		}
	}

	k--;
	
	fout << k << '\n';
	for(int i = 0; i < k; ++i){
		for(int j = 0; j < ans[i].size(); ++j){
			fout << ans[i][j] << ' ';
		}
		fout << '\n';
	}
}

