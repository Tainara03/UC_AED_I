#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

typedef struct TreeNode {
    char letter;
    struct TreeNode* right;
    struct TreeNode* left;
} TreeNode;

TreeNode* newNode(char letter);
void showPostfix(TreeNode* tree);
int findIndex(char* str, int start, int end, char letter);
TreeNode* buildTree(char* infix, char* prefix, int inStart, int inEnd);

short indexCounter;

int main() {
    short numCases;
    short numNodes, i;
    char prefix[MAXSIZE], infix[MAXSIZE];

    scanf("%hu", &numCases);

    while (numCases--) {
        scanf("%hu %s %s%*c", &numNodes, prefix, infix);
        indexCounter = 0;
        TreeNode* root = buildTree(infix, prefix, 0, numNodes - 1);
        showPostfix(root);
        printf("\n");
    }
}

TreeNode* newNode(char letter) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->letter = letter;
    node->left = node->right = NULL;
    return node;
}

int findIndex(char* str, int start, int end, char letter) {
    short i;
    for (i = start; i <= end; ++i) {
        if (str[i] == letter) {
            return i;
        }
    }
    return -1;
}

TreeNode* buildTree(char* infix, char* prefix, int inStart, int inEnd) {
    int infixIndex;

    if (inStart > inEnd) {
        return NULL;
    }

    TreeNode* node = newNode(prefix[indexCounter++]);
    if (inStart == inEnd) {
        return node;
    }

    infixIndex = findIndex(infix, inStart, inEnd, node->letter);
    node->left = buildTree(infix, prefix, inStart, infixIndex - 1);
    node->right = buildTree(infix, prefix, infixIndex + 1, inEnd);

    return node;
}

void showPostfix(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    showPostfix(node->left);
    showPostfix(node->right);
    printf("%c", node->letter);
}
