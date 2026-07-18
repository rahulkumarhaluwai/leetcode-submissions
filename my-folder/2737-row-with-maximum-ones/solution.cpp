class Solution {
public:
    int lowerBound(vector<int>& arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int index = 0;
        int maxOnes = 0;

        for (int i = 0; i < mat.size(); i++) {
            int cnt = 0;
            for (int x : mat[i]) {
                cnt += x;
            }

            if (cnt > maxOnes) {
                maxOnes = cnt;
                index = i;
            }
        }

        return {index, maxOnes};
    }
};
