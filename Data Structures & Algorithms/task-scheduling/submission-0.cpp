class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);

        for(char task: tasks){
            count[task-'A']++;
        }

        sort(count.begin(), count.end());
        int maxF = count[25];
        int idle = (maxF - 1)*n;

        for(int i = 24; i >=0; i--){
            idle -= min(maxF - 1, count[i]);
        }

        return max(0, idle) + tasks.size();
    }
};
