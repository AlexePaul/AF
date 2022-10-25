// -> Fac o sortare topologica si marchez nodurile vizitate cu un "id"
//  acest "id" este in functie de nodul de pe care incep dfs-ul sortarii
//  daca se intampla vreodata sa ma intalnesc cu un nod care deja a fost 
//  vizitat de acelasi "id" inseamna ca am dat de un ciclu si nu mai are 
//  sens sa continui 
// -> O(n+m)


#include <iostream>
#include <vector>
#include <stack> 

using namespace std;

stack<int> s;
vector<int> visited;
vector<vector<int> >edges;
bool ok = true;

class Solution {
public:

	void topSortDfs(int node, int step){
		visited[node] = step;
		bool k = true;
		for(int i = 0; i < edges[node].size(); ++i){
			if(visited[edges[node][i]] == step){
				k = false;
				ok = false;
			}
			if(visited[edges[node][i]] == 0){
				topSortDfs(edges[node][i], step);
			}
		}
		if(k == true){
			visited[node] = -1;
		}
		s.push(node);
	}

    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {

    	edges.resize(numCourses+1);
    	vector<int> v;
    	std::fill(edges.begin(), edges.end(), v);
    	visited.resize(numCourses+1);
    	std::fill(visited.begin(), visited.end(), 0);
    	while(!s.empty()){
    		s.pop();
    	}
    	vector<int> result;

    	for(int i = 0; i < prerequisites.size(); ++i){
    		edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
    	}

    	ok = true;

    	for(int i = 0; i < numCourses; ++i){
    		if(visited[i] == 0){
    			topSortDfs(i,i+1);
    			if(ok == false){
    				while(!s.empty()){
			    		result.push_back(s.top());
			    		s.pop();
    				}	
    				return result;		
    			}
    		}
    	}

    	while(!s.empty()){
    		result.push_back(s.top());
    		s.pop();
    	}
    	return result;
    }
}o;

int main(){
	int n,nrpreq;
	vector<vector<int> > e;
	cin >> n;
	cin >> nrpreq;
	e.resize(nrpreq);
	for(int i = 0; i < nrpreq; ++i){
		e[i].resize(3);
		cin >> e[i][0] >> e[i][1];
	}
	 vector<int> v = o.findOrder(n,e);
	cout << '\n';
	for(int i = 0; i < v.size(); ++i){
		cout << v[i] << ' ';
	}
}