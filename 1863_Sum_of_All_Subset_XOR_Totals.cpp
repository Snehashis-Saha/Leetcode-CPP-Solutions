class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        int subsets = 1 << n;

        for(int bitX=0; bitX<subsets; bitX++){
            int sum = 0;
            for(int i=0; i<n; i++){
                if(bitX & (1 << i)){
                    sum ^= nums[i];
                }
            }
            total += sum;
        }
        return total;
    }
};
