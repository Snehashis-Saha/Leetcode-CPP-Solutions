class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Step 1: If any number < k, it's impossible
        for (int num : nums) {
            if (num < k) return -1;
        }

        // Step 2: Count distinct elements > k
        unordered_set<int> greater;
        for (int num : nums) {
            if (num > k) greater.insert(num);
        }

        // Step 3: Each operation removes one such distinct value
        return greater.size();
    }
};
