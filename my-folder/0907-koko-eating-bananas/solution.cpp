class Solution {
public:
    int findMax(vector<int>& piles) {
        int maxi = INT_MIN;
        for (int pile : piles)
            maxi = max(maxi, pile);
        return maxi;
    }

    long long calculateTotalHours(vector<int> &piles, int hourly){
    long long totalH = 0;
    for (int pile : piles){
        totalH += (1LL * pile + hourly - 1) / hourly;
    }
    return totalH;
}

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (calculateTotalHours(piles, mid) <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};
