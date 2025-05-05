#include <iostream>
#include <string>
#include <stack>

class BinaryTree
{
    private:
        struct Node
        {
            char data;
            struct Node* left;
            struct Node* right;

            Node(char ch){
                data = ch;
                left = right = NULL;
            }
        };

        struct Node* root;

        void inordertravasal(struct Node* temp);
        void preordertravasal(struct Node* temp);
        void postordertravasal(struct Node* temp);

    public:
        BinaryTree()
        {
            root = NULL;
        }

        void construct(std::string str);
        void inorder();
        void preorder();
        void postorder();
};

void BinaryTree::construct(std::string str)
{
    int check = 0;
    std::string valid_str = str;

    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') && i > 1) {
            check--;
            check--;
            check++;
        }
        else {
            check++;
        }
    }

    if (check != 1) {
        std::cout << "Invalid expression!!\n";
        return;
    }

    if (str != "\0") {
        
        std::stack<struct Node*> stk;

        for (int i = 0; i < len; i++) {
            if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') {
                struct Node* newnode = new Node(str[i]);

                struct Node* x = stk.top();
                stk.pop();
                struct Node* y = stk.top(); 
                stk.pop();

                newnode->left = y;
                newnode->right = x;

                stk.push(newnode);
            }
            else {
                struct Node* newnode = new Node(str[i]);
                stk.push(newnode);
            }
        }

        root = stk.top();
    }
    else {
        std::cout << "Provide a postfix expression\n";
    }
}

void BinaryTree::inorder()
{
    inordertravasal(root);
    std::cout << std::endl;
}

void BinaryTree::inordertravasal(struct Node* temp)
{
    if (temp == NULL) {
        return;
    }

    inordertravasal(temp->left);
    std::cout << temp->data << " ";
    inordertravasal(temp->right);
}


void BinaryTree::preorder()
{
    preordertravasal(root);
    std::cout << std::endl;
}

void BinaryTree::preordertravasal(struct Node* temp)
{
    if (temp == NULL) {
        return;
    }

    std::cout << temp->data << " ";
    preordertravasal(temp->left);
    preordertravasal(temp->right);
}


void BinaryTree::postorder()
{
    postordertravasal(root);
    std::cout << std::endl;
}

void BinaryTree::postordertravasal(struct Node* temp)
{
    if (temp == NULL) {
        return;
    }
    
    postordertravasal(temp->left);
    postordertravasal(temp->right);
    std::cout << temp->data << " ";
}