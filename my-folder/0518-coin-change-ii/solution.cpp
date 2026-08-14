class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long> prev(amount + 1, 0);

        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0)
                prev[target] = 1;
        }

        for (int ind = 1; ind < n; ind++) {
            vector<long long> cur(amount + 1, 0);

            for (int target = 0; target <= amount; target++) {
                long long notTaken = prev[target];
                long long taken = 0;

                if (coins[ind] <= target)
                    taken = cur[target - coins[ind]];

                if (notTaken > INT_MAX - taken)
                    cur[target] = INT_MAX;
                else
                    cur[target] = notTaken + taken;
            }

            prev = cur;
        }

        return (int)prev[amount];
    }
};
