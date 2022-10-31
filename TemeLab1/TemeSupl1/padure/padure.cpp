#include <bits/stdc++.h>

using namespace std;

ifstream fin("padure.in");
ofstream fout("padure.out");

pair<int, int> mat[1005][1005];
pair<int, int> start;
pair<int, int> finish;
int n,m;
int di[] = {0,1,0,-1};
int dj[] = {1,0,-1,0};

void bfs(){
	deque<pair<int, int> > q;
	q.push_back(make_pair(start.first, start.second));
	mat[start.first][start.second].second = 0;
	while(!q.empty()){
		pair<int,int> f = q.front();
		q.pop_front();
		for(int i = 0; i < 4; ++i){
			if(f.first + di[i]>=0 && f.first + di[i] < n && f.second + dj[i]>=0 && f.second + dj[i] < m && mat[f.first][f.second].second < mat[f.first + di[i]][f.second + dj[i]].second){
				if(mat[f.first + di[i]][f.second + dj[i]].first != mat[f.first][f.second].first){
					mat[f.first + di[i]][f.second + dj[i]].second = min(mat[f.first+di[i]][f.second+dj[i]].second,mat[f.first][f.second].second + 1);
					q.push_back(make_pair(f.first + di[i],f.second + dj[i]));
				}
				else{
					mat[f.first + di[i]][f.second + dj[i]].second = min(mat[f.first+di[i]][f.second+dj[i]].second,mat[f.first][f.second].second);
					q.push_front(make_pair(f.first + di[i],f.second + dj[i]));
				}
			}
		}
		if(f.first == finish.first && f.second == finish.second)
			return;
	}
}

int main(){
	fin >> n >> m >> start.first >> start.second >> finish.first >> finish.second;
	start.first--;
	start.second--;
	finish.first--;
	finish.second--;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			fin >> mat[i][j].first;
			mat[i][j].second = INT_MAX;
		}
	}
	bfs();
	fout << mat[finish.first][finish.second].second<< '\n';
	// for(int i = 0; i < n; ++i){
	// 	for(int j = 0; j < m; ++j){
	// 		fout << mat[i][j].second << ' ';
	// 	}
	// 	fout << '\n';
	// }
}