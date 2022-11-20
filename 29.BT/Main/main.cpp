#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }
    Node *temp = new Node(d);
    temp->left = buildTree();
    temp->right = buildTree();
    return temp;
}

// printing!
void printPre(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printPre(root->left);
    printPre(root->right);
}
void printIn(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printIn(root->left);
    cout << root->data << " ";
    printIn(root->right);
}

void printPost(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout << root->data << " ";
}

// levelOrder
//  heigth of the tree
int heigth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftH = heigth(root->left);
    int rightH = heigth(root->right);
    return max(leftH, rightH) + 1;
}

void printKthLevel(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
    return;
}
void printAllLevels(Node *root)
{
    for (int i = 1; i <= heigth(root); i++)
    {
        printKthLevel(root, i);
        cout << "\n";
    }
}

// breath first search
void BFS(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *t = q.front();
        cout << t->data << " ";
        q.pop();
        if (t->left)
        {
            q.push(t->left);
        }
        if (t->right)
        {
            q.push(t->right);
        }
    }
}

void levelOrderUsingBFS(Node *root)
{

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *t = q.front();
        q.pop();
        if (t == NULL)
        {
            cout << "\n";
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
        }
    }
}

// Sum of all nodes data
int sum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->data + sum(root->left) + sum(root->right);
}
// number of nodes in the tree
int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
// diameter of the tree

int dia(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int mid = heigth(root->left) + heigth(root->right);
    int left = dia(root->left);
    int right = dia(root->right);
    int fff = max(mid, max(left, right));
    return fff;
}

// sum replace problem
int sumRe(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL and root->right == NULL)
    {
        return root->data;
    }
    int x = root->data;
    root->data = sumRe(root->left) + sumRe(root->right);
    return root->data + x;
}

// function to check is tree is balanced?
class HBPair
{
public:
    int heigth;
    bool balance;
};

HBPair isHeightBalanced(Node *root)
{
    HBPair p;
    if (root == NULL)
    {
        p.balance = true;
        p.heigth = 0;
        return p;
    }
    HBPair left = isHeightBalanced(root->left);
    HBPair right = isHeightBalanced(root->right);
    p.heigth = max(left.heigth, right.heigth) + 1;
    if (abs(left.heigth - right.heigth) <= 1 and left.balance and right.balance)
    {
        p.balance = true;
    }
    else
    {
        p.heigth = false;
    }
    return p;
}

// built height balance BT from array
Node *builtTreeFromArray(int *a, int s, int e)
{
    // base case
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    Node *root = new Node(a[mid]);
    root->left = builtTreeFromArray(a, s, mid - 1);
    root->right = builtTreeFromArray(a, mid + 1, e);
    return root;
}
int main()
{
    Node *root = buildTree();
    cout << sumRe(root) << "\n";
    levelOrderUsingBFS(root);

    // printPre(root);
    // cout << "\n";
    // printIn(root);
    // cout << "\n";
    // printPost(root);
    // cout << "Heigth: " << heigth(root) << "\n";
    // cout << sum(root) << "\n";
    // cout << countNodes(root) << "\n";
    // cout << sumRe(root) << "\n";
    // printPre(root);
    // cout << dia(root) << "\n";
    // HBPair x = isHeightBalanced(root);
    // cout << x.balance << "\n";
    // int A[] = {1, 2, 3, 4, 5, 6, 7};
    // Node *root = builtTreeFromArray(A, 0, 6);
    // levelOrderUsingBFS(root);
}