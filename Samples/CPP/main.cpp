#include <stdio.h>
#include <time.h>
using namespace std;

template<int max, class N>
int find_in_heap(N* T, N x) {
	return search_heap<max>(T, x, 0);
}

template<int max, class N>
int search_heap(N* T, N x, int i) {
	if (i >= max) return -1;
	if (T[i] == x) return i;
	if (T[i] < x) return -1;
	int next = 2 * i;
	if (!i) ++next;
	int k = search_heap<max>(T, x, next);
	if (k > 0) return k;
	return search_heap<max>(T, x, ++next);
}

int main() {
	const int n = 30;
	int a[n];
	clock_t start;
	for (int i = n; i > 0; i--) {
		a[n-i] = i * 5;
	}
	for (int i = n; i > 0; i=i-2) {
		start = clock();
		printf("a[%i] = %i\r\n", find_in_heap<n>(a, i * 5), i * 5);
		printf("start: %i, end: %i\r\n", start, clock());
	}
}