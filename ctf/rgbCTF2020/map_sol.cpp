#include <bits/stdc++.h>
using namespace std;

const int n = 200000;
struct edge {
	int v;
	long long w;
	string s;
};

vector <edge> near[n + 5];
long long d[n + 5];
pair <int, string> trace[n + 5];

struct cmp_min {
	bool operator () (const int &i, const int &j) {
		return d[i] > d[j];
	}
};

priority_queue <int, vector <int>, cmp_min> heap;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("map.txt", "r", stdin);
	for (int i = 1; i <= n; ++i) {
		int u, v, w;
		string s;
		cin >> u >> v >> w >> s;
		near[u].emplace_back(edge({v, w, s}));
		near[v].emplace_back(edge({u, w, s}));
	}
	// dijkstra heap
	for (int i = 2; i <= n; ++i)  // d[i] độ dài đường đi ngắn nhất từ nhà đến đỉnh i, ban đầu chưa biết nên mình để là một số rất lớn
		d[i] = 1e18;  // d[0] = 0 tức độ dài đường đi ngắn nhất từ nhà về nhà = 0, tất nhiên rồi :3
	heap.emplace(1);
	while (!heap.empty()) {
		int u = heap.top();
		heap.pop();
		if (u == n)  // Khi đi tới cửa hàng thì dừng luôn, khỏi bàn cãi :v
			break;
		for (edge &t: near[u]) {  
			int v = t.v, w = t.w;  
			if (d[v] > d[u] + w) {  // Nếu độ dài đường đi ngắn nhất từ 0 đến đỉnh u cộng độ dài cạnh (u, v) 
				d[v] = d[u] + w;   // ngắn hơn độ dài đường đi ngắn nhất từ 0 đến đỉnh v thì cập nhật d[v]
				heap.emplace(v);
				trace[v] = {u, t.s};  // Gán truy vết của v bằng u kèm với chuỗi s
			}
		}
	}
	// trace
	string flag = "";
	int u = n;
	while (u > 1) {
		flag = trace[u].second + flag;
		u = trace[u].first;
	}
	cout << flag;
}
