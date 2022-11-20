#include <iostream>
#include <queue>
#include <climits>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *next;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }
    if (data <= root->data)
    {

        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
Node *built()
{
    int d;
    cin >> d;

    Node *root = NULL;
    while (d != -1)
    {
        root = insert(root, d);
        cin >> d;
    }
    return root;
}

// inorder print

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void bfs(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *t = q.front();
        if (t == NULL)
        {
            cout << "\n";
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << t->data << " ";
            if (t->left)
            {
                q.push(t->left);
            }
            if (t->right)
            {
                q.push(t->right);
            }
            q.pop();
        }
    }
    return;
}

Node *serach(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }

    if (key <= root->data)
    {
        return serach(root->left, key);
    }
    return serach(root->right, key);
}

Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
        return root;
    }
    else if (data == root->data)
    {
        // case 1.
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // case 2.
        if (root->left != NULL and root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->right != NULL and root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // case 3
        Node *replace = root->right;

        // find the inorder successor from right subtree.
        while (replace->left != NULL)
        {
            replace = replace->left;
        }

        root->data = replace->data;
        root->right = deleteNode(root->right, replace->data);

        return root;
    }
    else
    {
        root->right = deleteNode(root->right, data);
        return root;
    }
}

Node *deleteNode_(Node *root, int data)
{
    if (root == NULL)
    {
        delete root;
        return NULL;
    }
    else if (root->data < data)
    {
        root->left = deleteNode_(root->left, data);
        return root;
    }
    else if (root->data == data)
    {
        // case one
        if (root->right == NULL and root->left == NULL)
        {
            delete root;
            return NULL;
        }

        // case two

        if (root->right == NULL and root->left != NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->left == NULL and root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // case three
        Node *replace = root->right;

        while (replace->left != NULL)
        {
            replace = replace->left;
        }

        root->data = replace->data;

        root->right = deleteNode_(root->right, replace->data);
        return root;
    }
    root->right = deleteNode_(root->right, data);
    return root;
}

bool isBST(Node *root)
{
    if (root->left == NULL and root->right == NULL)
    {
        return 1;
    }
    else if (root->left and root->right)
    {
        if (root->data > root->left->data and root->data < root->right->data)
        {
            return isBST(root->left);
            return isBST(root->right);
        }
        else
        {
            return false;
        }
    }
    else if (root->left != NULL and root->right == NULL)
    {
        if (root->data > root->left->data)
        {
            return isBST(root->left);
        }
        else
        {
            return false;
        }
    }
    else if (root->left == NULL and root->right != NULL)
    {
        if (root->data < root->right->data)
        {
            return isBST(root->right);
        }
        else
        {
            return false;
        }
    }
}

bool isBST_(Node *root, int minV = INT_MIN, int maxV = INT_MAX)
{
    if (root == NULL)
    {
        return 1;
    }
    if (minV <= root->data <= maxV)
    {
        bool a = isBST_(root->left, minV, root->data);
        bool b = isBST_(root->right, root->data, maxV);
        if (a and b)
        {
            return 1;
        }
    }
    return 0;
}
void flattenBT(Node *root)
{
    
}
int main()
{
    Node *root = built();

    inorder(root);
    cout << "\n";

    if (isBST_(root))
    {
        cout << "Yes"
             << "\n";
    }
    else
    {
        cout << "NO"
             << "\n";
    }

    return 0;
}