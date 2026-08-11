class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        const int MOD = 1e9 + 7;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();
            if (dis > dist[node])
                continue;
            for (auto [adjNode, edgeWeight] : adj[node]) {
                long long newDist = dis + edgeWeight;
                if (newDist < dist[adjNode]) {
                    dist[adjNode] = newDist;
                    ways[adjNode] = ways[node];
                    pq.push({newDist, adjNode});
                }
                else if (newDist == dist[adjNode]) {
                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};
