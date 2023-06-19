#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    int num_cases, count = 0, num_people, i;
    char spoken_language[MAX_LENGTH], language[MAX_LENGTH];
    bool different = false;
    char c;

    scanf("%d", &num_cases);
    getchar();

    while (count < num_cases) {
        scanf("%d", &num_people);
        getchar();

        for (i = 0; i < num_people; i++) {
            fgets(language, MAX_LENGTH, stdin);
            language[strcspn(language, "\n")] = '\0';

            if (i == 0) {
                strcpy(spoken_language, language);
            } else if (strcmp(language, spoken_language) != 0) {
                different = true;
            }
        }

        if (different) {
            printf("ingles\n");
        } else {
            printf("%s\n", spoken_language);
        }

        different = false;
        count++;
    }

    return 0;
}
