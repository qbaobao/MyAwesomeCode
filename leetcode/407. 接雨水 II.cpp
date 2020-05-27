#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cctype>
#include <unordered_map>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

struct point3D {
	int x,y,z;
	bool operator < (point3D& p1, point3D& p2) {
		return p1.z < p2.z;
	}
};
int trapRainWater(vector<vector<int>>& heightMap) {
	int row = heightMap.size();
	int col = heightMap[0].size();
	priority_queue<point3D> q;
	vector<vector<bool>> exit(row, vector<int>(col, false));

	for (int i = 0; i < col; i++) {
		q.push({0, i, heightMap[0][i]});
		q.push({row - 1, i, heightMap[row - 1][i]});
		exit[0][i] = true;
		exit[row - 1][i] = true;
	}
	for (int i = 0; i < row; i++) {
		q.push({i, 0, heightMap[i][0]});
		q.push({i, col - 1, heightMap[i][col - 1]});
		exit[i][0] = true;
		exit[i][col - 1] = true;
	}
	int index[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int res = 0;
	while (!q.empty()) {
		point3D p(1001, 1001, 1001);
		for (int i = 0; i < 3; i++) {
			int x = q.top().x + index[i][0];
			int y = q.top().y + index[i][1];
			p = (p < q.top()) ? q.top() : p;
			if (!exit[x][y]) {
				q.push({x, y, heightMap[x][y]});
			}
		}
		if (heightMap[p.x][p.y] > heightMap[q.top().x][q.top().y]) {
			res += heightMap[p.x][p.y] - heightMap[q.top().x][q.top().y];
			heightMap[q.top().x][q.top().y] = heightMap[p.x][p.y];
			exit[q.top().x][q.top().y] = true;
		}
		q.pop();
	}
	return res;
}


int main()
{
	vector<int> tmp1 = { 12, 13, 1, 12 };
	vector<int> tmp2 = { 13, 4, 13, 12 };
	vector<int> tmp3 = { 13, 8, 10, 12 };
	vector<int> tmp4 = { 12, 13, 12, 12 };
	vector<vector<int>> heightMap = {tmp1, tmp2, tmp3, tmp4};

	int res = trapRainWater(heightMap);
	cout << res << endl;
 	cout << endl;
	return 0;
}