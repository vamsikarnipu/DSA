#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_count=0,l=0,r=0,zeros=0;
        while(r<nums.size())
        {
            if(nums[r]==0)zeros++;
            while(zeros>k)
            {
                if(nums[l]==0)zeros--;
                l++;
            }
            if(zeros<=k)
            {
                max_count=max(max_count,r-l+1);
            }
            r++;
        }      
        return max_count;
    }
};


int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {1,1,1,0,0,0,1,1,1,1,0};
    int k1 = 2;
    cout << "Example 1 Output: " << solution.longestOnes(nums1, k1) << endl;
    
    // Example 2
    vector<int> nums2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};  // Add this line
    int k2 = 3;
    cout << "Example 2 Output: " << solution.longestOnes(nums2, k2) << endl;
    
    return 0;
}