class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int size = n * n;
        int xr = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                xr ^= grid[i][j];
                xr ^= (i * n + j + 1);
            }
        }
        int number = xr & ~(xr - 1);

        int zero = 0;
        int one = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((grid[i][j] & number) != 0) {
                    one ^= grid[i][j];
                } else {
                    zero ^= grid[i][j];
                }
            }
        }
        for (int i = 1; i <= size; i++) {
            if ((i & number) != 0) {
                one ^= i;
            } else {
                zero ^= i;
            }
        }
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == zero) {
                    count++;
                }
            }
        }
        if (count == 2) {
            return {zero, one};
        }

        return {one, zero};
    }
};
