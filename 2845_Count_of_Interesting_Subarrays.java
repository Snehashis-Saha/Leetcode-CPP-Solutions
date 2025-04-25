class Solution {
    public long countInterestingSubarrays(List<Integer> nums, int modulo, int k) {
        Map<Integer, Long> freq = new HashMap<>();
        freq.put(0, 1L);  // empty prefix is valid

        long res = 0;
        int prefix = 0;

        for (int num : nums) {
            if (num % modulo == k) {
                prefix++;
            }

            int target = (prefix - k + modulo) % modulo;
            res += freq.getOrDefault(target, 0L);

            int modValue = prefix % modulo;
            freq.put(modValue, freq.getOrDefault(modValue, 0L) + 1);
        }

        return res;
    }
}