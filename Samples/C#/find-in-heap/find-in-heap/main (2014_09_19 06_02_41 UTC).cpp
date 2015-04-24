#include <stdio.h>
#include <time.h>
using namespace std;

template<int max, class N>
int find_in_heap(N* T, N x) {
	return search_heap<max>(T, x, 0);
}

template<int max, class N>
int search_heap(N* T, N x, int i) {
	if (i >= max || T[i] < x) return -1;
	if (T[i] == x) return i;
	int next = i ? 2 * i : 1;
	int k = search_heap<max>(T, x, next);
	return k + 1 ? k : search_heap<max>(T, x, ++next);
}

int main(int argv, char* argc[]) {
	const int n = 35;
	int a[n], i = n;
	clock_t start = clock();
	for (int i = n; i > 0; i--) {
		a[n - i] = i * 5;
		printf("[%d] value %i: %i\r\n", clock() - start, i * 5, find_in_heap<n>(a, i * 5));
	}
	printf("start: %i, end: %i, time used: %d\r\naverage: %d\r\n", start, clock(), clock() - start, (clock() - start)/n);
}
