class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> bestTime(n, vector<int>(m, INT_MAX));

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        priority_queue<tuple<int, int, int, int>,vector<tuple<int, int, int, int>>,greater<>> pq;

        pq.emplace(0, 0, 0, 0); 
        bestTime[0][0] = 0;

        while (!pq.empty()) {
            auto [time, r, c, steps] = pq.top();
            pq.pop();

            if (r == n - 1 && c == m - 1) return time;
            if (time > bestTime[r][c]) continue;

            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                int delay = max(moveTime[nr][nc] - time, 0);
                int cost = (steps % 2 == 0) ? 1 : 2;
                int arrivalTime = time + delay + cost;

                if (arrivalTime < bestTime[nr][nc]) {
                    bestTime[nr][nc] = arrivalTime;
                    pq.emplace(arrivalTime, nr, nc, steps + 1);
                }
            }
        }

        return -1;
    }
};
