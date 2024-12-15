#include <stdio.h>
#include <stdlib.h>
struct BST {
    int data;
    struct BST *left, *right;
};
typedef struct BST NODE;
NODE* createNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
NODE* insertNode(NODE* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}
NODE* searchNode(NODE* root, int data) {
    if (root == NULL) return NULL;
    if (data == root->data) return root;
    return (data < root->data) ? searchNode(root->left, data) : searchNode(root->right, data);
}
NODE* findMin(NODE* root) {
    while (root && root->left) root = root->left;
    return root;
}
NODE* deleteNode(NODE* root, int data) {
    if (root == NULL) return root;
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            NODE* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NODE* temp = root->left;
            free(root);
            return temp;
        }
        NODE* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorder(NODE* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(NODE* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(NODE* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    NODE* root = NULL;
    int data, choice, n, i;
    while (1) {
        printf("\n1. Insert Element\n2. Search Element\n3. Delete Element\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter number of elements: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter element: ");
                    scanf("%d", &data);
                    root = insertNode(root, data);
                }
                break;
            case 2:
                printf("\nEnter element to search: ");
                scanf("%d", &data);
                NODE* result = searchNode(root, data);
                if (result != NULL) {
                    printf("Element %d found.\n", result->data);
                } else {
                    printf("Element %d not found.\n", data);
                }
                break;
            case 3:
                printf("\nEnter element to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 4:
                printf("\nInorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("\nPreorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("\nPostorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid choice, try again.\n");
        }
    }
    return 0;
}
