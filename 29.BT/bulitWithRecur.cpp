/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>
#include <queue>

using namespace std;

class HBPair
{
public:
    int height;
    bool balance;
};

class Pair
{
public:
    int height;
    int diameter;
};

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node() {}
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *builtTree()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    Node *t = new Node(data);
    t->left = builtTree();
    t->right = builtTree();
    return t;
}

void printInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
void printPreorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
void printPostorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}
int height(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int l = height(head->left);
    int r = height(head->right);

    return max(l, r) + 1;
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
}
void printLevelOrder(Node *root)
{
    int h = height(root);
    for (int i = 0; i <= h; i++)
    {
        printKthLevel(root, i);
        cout << "\n";
    }
}
void BFS(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int i = 7;
    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}
void BFS_(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        if (temp == NULL)
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
            cout << temp->data << " ";
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int sumNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}
int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int a = height(root->left) + height(root->right);
    int b = diameter(root->right);
    int c = diameter(root->left);

    return max(a, max(b, c));
}
Pair diameterOptimize(Node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }
    Pair left = diameterOptimize(root->left);
    Pair right = diameterOptimize(root->right);

    p.height = 1 + max(left.height, right.height);
    p.diameter = max(max(left.diameter, right.diameter), left.height + right.height);
    return p;
}
int sumOfNodes(Node *root)
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
    root->data = sumOfNodes(root->left) + sumOfNodes(root->right);
    return x + root->data;
}

HBPair isHeightBalanced(Node *root)
{
    HBPair x;
    if (root == NULL)
    {
        x.balance = true;
        x.height = 0;
        return x;
    }
    HBPair l = isHeightBalanced(root->left);
    HBPair r = isHeightBalanced(root->right);

    if (l.balance == true and r.balance == true and abs(l.height - r.height) <= 1)
    {
        x.balance = true;
    }
    else
    {
        x.balance = false;
    }

    x.height = max(l.height, r.height) + 1;
    return x;
}
Node *builtHBT(int *arr, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    Node *tt = new Node(arr[mid]);
    tt->left = builtHBT(arr, 0, mid - 1);
    tt->right = builtHBT(arr, mid + 1, e);
    return tt;
}

Node *createTreeFromTrav(int *in, int *pre, int s, int e)
{
    static int i = 0;
    // base
    if (s > e)
    {
        return NULL;
    }

    // rec case

    Node *root = new Node(pre[i]);
    int index = -1;
    for (int j = s; s <= e; j++)
    {
        if (in[j] == pre[i])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTrav(in, pre, s, index - 1);
    root->right = createTreeFromTrav(in, pre, index - 1, e);
    return root;
}
void printRightView(Node *root, bool left, bool right)
{
    bool l, r = false;
    if (root == NULL)
    {
        return;
    }
    if (root->right)
    {
        r = true;
    }
    if (root->left)
    {
        l = true;
    }
    // if (right and)
    // {
    //     cout << root->data << "\n";
    // }

    printRightView(root->right, l, r);

    printRightView(root->left, l, r);
}
void printRightView2(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        // get number of nodes for each level
        int n = q.size();

        // traverse all the nodes of the current level
        while (n > 1)
        {
            q.pop();

            // print the last node of each level
            if (n == 0)
            {
                cout << x->data << " ";
            }
            // if left child is not null push it into the
            // queue
            if (x->left)
                q.push(x->left);
            // if right child is not null push it into the
            // queue
            if (x->right)
                q.push(x->right);
        }
    }
}

int main()
{
    // int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    // int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    // int n = sizeof(in) / sizeof(in[0]);

    // Node *root = createTreeFromTrav(in, pre, 0, n - 1);
    Node *root = builtTree();
    printRightView(root);

    return 0;
}