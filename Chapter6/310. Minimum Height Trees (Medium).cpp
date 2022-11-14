 class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (const auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool>visted(n, false);
        queue<int> q; q.push(0);
        visted[0] = true;
        int node;
        while (!q.empty()) {
            node = q.front(); q.pop();
            for (int next: graph[node]) {
                if (!visted[next]) {
                    q.push(next);
                    visted[next] = true;
                }
            }
        }

        vector<int> parant(n);
        visted.assign(n, false);
        int root = node;
        q.push(node);
        visted[node] = true;
        while(!q.empty()) {
            node = q.front(); q.pop();
            for (int next: graph[node]) {
                if (!visted[next]) {
                    q.push(next);
                    visted[next] = true;
                    parant[next] = node;
                }
            }
        }

        parant[root] = -1;
        vector<int> path;
        while (node != -1) {
            path.push_back(node);
            node = parant[node];
        }
        int len = path.size();
        if (len % 2) {
            return {path[len / 2]};
        }
        return {path[len / 2 - 1], path[len / 2]};
    }
};
