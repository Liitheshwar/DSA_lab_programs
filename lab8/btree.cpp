#include <iostream>

using namespace std;

class BinaryTree {
    private:
        struct node {
            char data;
            struct node* left;
            struct node* right;
        };

        struct node* root;

        void inorderTraversal(struct node* temp);
        void preorderTraversal(struct node* temp);
        void postorderTraversal(struct node* temp);
        bool searchNode(struct node* temp, char val);
    public:
        BinaryTree()
        {
            root = NULL;
        }
        void insert(char val);
        void inorder();
        void preorder();
        void postorder();
        bool search(char val);
    
    private:
        
};

int main() {
    BinaryTree tree;
    int loop = 1, ch = 0;
    char val;

    while (loop) {
        cout << "\n####### Binary Tree #######\n";
        cout << "1. Insert\n"
             << "2. Inorder Traversal\n"
             << "3. Preorder Traversal\n"
             << "4. Postorder Traversal\n"
             << "5. Search\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter the character value: ";
                cin >> val;
                tree.insert(val);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 3:
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case 4:
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
            case 5:
                cout << "Enter the character to search: ";
                cin >> val;
                if (tree.search(val)) {
                    cout << "Element found!\n";
                } else {
                    cout << "Element not found!\n";
                }
                break;
            case 6:
                loop = 0;
                break;
            default:
                cout << "Invalid input!!!\n";
                break;
        }
    }

    return 0;
}

void BinaryTree::insert(char val) {
    struct node* newNode = new struct node;
    newNode->data = val;
    newNode->left = newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
        return;
    }

    struct node* temp = root;
    char direction;

    while (true) {
        cout << "Insert " << val << " to left or right of " << temp->data << " (l/r): ";
        cin >> direction;

        if (direction == 'l') {
            if (temp->left == NULL) {
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        } else if (direction == 'r') {
            if (temp->right == NULL) {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }
}

void BinaryTree::inorder() {
    inorderTraversal(root);
    cout << endl;
}

void BinaryTree::inorderTraversal(struct node* temp) {
    if (temp) {
        inorderTraversal(temp->left);
        cout << temp->data << " ";
        inorderTraversal(temp->right);
    }
}

void BinaryTree::preorder() {
    preorderTraversal(root);
    cout << endl;
}

void BinaryTree::preorderTraversal(struct node* temp) {
    if (temp) {
        cout << temp->data << " ";
        preorderTraversal(temp->left);
        preorderTraversal(temp->right);
    }
}

void BinaryTree::postorder() {
    postorderTraversal(root);
    cout << endl;
}

void BinaryTree::postorderTraversal(struct node* temp) {
    if (temp) {
        postorderTraversal(temp->left);
        postorderTraversal(temp->right);
        cout << temp->data << " ";
    }
}

bool BinaryTree::search(char val) {
    return searchNode(root, val);
}

bool BinaryTree::searchNode(struct node* temp, char val) {
    if (!temp) {
        return false;
    }
    if (temp->data == val) {
        return true;
    }
    return searchNode(temp->left, val) || searchNode(temp->right, val);
}