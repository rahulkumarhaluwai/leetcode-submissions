class Solution {
public:
    int solve(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        long long prev = arr[0];
        long long prev2 = 0;

        for (int i = 1; i < n; i++) {
            long long pick = arr[i];
            if (i > 1) pick += prev2;

            long long nonPick = prev;
            long long cur = max(pick, nonPick);

            prev2 = prev;
            prev = cur;
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> arr1, arr2;

        for (int i = 0; i < n; i++) {
            if (i != 0) arr1.push_back(nums[i]);
            if (i != n - 1) arr2.push_back(nums[i]);
        }

        return max(solve(arr1), solve(arr2));
    }
};
