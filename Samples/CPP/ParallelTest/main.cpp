#include <iostream>
#include <thread>
#include <stdlib.h>

void fn(int* val, int* root) {
    *val = (int)(val - root);
}

int main(int argc, char ** argv) {
    int n = 100000;
    if (argc == 2) n = atoi(argv[1]);

    std::cout << "Begin Parallel Test" << std::endl;
    int* arr = new int[n];
    int start = clock();
    std::thread* threads;
    for (int i = 0; i < n; i++) {
        threads = new std::thread(fn, &arr[i], arr);
    }
    threads->join();
    std::cout << arr[n-1] << " in " << clock() - start << std::endl;

    std::cout << "Begin Linear Test" << std::endl;
    int* arr2 = new int[n];
    start = clock();
    for (int i = 0; i < n; i++) {
        fn(&arr2[i], arr2);
    }
    std::cout << arr2[n-1] << " in " << clock() - start << std::endl;

    return 0;
}