class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        vector<int> indeg(n,0);
        vector<bool> sus(n, false);

        // build our adj list forming edge from u to v
        for(auto &edge : invocations){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indeg[v]++;
        }

        // normal bfs traversal
        queue<int> q;
        q.push(k);
        sus[k] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto &ngbr : adj[curr]){
                indeg[ngbr]--;
                if(!sus[ngbr]){
                    sus[ngbr] = true;
                    q.push(ngbr);
                }    
            }
        }

        vector<int> res;
        bool cannot = false;
        for(int i =0; i < n; i++){
            if(sus[i] && indeg[i] > 0){
                cannot = true;
                break;
            }

            if(!sus[i]){
                res.push_back(i);
            }

        }

        if(cannot){
            vector<int> vec(n); 
            for(int i = 0; i<n; i++){
                vec[i] = i;
            }
            return vec;
        }
        return res;
    }
};