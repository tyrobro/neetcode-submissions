class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inD(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto& pre: prerequisites){
            inD[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inD[i] == 0) {
                q.push(i);
            }
        }

        int fin = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            fin++;

            for(int nei : adj[node]){
                inD[nei]--;
                if(inD[nei] == 0){
                    q.push(nei);
                }
            }
        }

        return fin == numCourses;

    }
};
