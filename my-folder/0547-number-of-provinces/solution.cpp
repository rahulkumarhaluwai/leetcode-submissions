class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;

        for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
            if (isConnected[node][neighbor] == 1 && !visited[neighbor]) {
                dfs(neighbor, isConnected, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> visited(V, 0);
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, isConnected, visited);
            }
        }

        return count;
    }
};
