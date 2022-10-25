#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int n, m;
	vector<int> visited;
	vector<int> nivel;
	vector<int> nivel_min;
	vector<vector<int> > edges;
	vector<vector<int> > result;
    vector<vector<int> > criticalConnections(int n, vector<vector<int> >& connections) {
        this->n = n;
        edges.resize(n+1);
        for(int i = 0; i < connections.size(); ++i){
        	edges[connections[i][1]].push_back(connections[i][0]);
        	edges[connections[i][0]].push_back(connections[i][1]);		
        }
        reset();
        dfs(0);
        for(int i = 0; i < n; ++i){
        	cout << nivel_min[i] << ' ';
        }
        return result;
    }

    void reset(){
    	result.clear();
    	visited.clear();
    	visited.resize(n+1);
    	nivel.clear();
    	nivel.resize(n+1);
    	nivel_min.clear();
    	nivel_min.resize(n+1);
    	fill(nivel_min.begin(), nivel_min.end(), INT_MAX);
    }

    void dfs(int node){
    	visited[node] = 1;
    	nivel_min[node] = nivel[node];
    	for(int i = 0; i < edges[node].size(); ++i){
    		if(!visited[edges[node][i]]){
    			nivel[edges[node][i]] = nivel[node]+1;
    			dfs(edges[node][i]);
    			nivel_min[node] = min(nivel_min[node],nivel_min[edges[node][i]]);
    			if(nivel_min[edges[node][i]] > nivel[i]){
    				vector<int> r;
    				r.push_back(node);
    				r.push_back(edges[node][i]);
    				result.push_back(r);
    			}
    		}
    		else if(nivel[edges[node][i]] < nivel[node]-1){
    			nivel_min[node] = min(nivel_min[node], nivel[edges[node][i]]);
    		}
    	}
    }
}o;

int main(){
	ifstream fin("criticalConnections.in");
	ofstream fout("criticalConnections.out");
	int n,m;
	vector<vector<int> > edges;
	fin >> n >> m;
	edges.resize(m+1);
	for(int i = 0; i < m; ++i){
		int x,y;
		fin >> x >> y;
		edges[i].resize(3);
		edges[i][0] = y;
		edges[i][1] = x;
	}	
	vector<vector<int> > r = o.criticalConnections(n, edges);
	for(int i = 0; i < r[1].size(); ++i){
		cout << '\n' << r[1][i] << ' ' << r[2][i];
	}
}