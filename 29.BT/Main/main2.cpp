#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

Node *BulitBT()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }

    Node *root = new Node(d);
    root->left = BulitBT();
    root->right = BulitBT();
    return root;
}
// print

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

// Height

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    return 1 + max(left, right);
}

// count

int count(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

// sum of all nodes

int sumOfAll(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->data + sumOfAll(root->left) + sumOfAll(root->right);
}

// diameter of the binary tree
// O n^2
int dia(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int fromRoot = height(root->left) + height(root->right);
    int fromLeft = dia(root->left);
    int fromRight = dia(root->right);

    return max(fromLeft, max(fromRight, fromRoot));
}

// optimized
class HDPair
{
public:
    int height;
    int diameter;
};

HDPair diaOptimized(Node *root)
{
    HDPair p;
    if (root == NULL)
    {
        p.height = 0;
        p.diameter = 0;
        return p;
    }

    HDPair left = diaOptimized(root->left);
    HDPair right = diaOptimized(root->right);
    p.diameter = max((left.height + right.height), max(left.diameter, right.diameter));
    p.height = max(left.height, right.height) + 1;
    return p;
}
// sum replacement
int sumRep(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL and root->right == NULL)
    {
        return root->data;
    }
    int temp = root->data;
    root->data = sumRep(root->left) + sumRep(root->right);

    return root->data + temp;
}
// BFS

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

void LevelOrderOptimized(Node *root)
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
            continue;
        }

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
// is tree is balance
class HBPair
{
public:
    int height;
    bool balance;
};

HBPair isHB(Node *root)
{
    HBPair p;

    if (root == NULL)
    {
        p.balance = 1;
        p.height = 0;
        return p;
    }
    HBPair left = isHB(root->left);
    HBPair right = isHB(root->right);
    if (left.balance and right.balance and abs(left.height - right.height) <= 1)
    {
        p.balance = 1;
    }
    else
    {
        p.balance = 0;
    }
    p.height = 1 + max(left.height, right.height);
    return p;
}

// make Balanced BT from array
Node *BTFromArray(int A[], int l, int h)
{
    int mid = (l + h) / 2;
    if (l > h)
    {
        return NULL;
    }
    Node *t = new Node(A[mid]);
    t->left = BTFromArray(A, l, mid - 1);
    t->right = BTFromArray(A, mid + 1, h);
    return t;
}

// built BT from Preorder and InOrder

// Node *BuiltBTT(vector<int> inorder, vector<int> preorder, int s, int e)
// {
//     static int idx = 0;
//     if (s > e)
//     {
//         return NULL;
//     }
//     int i = find(inorder.begin(), inorder.end(), preorder[idx]) - inorder.begin();
//     Node *root = new Node(inorder[i]);
//     root->left = BuiltBTT(inorder, preorder, s, i - 1);
//     idx++;
//     root->right = BuiltBTT(inorder, preorder, i + 1, e);
//     idx++;
//     return root;
// }

Node *BuiltBTTT(int pre[], int in[], int s, int e)
{
    static int i = 0;
    if (s > e)
    {
        return NULL;
    }

    Node *root = new Node(pre[i]);
    int index = -1;
    for (int j = s; j <= e; j++)
    {
        if (in[j] == pre[i])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left = BuiltBTTT(pre, in, s, index - 1);
    root->right = BuiltBTTT(pre, in, index + 1, e);
    return root;
}

// Right View

// void RightView(Node *root, int level, int &maxLevel)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     if (level > maxLevel)
//     {
//         cout << root->data << "\n";
//         maxLevel = level;
//     }
//     RightView(root->right, ++level, maxLevel);
//     RightView(root->left, level, maxLevel);
// }

void RightView(Node *root, int level)
{
    static int maxlevel = -1;
    if (root == NULL)
    {
        return;
    }
    if (level > maxlevel)
    {
        cout << root->data << "\n";
        maxlevel = level;
    }
    RightView(root->right, level + 1);
    RightView(root->left, level + 1);
}

// left view
void LeftView(Node *root, int level)
{
    static int maxlevel = -1;
    if (root == NULL)
    {
        return;
    }
    if (level > maxlevel)
    {
        cout << root->data << "\n";
        maxlevel = level;
    }
    LeftView(root->left, level + 1);
    LeftView(root->right, level + 1);
}

int main()
{
    // int inorder[] = {1, 2, 3, 4, 8, 5, 6, 7};
    // int preorder[] = {3, 2, 8, 4, 1, 6, 7, 5};
    // Node *root = BuiltBTTT(inorder, preorder, 0, 7);
    // LevelOrderOptimized(root);

    // int A[] = {1, 2, 3, 4, 5, 6, 7};
    // Node *root = BTFromArray(A, 0, 6);
    // LevelOrderOptimized(root);
    // cout << "\n";

    Node *root = BulitBT();
    int maxLevel = -1;
    LeftView(root, 0);

    // cout << dia(root) << "\n";
    // HDPair p;
    // p = diaOptimized(root);
    // cout << p.diameter << "\n";
    // cout << p.height << "\n";
    // LevelOrderOptimized(root);

    // LevelOrderOptimized(root);
    // cout << "\n";
    // cout << sumRep(root);
    // cout << "\n";
    // LevelOrderOptimized(root);

    // HBPair p;
    // p = isHB(root);
    // cout << p.balance << "\n";
}