class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>vc;
        vector<int>temp=newInterval;
        for(auto it:intervals)
        {
            if(it[1]<temp[0])
            {
                vc.push_back(it);
            }
            else if(it[0]>temp[1])
            {
                vc.push_back(temp);
                temp=it;
            }
            else
            {
                temp[0]=min(temp[0],it[0]);
                temp[1]=max(temp[1],it[1]);
            }
            
        }
        vc.push_back(temp);
        return vc;
    }
        
    
};