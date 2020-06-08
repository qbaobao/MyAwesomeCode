class Solution {
public:
    struct  Node {
        int x;
        int y;
        Node(int x, int y) : x(x), y(y) {}
        Node() {}
        bool operator < (const Node& n) const
        {
            return x < n.x || (x == n.x && y < n.y);
        }
    };
    struct Route
    {
        int step;
        string path;
        Route(int step, string path) : step(step), path(path) {}
        Route() {}
    };
    
    int GetNextCordition(const Node& n, Node& nextN, const vector<vector<int>>& maze, int i)
    {
        int newX = n.x + index[i][0];
        int newY = n.y + index[i][1];
        int step = 0;
        while (newX >= 0 && newX < maze.size() &&
               (newY >= 0 && newY < maze[0].size()) &&
               maze[newX][newY] != 1) {
            step++;
            nextN.x = newX;
            nextN.y = newY;
            if (maze[newX][newY] == 2) {
                break;
            }
            newX += index[i][0];
            newY += index[i][1];
        }
        return step;
    }
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        queue<Node> q;
        map<Node, Route> nodeInfo;
        Node n1(ball[0], ball[1]);
        Route r1(0, "");
        q.push(n1);
        nodeInfo[n1] = r1;
        maze[hole[0]][hole[1]] = 2;

        while (!q.empty()) {
            Node n = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                Node nextN;
                int step = GetNextCordition(n, nextN, maze, i);
                if (step == 0) {
                    continue;
                }
                Route r(nodeInfo[n].step + step, nodeInfo[n].path + indexS[i]);
                if (!nodeInfo.count(nextN)) {
                    nodeInfo[nextN] = r;
                    q.push(nextN);
                } else if (nodeInfo[nextN].step > r.step || (nodeInfo[nextN].step == r.step && nodeInfo[nextN].path > r.path)) {
                    nodeInfo[nextN].step = r.step;
                    nodeInfo[nextN].path = r.path;
                    q.push(nextN);
                }
            }
        }
        n1.x = hole[0];
        n1.y = hole[1];
        if (nodeInfo.count(n1)) {
            return nodeInfo[n1].path;
        }
        return "impossible";
    }

private:
    static constexpr int index[4][2] = {
        {1, 0},
        {0, -1},
        {0, 1},
        {-1, 0}
    };
    static constexpr char indexS[4] = {'d', 'l', 'r', 'u'};
};