#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    static bool comp(const vector<int>& a, const vector<int>& b) {
        if (a[0] < b[0]) return true;
        if (a[0] == b[0]) return a[1] > b[1];
        return false;
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        
        if (intervals.empty()) return merged;

        // Sort the intervals using the custom comparator
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<int> temp = intervals[0];
        for (const auto& interval : intervals) {
            if (interval[0] <= temp[1]) {
                // Overlapping intervals, merge them
                temp[1] = max(temp[1], interval[1]);
            } else {
                // Non-overlapping interval, push the previous interval and update
                merged.push_back(temp);
                temp = interval;
            }
        }
        // Add the last interval
        merged.push_back(temp);
        
        return merged;
    }
};
