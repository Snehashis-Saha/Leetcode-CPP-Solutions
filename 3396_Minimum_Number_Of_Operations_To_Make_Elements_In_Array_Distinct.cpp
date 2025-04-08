class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> seen;
        int duplicates = 0;

        for (int num : nums) {
            if (seen.count(num)) {
                duplicates++;  
            } else {
                seen.insert(num);
            }
        }

        int n = nums.size();
        int ops = 0;

        while (true) {
            unordered_set<int> s;
            bool hasDuplicate = false;
            for (int i = ops * 3; i < n; i++) {
                if (s.count(nums[i])) {
                    hasDuplicate = true;
                    break;
                }
                s.insert(nums[i]);
            }

            if (!hasDuplicate) break;
            ops++;
        }

        return ops;
    }
};
