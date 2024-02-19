#include<iostream>
#include<queue>	
#include<tuple>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

char board[1000][1000];
// dist[x][y][0] : 벽을 하나도 부수지 않고 (x,y)까지 오는데 걸리는 비용
// dist[x][y][1] : 벽을 하나만 부수고 (x,y)까지 오는데 걸리는 비용, (x,y)가 벽이라서 부수는 경우 포함
int dist[1000][1000][2];

int n, m;

int bfs() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dist[i][j][0] = dist[i][j][1] = -1;

    dist[0][0][0] = dist[0][0][1] = 1; // 시작

    queue<tuple<int, int, int>> q;
    q.push({ 0,0,0 });

    // 이동가능한 지점(0)으로 계속 이동을 하되 벽(1)이 있으면 부수고 최소 거리를 체크해본다
    while (!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front();        
        q.pop();

        // 도착지점인 경우
        if (x == n - 1 && y == m - 1) return dist[x][y][broken];
        
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;

            // 1.벽을 부수지 않고 이동한 거리
            if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.push({ nx, ny, broken });
            }
            
            // 2.벽을 한번 부수고 이동한 거리
            // 0인지점(이동가능한 곳)이면서 그 다음칸이 벽이면서 그 벽을 한번도 부순적이 없는 경우
            if (!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = dist[x][y][1] + 1;
                // 벽을 부수고 이동한 지점에서 상하좌우를 검사하는 경우에 벽을 한 번더 부술 수 없으므로 0인 지점만 이동가능하다                
                q.push({ nx, ny, 1 });
            }
        }

    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];
    cout << bfs();
    return 0;
}