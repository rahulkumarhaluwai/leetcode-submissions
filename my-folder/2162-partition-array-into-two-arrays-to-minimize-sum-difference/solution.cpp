class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;
        vector<vector<int>> left(half + 1);
        vector<vector<int>> right(half + 1);
        int total = 0;
        for (int x : nums)
            total += x;
        for (int mask = 0; mask < (1 << half); mask++) {
            int sum = 0;
            int cnt = 0;
            for (int i = 0; i < half; i++) {
                if (mask & (1 << i)) {
                    sum += nums[i];
                    cnt++;
                }
            }
            left[cnt].push_back(sum);
        }
        int rightSize = n - half;
        for (int mask = 0; mask < (1 << rightSize); mask++) {
            int sum = 0;
            int cnt = 0;
            for (int i = 0; i < rightSize; i++) {
                if (mask & (1 << i)) {
                    sum += nums[half + i];
                    cnt++;
                }
            }
            right[cnt].push_back(sum);
        }
        for (int i = 0; i <= rightSize; i++)
            sort(right[i].begin(), right[i].end());

        int ans = INT_MAX;
        for (int cnt = 0; cnt <= half; cnt++) {
            int need = half - cnt;

            for (int sumLeft : left[cnt]) {
                int target = total / 2 - sumLeft;

                auto it = lower_bound(
                    right[need].begin(),
                    right[need].end(),
                    target
                );

                if (it != right[need].end()) {
                    int sum1 = sumLeft + *it;
                    int sum2 = total - sum1;

                    ans = min(ans, abs(sum1 - sum2));
                }

                if (it != right[need].begin()) {
                    --it;

                    int sum1 = sumLeft + *it;
                    int sum2 = total - sum1;

                    ans = min(ans, abs(sum1 - sum2));
                }
            }
        }

        return ans;
    }
};
