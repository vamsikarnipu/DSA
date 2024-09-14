#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0,r=0;
        double ans=INT_MIN,sum=0;
        while(r<nums.size())
        {
            sum+=nums[r];
            if(r>=k-1)
            {
               double avg=sum/k;
               ans=max(avg,ans);
               sum-=nums[l];
               l++;
            }
            r++;
        }
        return ans;
        
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int k = 3;
    cout<<s.findMaxAverage(nums,k);
}

