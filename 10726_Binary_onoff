#include <iostream>
#include <cstdio>

using namespace std;

int Power_of_Two(int N) {
	
	if (N) {
		
		return 2*Power_of_Two(N - 1);
	}
	else {
		return 1;
	}
}

int main() {
	int TC;
	int N;
	int M;

	cout << "The number of Test Case : ";
	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		cout << "Enter N M : ";
		cin >> N >> M;
		for (int j = 1; j <= N+1; j++) {
			if (j == N + 1) {
				printf("#%d ON\n", i);
				break;
			}
			if (M % 2) {
				M /= 2;
			}
			else {
				printf("#%d OFF\n", i);
				break;
			}

		}
		
	}
	return 0;
}
