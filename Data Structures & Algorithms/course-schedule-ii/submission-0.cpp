class Solution {
public:
    vector<int> out;
    vector<int> inD;
    vector<vector<int>> adj;

    void dfs(int node) {
        out.push_back(node);
        inD[node]--;

        for(int nei : adj[node]){
            inD[nei]--;
            if(inD[nei] == 0){
                dfs(nei);
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj = vector<vector<int>>(numCourses);
        inD = vector<int>(numCourses, 0);

        for(auto& pre: prerequisites){
            inD[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }        

        for(int i = 0; i < numCourses; i++){
            if(inD[i] == 0){
                dfs(i);
            }
        }

        if(out.size() != numCourses) return {};
        return out;
    }
};
