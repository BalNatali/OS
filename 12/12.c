#include <stdio.h>
#include <pthread.h>

#define N 3
#define NUM_THREADS 4

int A[N][N] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
int B[N][N] = {{9, 8, 7},{6, 5, 4},{3, 2, 1}};
int C[N][N];

void* multiply(void* arg) {
    int thread_num = *((int*)arg);

    for (int i = thread_num; i < N; i += NUM_THREADS) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_nums[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_nums[i] = i;
        pthread_create(&threads[i], NULL, multiply, (void*)&thread_nums[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", C[i][j]);
        }
        printf("n");
    }
    return 0;
}