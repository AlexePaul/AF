// -> Fac cate un DFS din fiecare din nodurile "punct de control"
// -> Vectorul ans incepe cu INT_MAX pe toate pozitiile
// 	 > punctele de control au 0 in ans
//	 > in DFS verific daca vecinul nodului pe care ma aflu are 
//	   ans mai mare, daca da, inseamna ca e posibil si vecinii lui 
//	   sa trebuiasca modificati, deci apelez DFS pe pozitia lui.
// -> O(k * (n+m)), unde k este numarul de puncte de control, 
//    iar n si m numarul de noduri respectiv muchii

#include <fstream>
#include <vector>
#include <climits>
#include <climits>

using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");
int n,m;
vector<int> roots;
vector<vector<int> > edges;
vector<int> ans;

void DFS(int node){
	for(int i = 0; i < edges[node].size(); ++i){
		if(ans[edges[node][i]] > ans[node] + 1){
			ans[edges[node][i]] = ans[node] + 1;
			DFS(edges[node][i]);
		}
	}
}

int main(){

	fin >> n >> m;
	edges.resize(n);
	ans.resize(n+1, INT_MAX);

	for(int i = 0; i < m; ++i){
		int x,y;
		fin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	int x;
	while(fin >> x){
		roots.push_back(x);
		ans[x] = 0;
	}

	for(int i = 0; i < roots.size(); ++i){
		DFS(roots[i]);
	}

	for(int i = 1; i <= n; ++i){
		fout << ans[i] << ' ';
	}

	return 0;
}