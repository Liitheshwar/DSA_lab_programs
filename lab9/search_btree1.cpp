#include <iostream>

class SearchTree
{
    private:
        struct node
        {
            int data;
            struct node* left;
            struct node* right;

            node(int val)
            {
                data = val;
                left = right = NULL;
            }
        };

        struct node* root;

        void inordertravesal(struct node* temp);
        void preordertravesal(struct node* temp);
        void postordertravesal(struct node* temp);

    public:
        SearchTree()
        {
            root = NULL;
        }

        void insert(int val);
        void inorder();
        void preorder();
        void postorder();
        int search(int val);
};


int main() {
    SearchTree btree;

    int loop = 1, ch = 0;
    int val;

    while (loop) {
        std::cout << "\n####### Binary Search Tree #######\n";
        std::cout << "1. Insert\n"
             << "2. Inorder Traversal\n"
             << "3. Preorder Traversal\n"
             << "4. Postorder Traversal\n"
             << "5. Search\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        std::cin >> ch;

        switch (ch) {
            case 1:
                std::cout << "Enter the value: ";
                std::cin >> val;
                btree.insert(val);
                break;
            case 2:
                std::cout << "Inorder Traversal: ";
                btree.inorder();
                break;
            case 3:
                std::cout << "Preorder Traversal: ";
                btree.preorder();
                break;
            case 4:
                std::cout << "Postorder Traversal: ";
                btree.postorder();
                break;
            case 5:
                std::cout << "Enter the character to search: ";
                std::cin >> val;
                val = btree.search(val);
                if (val == 1) {
                    std::cout << "Element found!\n";
                } 
                else if (val == 0){
                    std::cout << "Element not found!\n";
                }
                break;
            case 6:
                loop = 0;
                break;
            default:
                std::cout << "Invalid input!!!\n";
                break;

        }
        std::cout << "##################################\n";
    }

    return 0;
}



void SearchTree::insert(int val)
{
    struct node* newnode = new node(val);

    if (root == NULL) {
        root = newnode;
        return;
    }

    struct node* temp = root;

    while (true)
    {
        if (temp->data < val) {
            if (temp->right == NULL) {
                temp->right = newnode;
                return;
            }
    
            temp = temp->right;
        }
        else if (temp->data > val) {
            if (temp->left == NULL) {
                temp->left = newnode;
                return;
            }
    
            temp = temp->left;
        }
        else {
            std::cout << "The value is already in the Tree!!\n";
            return;
        }
    }
}


void SearchTree::inorder()
{
    if (root == NULL) {
        std::cout << "The tree is empty.\n";
        return;
    }

    inordertravesal(root);
    std::cout << std::endl;
}

void SearchTree::inordertravesal(struct node* temp)
{
    if (temp == NULL) {
        return;
    }

    inordertravesal(temp->left);
    std::cout << temp->data << " ";
    inordertravesal(temp->right);
}


void SearchTree::preorder()
{
    if (root == NULL) {
        std::cout << "The tree is empty.\n";
        return;
    }

    preordertravesal(root);
    std::cout << std::endl;
}

void SearchTree::preordertravesal(struct node* temp) 
{
    if (temp == NULL) {
        return;
    }

    std::cout << temp->data << " ";
    preordertravesal(temp->left);
    preordertravesal(temp->right);
}


void SearchTree::postorder()
{
    if (root == NULL) {
        std::cout << "The tree is empty.\n";
        return;
    }

    postordertravesal(root);
    std::cout << std::endl;
}

void SearchTree::postordertravesal(struct node* temp)
{
    if (temp == NULL) {
        return;
    }

    postordertravesal(temp->left);
    postordertravesal(temp->right);
    std::cout << temp->data << " ";
}


int SearchTree::search(int val)
{
    if (root == NULL) {
        std::cout << "The tree is empty!!\n";
        return -1;
    }

    struct node* temp = root;

    while (true) 
    {
        if (temp->data == val) {
            return 1;
        }

        if (temp->data > val) {
            if (temp->left == NULL) {
                return 0;
            }
            temp = temp->left;
        }
        else {
            if (temp->right == NULL) {
                return 0;
            }
            temp = temp->right;
        }
    }
    return 0;
}