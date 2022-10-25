#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("graf.in");


//a)
pair<bool **, int> adiacenta(){
	int size, edgesCount, tempX, tempY;
	bool orientat;
	fin >> size >> orientat;
	
	bool ** mat = new bool*[size];
	for(int i = 0; i <= size; ++i){
		mat[i] = new bool[size];
	}
	
	fin >> edgesCount;
	
	for(int i = 0; i < edgesCount; ++i){
		fin >> tempX >> tempY;
		mat[tempX][tempY] = 1;
		if(orientat == false){
			mat[tempY][tempX] = 1;
		}
	}

	return make_pair(mat, size);
}

//b)
pair<vector< vector<int> >, int> adiacentaL(){
	int size, edgesCount, tempX, tempY;
	bool orientat;
	vector< vector<int> > lista;
	
	fin >> size >> orientat;
	lista.resize(size+1);

	fin >> edgesCount;

	for(int i = 0; i < edgesCount; ++i){
		fin >> tempX >> tempY;
		lista[tempX].push_back(tempY);
		if(orientat == false){
			lista[tempY].push_back(tempX);
		}
	}
	return make_pair(lista,size);
}

void testgraf1(){
	cout << "Matrice De Adiacenta:\n";

	pair<bool **, int> graf = adiacenta();

	for(int i = 0; i < graf.second; ++i){
		for(int j = 0; j < graf.second; ++j){
			cout << graf.first[i][j] << ' ';
		}
		cout << '\n';
	}
}

void testgraf2(){
	cout << "Lista De Adiacenta:";

	pair<vector< vector<int> >, int> graf = adiacentaL();

	for(int i = 0; i < graf.second; ++i){
		cout << i << ": ";
		for(int j = 0; j < graf.first[i].size(); ++j){
			cout << graf.first[i][j] << ' ';
		}
		cout << '\n';
	}
}

void bfs(pair<vector< vector<int> >, int> graf){
	queue<int> q;
	vector<bool> visited(graf.second, false);
	q.push(1);
	visited[1] = true;
	cout << "Parcurgere BF: \n";
	while(!q.empty()){
		int top = q.front();
		q.pop();
		for(int i = 0; i < graf.first[top].size(); ++i){
			if(visited[graf.first[top][i]] == false){
				q.push(graf.first[top][i]);
				visited[graf.first[top][i]] = true;
			}
		}
		cout << top << ' ';
	}
	cout << '\n';
}

void dfs(pair<vector< vector<int> >, int> graf){
	stack<int> s;
	vector<bool> visited(graf.second, false);
	s.push(1);
	visited[1] = true;
	cout << "Parcurgere DF: \n";
	while(!s.empty()){
		int top = s.top();
		s.pop();
		for(int i = 0; i < graf.first[top].size(); ++i){
			if(visited[graf.first[top][i]] == false){
				s.push(graf.first[top][i]);
				visited[graf.first[top][i]] = true;
			}
		}
		cout << top << ' ';
	}
	cout << '\n';
}

int main(){
	//testgraf1();
	//testgraf2();
	pair<vector< vector<int> >, int> graf = adiacentaL();
	bfs(graf);
	dfs(graf);
	
}