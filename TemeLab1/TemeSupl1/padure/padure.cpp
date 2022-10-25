#include <bits/stdc++.h>

using namespace std;

ifstream fin("padure.in");
ofstream fout("padure.out");

int n,m;
int mat[1000][1000];
pair <int, int> start,finish;
vector<int> frecv;
int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};

void Fill(int i, int j, int value, int s){
	mat[i][j] = value;
	for(int k = 0; k < 4; ++ k){
		if(i+di[k] >= 0 && i+di[k] < n && j+dj[k] >= 0 && j+dj[k] < m)
			if (mat[i+di[k]][j+dj[k]] == s)
				Fill(i+di[k], j+dj[k], value, s);
	}
}

int main(){
	fin >> n >> m;
	fin >> start.first >> start.second;
	fin >> finish.first >> finish.second;

	frecv.resize(1000);

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			fin >> mat[i][j];
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(mat[i][j] <= 104){
				Fill(i,j,frecv[mat[i][j]]*105 + mat[i][j], mat[i][j]);
			}
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}


