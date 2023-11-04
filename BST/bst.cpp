#include <iostream>
#include <cmath>
#include <string.h>
#define SPACE 10
using namespace std;

struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node()
    {

        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{

public:
    Node *root;

    BST()
    {
        this->root = NULL;
    }

    bool isBstNull()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // insertion

    void insert(int value)
    {
        Node *newNode = new Node(value);

        if (root == NULL)
        {
            root = newNode;
        }

        else
        {
            Node *curr;
            curr = root;
            while (curr != NULL)
            {

                if (newNode->data == curr->data)
                {
                    cout << "ERROR::NoDuplicates\nValue already exist" << endl;
                    return;
                }
                else if ((newNode->data < curr->data) && (curr->left == NULL))
                {
                    curr->left = newNode;
                    break;
                }
                else if (newNode->data < curr->data)
                {
                    curr = curr->left;
                }
                else if ((newNode->data > curr->data) && (curr->right == NULL))
                {
                    curr->right = newNode;
                    break;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
    }

    void print2D(Node *r, int space)
    {
        if (r == NULL) // Base case  1
            return;
        space += SPACE;           // Increase distance between levels   2
        print2D(r->right, space); // Process right child first 3
        cout << endl;
        for (int i = SPACE; i < space; i++) // 5
            cout << " ";                    // 5.1
        cout << r->data << "\n";            // 6
        print2D(r->left, space);            // Process left child  7
    }

    void preOrder(Node *n)
    {
        if (n == NULL)
        {
            return;
        }

        cout << n->data << " ";
        preOrder(n->left);
        preOrder(n->right);
    }
};

void printTree(Node *root, Trunk *prev, bool isRight)
{
    if (root == NULL)
        return;

    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->data << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

int main()
{

    BST tree;
    tree.insert(30);
    tree.insert(18);
    tree.insert(43);
    tree.insert(10);
    tree.insert(25);
    tree.insert(32);
    tree.insert(48);
    tree.print2D(tree.root, SPACE);
    cout << endl
         << endl
         << endl;
    printTree(tree.root, NULL, false);
    cout << endl
         << endl;
    tree.preOrder(tree.root);
    cout<<endl;
    return 0;
}
