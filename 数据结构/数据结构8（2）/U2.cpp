#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int a[1001][1001] = { 0 };
int color[1001][2] = { 0 };
int num[1001];
int num1 = 0;

int main() {
	//7 9
	//1 2 1 4 2 3 3 4 2 5 4 5 2 6 5 7 6 7
	int v, e, x, y;
	cin >> v >> e; //输入节点数和边数
	for (int i = 0; i < e; i++) {
		cin >> x >> y; //输入e条边每条边对应的节点序号
		a[x][y] = 1;
		a[y][x] = 1;
	}
	deque<int> deq;
	deq.push_back(1);
	bool flag = false;
	while (!deq.empty()) {
		int cur = deq.front();  //cur存储当前所取节点的序号
		deq.pop_front(); //将该节点出队列
		int tmp = color[cur][0]; //tmp为该节点的颜色
		color[cur][1] = 2; //将该节点状态置为2（代表已设置颜色）
		for (int j = 1; j <= v; j++) { //寻找与cur相连的节点
			if (a[cur][j] == 1 && color[j][1] == 0) {  //j节点与cur节点之间有边，且颜色未被设置
				color[j][0] = 1 - tmp; //颜色取反
				color[j][1] = 2; //设置节点状态
				deq.push_back(j); //将该节点入队列
			}
			if (a[cur][j] == 1 && color[j][1] == 2) { //如果节点j颜色已被设置，判断颜色是否与tmp一致
				if (color[j][0] != (1 - tmp)) { //不一致
					flag = true;
					break;
				}
			}
		}
		if (flag) {
			num1 = -1;
			break;
		}
	}
	if (!flag) {
		num1 = 0;
		for (int k = 1; k <= v; k++) {
			if (color[k][0] == 1)
				num[num1++] = k;
		}
	}

	cout << "#：" << num1;
	for (int d = 0; d < num1; d++) {
		cout << " " << num[d];
	}
	cout << endl;
	return 0;
}
