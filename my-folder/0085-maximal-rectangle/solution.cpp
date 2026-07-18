class Solution {
public:
    int largestRectangleArea(vector<int>& matrix) {
        stack<int> st;
        int maxArea = 0;

        matrix.push_back(0);

        for (int i = 0; i < matrix.size(); i++) {
            while (!st.empty() && matrix[i] < matrix[st.top()]) {
                int height = matrix[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        matrix.pop_back();
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix[0].size();
        vector<int> height(m, 0);
        int maxArea = 0;

        for (auto& row : matrix) {
            for (int i = 0; i < m; i++) {
                if (row[i] == '1')
                    height[i]++;
                else
                    height[i] = 0;
            }

            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }
};
