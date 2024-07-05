#include <iostream>
#include <unistd>
#include <sys/wait.h>

using namespace std;

const int N = 3;

void multiplyMatrices(int A[N][N], int B[N][N], int C[N][N], int row) {
    for (int i = 0; i < N; i++) {
        C[row][i] = 0;
        for (int j = 0; j < N; j++) {
            C[row][i] += A[row][j] * B[j][i]:

        }
    }
}

int main() {
    int A[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[N][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int C[N][N];

    for (int i = 0; i < N; i++) {
        int pid = fork();
        if (pid == 0) {
            multiplyMatrices(A, B, C, i);
            _exit(0);
        }
    }

    for (int i = 0; i < N; i++) {
        wait(NULL);
    }

    cout << "Result matrix C:" << end1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << C[i][j] << " ";
        }

        cout << end1;
    }

    return 0;
}