#include <iostream>

class SearchTree
{
    private:
        struct Node
        {
            int data;
            struct Node* left;
            struct Node* right;

            Node(int val) 
            {
                data = val;
                left = right = NULL;
            }
        };

        struct Node* root;

        void inordertravasal(struct Node* temp);
        void preordertravasal(struct Node* temp);
        void postordertravasal(struct Node* temp);

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

    SearchTree tree;
    int ch = 0, val = 0, check = -1, loop = 1;

    while(loop)
    {
        std::cout << "1.Insert Value \n2.Inorder \n3.Preorder \n4.Postorder \n5.Search \n6.Exit \n";
        std::cout << "Enter your choice: ";
        std::cin  >> ch;

        switch (ch)
        {
        case 1:
            std::cout << "Enter the value: ";
            std::cin  >> val;
            tree.insert(val);

            break;
        
        case 2:
            std::cout << "Inorder Travasal: ";
            tree.inorder();

            break;

        case 3:
            std::cout << "preorder Travasal: ";
            tree.preorder();

            break;

        case 4:
            std::cout << "postorder Travasal: ";
            tree.postorder();

            break;

        case 5:
            std::cout << "Enter value to search: ";
            std::cin  >> val;

            check = tree.search(val);

            if(check == 1) {
                std::cout << "The value is present.\n";
            }
            else if (check == 0)
            {
                std::cout << "The value is not present\n";
            }
            

            break;

        case 6:
            loop = 0;

            break;

        default:
            std::cout << "Inavlid choice!!\n";

            break;
        }
        std::cout << std::endl;
    }
    return 0;
}

void SearchTree::insert(int val)
{
    struct Node* newnode = new Node(val);

    if (root == NULL) {
        root = newnode;
        return;
    }

    struct Node* temp = root;

    while(true)
    {
        if (temp->data > val) {

            if (temp->left == NULL) {
                temp->left = newnode;
                return;
            }
            temp = temp->left;
        }
        else {

            if (temp->right == NULL) {
                temp->right = newnode;
                return;
            }
            temp = temp->right;
        }
    }
}


void SearchTree::inorder()
{
    inordertravasal(root);
    std::cout << std::endl;
}

void SearchTree::inordertravasal(struct Node* temp)
{
    if (temp == NULL) {
        return;
    }

    inordertravasal(temp->left);
    std::cout << temp->data << " ";
    inordertravasal(temp->right);
}


void SearchTree::preorder()
{
    preordertravasal(root);
    std::cout << std::endl;
}

void SearchTree::preordertravasal(struct Node* temp)
{
    if (temp == NULL) {
        return;
    }

    std::cout << temp->data << " ";
    preordertravasal(temp->left);
    preordertravasal(temp->right);
}


void SearchTree::postorder()
{
    postordertravasal(root);
    std::cout << std::endl;
}

void SearchTree::postordertravasal(struct Node* temp)
{
    if (temp == NULL) {
        return;
    }
    
    postordertravasal(temp->left);
    postordertravasal(temp->right);
    std::cout << temp->data << " ";
}

int SearchTree::search(int val)
{
    if (root == NULL) {
        std::cout << "The tree is empty!!\n";
        return -1;
    }

    struct Node* temp = root;

    while(temp != NULL)
    {
        if (temp->data > val) {

            temp = temp->left;
        }
        else if (temp->data < val) {

            temp = temp->right;
        }
        else if (temp->data == val) {
            return 1;
        }
    }
    return 0; 
}