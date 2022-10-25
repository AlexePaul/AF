#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("maxarea.in");
ofstream fout("maxarea.out");

class Solution {
public:

    int di[4] = {1,0,-1,0};
    int dj[4] = {0,1,0,-1};

    void fill(vector<vector <int> >& mat, int i, int j, int& count){
        if(mat[i][j] == 1){
            count++;
            mat[i][j] = 0;
            for(int k = 0; k < 4; ++k){
                if(di[k] + i >= 0 && di[k]+i < mat.size() && dj[k] + j >= 0 && dj[k]+j < mat[i].size()){
                    fill(mat, di[k] + i, dj[k]+j, count);
                }
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int> >& grid) {
        int maxC = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                if(grid[i][j] == 1){
                    int count = 0;
                    fill(grid, i, j, count);
                    if(count > maxC){
                        maxC = count;
                    }
                }
            }
        }
        return maxC;
    }
}o;

int main() {
    int n,m;
    fin >> n >> m;
    vector< vector <int> > grid(n);
    for(int i = 0; i < n; ++i){
        grid[i].resize(m);
        for(int j = 0; j < m; ++j){
            fin >> grid[i][j];
        }
    }
    fout << o.maxAreaOfIsland(grid);
}
