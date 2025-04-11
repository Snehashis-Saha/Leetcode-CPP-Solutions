class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i <= high; i++){
            string s = to_string(i);
            int n = s.length();

            if(n % 2 != 0){
                continue;
            }

            int half = n/2;
            int sum1 = 0, sum2 = 0;

            for(int j = 0; j < half; j++){
                sum1 += s[j] - '0';
            }

            for(int j = half; j < n; j++){
                sum2 += s[j] - '0';
            }

            if(sum1 == sum2){
                count++;
            }
        }
        return count;
    }
};
