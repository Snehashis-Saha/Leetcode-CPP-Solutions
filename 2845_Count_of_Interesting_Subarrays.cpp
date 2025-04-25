class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> freq;
        freq[0] = 1;
        int prefixMod = 0;
        long long count = 0;

        for (int num : nums) {
            if (num % modulo == k)
                prefixMod++;

            int need = (prefixMod - k + modulo) % modulo;
            count += freq[need];

            freq[prefixMod % modulo]++;
        }

        return count;
    }
};