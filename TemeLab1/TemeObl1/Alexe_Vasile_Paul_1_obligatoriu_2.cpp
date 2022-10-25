// -> Sortez vecinii fiecarui nod in functie de ordinea in care apar
// 	 in permutarea data.
// -> Parcurg graful cu un DFS si tin minte ordinea in care am parcurs
// -> Verific daca ordinea in care am parcurs coincide cu permutarea
// 		- Daca nu coincid inseamna ca nu este posibil
// -> O(m * log m)


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector <int> > adjacencyList(100000);
vector<int> permutation(100000);
vector<int> frecv(100000);
vector<bool> visited(100000,false);
vector<int> order;
int n,m;

void checkDfs(int node){
	visited[node] = true;
	order.push_back(node);
	for(int i = 0; i < adjacencyList[node].size(); ++i){
		if(visited[adjacencyList[node][i]] == false)
			checkDfs(adjacencyList[node][i]);
	}
}

bool cmp(int a, int b){
	return frecv[a] < frecv[b];
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		cin >> permutation[i];
		frecv[permutation[i]] = i;
	}
	for(int i = 0; i < m; ++i){
		int a,b;
		cin >> a >> b;
		adjacencyList[a].push_back(b);
		adjacencyList[b].push_back(a);
	}

	for(int i = 1; i <= n; ++i){
		sort(adjacencyList[i].begin(), adjacencyList[i].end(), cmp);
	}

	checkDfs(1);

	for(int i = 0; i < n; ++i){
		if(order[i] != permutation[i]){
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}