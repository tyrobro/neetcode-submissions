/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mp;

        for(auto x: intervals){
            mp[x.start]++;
            mp[x.end]--;
        }

        int curr = 0;
        int ans = 0;

        for(auto& [k, v]: mp){
            curr += v;
            ans = max(ans, curr);
        }
        return ans;
    }
};
