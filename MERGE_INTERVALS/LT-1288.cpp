class Solution {
   static bool comp(vector<int>&a,vector<int>&b)
    {
        if(a[0]<b[0])return true;
        if(a[0]==b[0])return a[1]>b[1];
        return false;
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<int>temp=intervals[0];
        int count=intervals.size();
        for(int i=1;i<intervals.size();i++)
        {
            if(temp[0]<=intervals[i][0] && intervals[i][1]<=temp[1])
            {
               count--;
            }
            else
            {
                temp=intervals[i];
            }
        }
        return count;

    }
};