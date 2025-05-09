#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void loop(float a[], float b[], float c[]) 
{
    for (int i=0; i<4; i++) {
        c[i] = a[i] * b[i];
    }
}

int main(int argc, char** argv) {
    clock_t start = clock();
    int iterations_num = atoi(argv[1]);
    float a[] = {5.1, 6.3, 4.8, 4.2};
    float b[] = {1.3, 5.9, 3.2, 8.1};
    float c[4] = {0.0};
    for (int i=0; i<iterations_num; i++) {
        loop(a, b, c);
    }
    clock_t end = clock();
    double time = ((double) (end - start) / CLOCKS_PER_SEC) * 1e3;
    printf("Время выполнения: %d, количество итераций: %.2f мс \n", iterations_num, time);

    return 0;
}