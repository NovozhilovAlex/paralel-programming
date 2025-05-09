#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

void heavy_task(int idx) {
  for (int i = 1; i < 1e8; i++) {
    sqrt(i);
  }
  printf("\tThread #%d finished\n", idx);
}

void sequential(int threads_num) {
  for (int i = 0; i < threads_num; i++) {
    printf("MAIN: starting thread %d\n", i);
    heavy_task(i);
  }
}

int main(int argc, char** argv) {
  struct timeval start, end;
  gettimeofday(&start, NULL);
  int threads_num = atoi(argv[1]);
  sequential(threads_num);
  gettimeofday(&end, NULL);
  long seconds = end.tv_sec - start.tv_sec;
  long micros = end.tv_usec - start.tv_usec;
  if (micros < 0) {
      seconds--;
      micros += 1000000;
  }

  double time = seconds * 1000.0 + micros / 1000.0;
  printf("Время выполнения %d потоками (последовательно): %.2f мс\n", threads_num, time);
  return 0;
}
