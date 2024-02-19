#include<iostream>
#include<queue>	
#include<tuple>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

char board[1000][1000];
// dist[x][y][0] : ���� �ϳ��� �μ��� �ʰ� (x,y)���� ���µ� �ɸ��� ���
// dist[x][y][1] : ���� �ϳ��� �μ��� (x,y)���� ���µ� �ɸ��� ���, (x,y)�� ���̶� �μ��� ��� ����
int dist[1000][1000][2];

int n, m;

int bfs() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dist[i][j][0] = dist[i][j][1] = -1;

    dist[0][0][0] = dist[0][0][1] = 1; // ����

    queue<tuple<int, int, int>> q;
    q.push({ 0,0,0 });

    // �̵������� ����(0)���� ��� �̵��� �ϵ� ��(1)�� ������ �μ��� �ּ� �Ÿ��� üũ�غ���
    while (!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front();        
        q.pop();

        // ���������� ���
        if (x == n - 1 && y == m - 1) return dist[x][y][broken];
        
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;

            // 1.���� �μ��� �ʰ� �̵��� �Ÿ�
            if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.push({ nx, ny, broken });
            }
            
            // 2.���� �ѹ� �μ��� �̵��� �Ÿ�
            // 0������(�̵������� ��)�̸鼭 �� ����ĭ�� ���̸鼭 �� ���� �ѹ��� �μ����� ���� ���
            if (!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = dist[x][y][1] + 1;
                // ���� �μ��� �̵��� �������� �����¿츦 �˻��ϴ� ��쿡 ���� �� ���� �μ� �� �����Ƿ� 0�� ������ �̵������ϴ�                
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