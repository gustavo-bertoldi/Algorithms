#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n, int *memo) {

    if (n == 0) return 0;
    else if (n == 1) return 1;
    else if (memo[n] == 0) {
        memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    }
    return memo[n];

}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int *memo = (int*)calloc(n, sizeof(int));

    int ans = fibonacci(n, memo);
    printf("%d\n", ans);

    free(memo);
}

