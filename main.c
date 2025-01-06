#include <stdio.h>
#include <stdlib.h>

int ePrim(int n) {
    if (n <= 1) return 0;
    for(int d = 2; d <= n / 2; d++) {
        if(n % d == 0) {
            return 0;
        }
    }
    return 1;
}

void statisticaPrime(int v[], int* n) {
    int contor = 0;
    int originalN = *n;

    for (int i = 0; i < originalN; i++) {
        if (ePrim(v[i]) == 1) {
            contor++;
            int mutare = contor;

            for (int j = *n - 1; j > i; j--) {
                v[j + mutare] = v[j];
            }

            for (int j = 0; j < mutare; j++) {
                v[i + j + 1] = v[i];
            }

            *n += mutare;
            i += mutare;
            originalN += mutare;
        }
    }
}

int main(void) {
    int v[20] = {8, 2, 3, 6, 5, 10, 17};
    int n = 7;

    statisticaPrime(v, &n);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}