class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int>v(n+1);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i] == key){
                int start = max(0, i - k);
                int end = min(n, i + k + 1);
                v[start]++;
                v[end]--;
            }
        }
        int sum =0;
        for(int i=0;i<=n;i++){
            sum += v[i];
            if(sum) ans.push_back(i);
        }
        return ans;
    }
};
