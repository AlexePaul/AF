// incerc sa colorez graful in 2 culori:
// 	->daca reusesc inseamna ca este un graf bipartit
// 	->daca nu reusesc inseamna ca nu este graf bipartit
// colorez folosind un BFS 
// O(n*k) unde: -> n este numarul de noduri
//				-> k este numarul de componente conexe
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector <int> >& dislikes) {
        vector<int> team(10000);
        queue<int> q;
        vector<vector <int> > dislikesAg(10000);
        for(int i = 0; i < dislikes.size(); ++i){
        	dislikesAg[dislikes[i][0]].push_back(dislikes[i][1]);
        	dislikesAg[dislikes[i][1]].push_back(dislikes[i][0]);
        }
   		q.push(1);
        while(!q.empty()){
        	int fr = q.front();
        	if(team[fr] == 0)
        			team[fr] = 1;
        	for(int i = 0; i < dislikesAg[fr].size(); ++i){
        		if(team[fr] == 1){
        			if(team[dislikesAg[fr][i]] == 0){
        				team[dislikesAg[fr][i]] = 2;
        				q.push(dislikesAg[fr][i]);
        				continue;
        			}
        			if(team[dislikesAg[fr][i]] == 1)
        				return false;
        		}
        		if(team[fr] == 2){
        			if(team[dislikesAg[fr][i]] == 0){
        				team[dislikesAg[fr][i]] = 1;
        				q.push(dislikesAg[fr][i]);
        				continue;
        			}
        			if(team[dislikesAg[fr][i]] == 2)
        				return false;
        		}
        	}
        	q.pop();
        	if(q.empty()){
        		// acest for este motivul de ce am O(n*k)
        		for(int i = 1; i <= n; ++i){ 
        			if(team[i] == 0){
        				q.push(i);	
        				break;
        			}
        		}
        	}
        }
        return true;
    }
    vector<vector<int> > possibleBipartitionB(int n, vector<vector <int> >& dislikes) {
    vector<int> team(10000);
    queue<int> q;
    vector<vector <int> > dislikesAg(10000);
    vector<vector <int> > ans;
    ans.resize(2);
    for(int i = 0; i < dislikes.size(); ++i){
    	dislikesAg[dislikes[i][0]].push_back(dislikes[i][1]);
    	dislikesAg[dislikes[i][1]].push_back(dislikes[i][0]);
    }
		q.push(1);
    while(!q.empty()){
    	int fr = q.front();
    	if(team[fr] == 0)
    			team[fr] = 1;
    	for(int i = 0; i < dislikesAg[fr].size(); ++i){
    		if(team[fr] == 1){
    			if(team[dislikesAg[fr][i]] == 0){
    				team[dislikesAg[fr][i]] = 2;
    				q.push(dislikesAg[fr][i]);
    				continue;
    			}
    			if(team[dislikesAg[fr][i]] == 1)
    				return ans;
    		}
    		if(team[fr] == 2){
    			if(team[dislikesAg[fr][i]] == 0){
    				team[dislikesAg[fr][i]] = 1;
    				q.push(dislikesAg[fr][i]);
    				continue;
    			}
    			if(team[dislikesAg[fr][i]] == 2)
    				return ans;
    		}
    	}
    	q.pop();
    	if(q.empty()){
    		// acest for este motivul de ce am O(n*k)
    		for(int i = 1; i <= n; ++i){ 
    			if(team[i] == 0){
    				q.push(i);	
    				break;
    			}
    		}
    	}
    }

    for(int i = 1; i <= n; ++i){
    	ans[team[i]].push_back(i);
    }

    return ans;
	}

}o;

int main() {
	vector<vector <int> > dislikes;
	int nrDislikes,a,b,n;
	cin >> n >> nrDislikes;
	dislikes.resize(nrDislikes-1);
	for(int i = 0; i < nrDislikes; ++i){
		cin >> a >> b;
		dislikes[i].resize(3);
		dislikes[i][1] = a;
		dislikes[i][2] = b;
	}

	cout << o.possibleBipartition(n,dislikes);
	return 0; 
}