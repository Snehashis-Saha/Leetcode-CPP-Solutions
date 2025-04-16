class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long ans = 0;
        long long pairs = 0;
        int l = 0;

        for (int r = 0; r < nums.size(); ++r) {
            pairs += mp[nums[r]];
            mp[nums[r]]++;

            while (pairs >= k) {
                ans += nums.size() - r;
                mp[nums[l]]--;
                pairs -= mp[nums[l]];
                l++;
            }
        }
        return ans;
    }
};
