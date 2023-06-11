#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int a, b;
        scanf("%d %d", &a, &b);

        int c[b];
        for (int j = 0; j < b; j++) {
            scanf("%d", &c[j]);
        }

        for (int i = 0; i < a; i++) {
            printf("%d -> ", i);
            for (int j = 0; j < b; j++) {
                if (c[j] % a == i) {
                    printf("%d -> ", c[j]);
                }
            }
            printf("\\\n");
        }

        if (n > 0) {
            printf("\n");
        }
    }

    return 0;
}