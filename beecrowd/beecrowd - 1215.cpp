#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char word[201];
    struct node *next;
} Node;

Node *insert(Node *list, char *word) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memoria.\n");
        return list;
    }
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (list == NULL) {
        return newNode;
    } else {
        Node *aux = list;
        Node *prev = NULL;
        while (aux != NULL && strcmp(aux->word, word) < 0) {
            prev = aux;
            aux = aux->next;
        }
        if (prev == NULL) {
            newNode->next = list;
            return newNode;
        } else {
            prev->next = newNode;
            newNode->next = aux;
            return list;
        }
    }
}

char correctLetter(char letter) {
    if (letter >= 'A' && letter <= 'Z') {
        return letter + 32;
    }
    return letter;
}

void printList(Node *list) {
    Node *aux = list;
    while (aux != NULL) {
        printf("%s\n", aux->word);
        aux = aux->next;
    }
}

int search(Node *list, char *word) {
    Node *aux = list;
    while (aux != NULL) {
        if (strcmp(aux->word, word) == 0) {
            return 1;
        }
        aux = aux->next;
    }
    return 0;
}

int main() {
    char line[201];
    Node *list = NULL;

    while (fgets(line, sizeof(line), stdin) != NULL) {
        int i, len = strlen(line);
        char word[201];
        int index = 0;

        for (i = 0; i < len; i++) {
            char letter = line[i];
            if (isalpha(letter)) {
                word[index++] = correctLetter(letter);
            } else if (index > 0) {
                word[index] = '\0';

                if (search(list, word) == 0) {
                    list = insert(list, word);
                }

                index = 0;
            }
        }
    }

    printList(list);

    return 0;
}