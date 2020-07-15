#include <cstdio>

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n;
bool a[5005][5005];

void dfs(int i, int j) {
	a[i][j] = false;
	for (int k = 0; k < 4; ++k) {
		int x = i + dx[k];
		int y = j + dy[k];
		if (x < 1 || y < 1 || x > n || y > n || !a[x][y])
			continue;
		dfs(x, y);
	}
}

int main() {
	freopen("grid.txt", "r", stdin);
	n = 5000;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			char c;
			scanf("%c\n", &c);
			a[i][j] = c - '0';
		}
	int res = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (a[i][j]) {
				++res;
				dfs(i, j);
			}
	printf("%d", res);
}
