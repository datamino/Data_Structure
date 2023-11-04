#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

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

    bool isBstNull(BST n)
    {
        if (n.root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

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
                    cout << "Value inserted Sucessfully." << endl;
                    break;
                }
                else if (newNode->data < curr->data)
                {
                    curr = curr->left;
                }
                else if ((newNode->data > curr->data) && (curr->right == NULL))
                {
                    curr->right = newNode;
                    cout << "Value inserted Sucessfully." << endl;
                    break;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
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

    Node *Search(Node *n, int value)
    {
        if (n == NULL || n->data == value)
            return n;

        else if (value < n->data)
            return Search(n->left, value);

        else
            return Search(n->right, value);
    }

    Node *minValueNode(Node *node)
    {
        Node *curr = node;
        while (curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr;
    }

    Node *deleteNode(Node *n, int value)
    {

        if (n == NULL)
        {
            return NULL;
        }

        else if (value < n->data)
        {
            n->left = deleteNode(n->left, value);
        }

        else if (value > n->data)
        {
            n->right = deleteNode(n->right, value);
        }

        else
        {

            if (n->left == NULL)
            {
                if (n == root)
                {
                    root = n->right;
                }

                Node *temp = n->right;
                delete n;
                return temp;
            }
            else if (n->right == NULL)
            {
                if (n == root)
                {
                    root = n->left;
                }
                Node *temp = n->left;
                delete n;
                return temp;
            }
            else
            {

                Node *temp = minValueNode(n->right);
                n->data = temp->data;
                n->right = deleteNode(n->right, temp->data);
            }
        }
        return n;
    }
};

void menu()
{

    cout << endl
         << "-------------------------------" << endl;
    cout << "\t\tMenu" << endl;
    cout << "-------------------------------" << endl;
    cout << "1) Check Empty." << endl;
    cout << "2) Insert." << endl;
    cout << "3) Search." << endl;
    cout << "4) Delete." << endl;
    cout << "5) Print Inorder." << endl;
    cout << "6) Exit." << endl;
    cout << "-------------------------------" << endl
         << endl;
}

int main()
{

    int choice, value;
    BST tree;
    while (1)
    {

        menu();
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (tree.isBstNull(tree))
            {
                cout << "BST is empty." << endl;
            }
            else
            {
                cout << "BST is not empty." << endl;
            }
            break;
        case 2:
            cout << "Enter your value to insert:";
            cin >> value;
            tree.insert(value);
            break;
        case 3:
            cout << "Enter your value to search:";
            cin >> value;

            if (tree.Search(tree.root, value) != NULL)
                cout << "Value found" << endl;
            else
                cout << "Value not found" << endl;
            break;
        case 4:
            cout << "Enter your value to delete:";
            cin >> value;
            if (tree.Search(tree.root, value) != NULL)
            {
                tree.deleteNode(tree.root, value);
                cout << value << " deleted sucessfully" << endl;
            }
            else
            {
                cout << "Can not Delete beacuse " << value << " is not present " << endl;
            }

            break;
        case 5:
            cout << "Inorder Traversal" << endl;
            tree.preOrder(tree.root);
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}
