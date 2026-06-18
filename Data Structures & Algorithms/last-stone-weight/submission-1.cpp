class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(int x: stones){
            maxHeap.push(x);
        }

        while(maxHeap.size() > 1){
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();

            if(x == y){
                continue;
            }
            if(x < y){
                maxHeap.push(y-x);
            } 
            if(y < x){
                maxHeap.push(x - y);
            }
        }

        if(maxHeap.size() == 1){
            return maxHeap.top();
        } else {
            return 0;
        }
    }
};
