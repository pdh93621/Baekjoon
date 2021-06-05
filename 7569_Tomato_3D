#include <iostream>
#include <vector>
#define EMPTY 0

using namespace std;
__int8 dm[6] = {1,-1,0,0,0,0};
__int8 dn[6] = {0,0,1,-1,0,0};
__int8 dh[6] = {0,0,0,0,1,-1};

typedef struct Node {
	int m;
	int n;
	int h;
	struct Node* link;
}Queue;

Queue* Getnode() {
	Queue* New;
	New = (Queue*)malloc(sizeof(Queue));
	New->link = EMPTY;
	return New;
}

void Push(Queue** Head, Queue** Rear, int h, int n, int m) {
	if (*Head) {
		(*Rear)->link = Getnode();
		*Rear = (*Rear)->link;
		(*Rear)->h = h;
		(*Rear)->m = m;
		(*Rear)->n = n;
	}
	else {
		*Head = Getnode();
		*Rear = *Head;
		(*Rear)->h = h;
		(*Rear)->m = m;
		(*Rear)->n = n;
	}
}
void Pop(Queue** Head) {
	if (*Head) {
		Queue* temp;
		temp = *Head;
		*Head = (*Head)->link;
		free(temp);
	}
}

int main() {
	Queue* Head = EMPTY;
	Queue* Rear = EMPTY;
	int M;
	int N;
	int H;
	cin >> M;
	cin >> N;
	cin >> H;
	
	vector<vector<vector<int> > > box(H, vector<vector<int>>(N, vector<int>(M)));
	vector<vector<vector<int> > > vis(H, vector<vector<int>>(N, vector<int>(M)));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {				
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					Push(&Head, &Rear, i, j, k);					
					vis[i][j][k] = 1;
				}
			}
		}
	}
	while (Head) {
		int nh;
		int nn;
		int nm;
		for (int a = 0; a < 6; a++) {
			nh = Head->h + dh[a];
			nn = Head->n + dn[a];
			nm = Head->m + dm[a];
			if (nh >= 0 && nh < H && nn >= 0 && nn < N && nm >= 0 && nm < N) {
				if (!box[nh][nn][nm] && !vis[nh][nn][nm]) {
					Push(&Head, &Rear, nh, nn, nm);
					vis[nh][nn][nm] = vis[Head->h][Head->n][Head->m] + 1;
				}
			}
		}
		Pop(&Head);		
	}

	return 0;
}
