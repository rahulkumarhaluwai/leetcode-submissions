class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int preSum = 0, cnt = 0;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            int remove = preSum - k;
            if (m.find(remove) != m.end()) {
                cnt += m[remove];
            }
            m[preSum]++;
        }
        return cnt;
    }
};
