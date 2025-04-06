class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        sort(nums.begin(), nums.end());
        
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxIndex = 0, maxLen = 1;

        for(int i=1; i<n; ++i){
            for(int j=0; j<i; ++j){
                if(nums[i] % nums[j] == 0 && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
                if(dp[i] > maxLen){
                    maxLen = dp[i];
                    maxIndex = i;
                }
            }
        }
        vector<int> result;
        while(maxIndex != -1){
            result.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
