#include <stdio.h>
#include "btree.h"

int main() {
    struct node *root = NULL;
    int option, val;

    do {
        printf("\n ****** BST ADT MENU ******* \n");
        printf("\n 1. Insert Node");
        printf("\n 2. Display Inorder Traversal");
        printf("\n 3. Display Preorder Traversal");
        printf("\n 4. Postorder Traversal");
        printf("\n 5. Find Height of Tree");
        printf("\n 6. Find Height of a Node");
        printf("\n 7. Count Internal Nodes");
        printf("\n 8. Count External Nodes");
        printf("\n 9. Check Existence");
        printf("\n 10. Exit");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n Enter the value : ");
                scanf("%d", &val);
                root = create_bst(root, val);
                break;
            case 2:
                printf("\n Inorder : ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("\n Preorder : ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("\n Postorder : ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("\n Height of Tree: %d\n", findHeight(root));
                break;
            case 6: {
                printf("\n Enter node value : ");
                scanf("%d", &val);
                int h = nodeHeight(root, val);
                if(h == -1) printf(" Node not found.\n");
                else printf(" Height of node %d: %d\n", val, h);
                }
                break;
            case 7:
                printf("\n Internal Nodes: %d\n", countInternalNodes(root));
                break;
            case 8:
                printf("\n External Nodes: %d\n", countExternalNodes(root));
                break;
            case 9:
                printf("\n Enter value to search : ");
                scanf("%d", &val);
                if(exists(root, val)) printf(" %d exists in tree.\n", val);
                else printf(" %d does not exist.\n", val);
                break;
        }
    } while (option != 10);

    return 0;
}
