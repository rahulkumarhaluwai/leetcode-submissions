class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;

        for (int num : nums)
            xorr ^= num;

        unsigned int rightmost = (unsigned int)xorr & (-(unsigned int)xorr);

        int b1 = 0, b2 = 0;

        for (int num : nums) {
            if ((unsigned int)num & rightmost)
                b1 ^= num;
            else
                b2 ^= num;
        }

        return {b1, b2};
    }
};
