#pragma warning(disable: 4996) 
#include <stdio.h>
using namespace std;

long long int DynamicArray[101][10];

int main(void) {

	// 길이가 1이고 끝자리가 i인 숫자의 개수
	for (int i = 1; i <= 9; i++) {
		DynamicArray[1][i] = 1;
	}

	int N;
	scanf("%d" , &N);

	for (int i = 2; i <= N; i++) {

		// endNum이 0이나 9인 경우는 한 방향으로 밖에 추가가 안됌

		DynamicArray[i][0] = DynamicArray[i - 1][1];
		DynamicArray[i][9] = DynamicArray[i - 1][8];

		for (int endNum = 1; endNum <= 8; endNum++) {
			DynamicArray[i][endNum] = 
				DynamicArray[i - 1][endNum - 1] + DynamicArray[i-1][endNum+1];
			DynamicArray[i][endNum] %= 1000000000;
		
		}
	}

	long long int ans = 0;

	for (int endNum = 0; endNum <= 9; endNum++) {
		ans += DynamicArray[N][endNum];
		ans %= 1000000000;
	}

	printf("%lld\n", ans);
}