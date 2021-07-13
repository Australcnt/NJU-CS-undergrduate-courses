#include <iostream>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    Node() { left = NULL; right = NULL; }
};

int z_max = 0;

/*left: direction = 0, right: direction = 1*/
void DFS(Node* p, bool direction, int z_length) {
    if (z_length > z_max)
        z_max = z_length;
    if (direction == 0) {
        if (p->left)
            DFS(p->left, 1, z_length + 1);
        if (p->right)
            DFS(p->right, 0, 1);
    }
    else {
        if (p->right)
            DFS(p->right, 0, z_length + 1);
        if (p->left)
            DFS(p->left, 1, 1);
    }
}

int main()
{
    Node* root;
    /*Create a 2-Tree with the root named "root"*/
    DFS(root, 0, 0);
    DFS(root, 1, 0);
    cout << z_max << endl;
	return 0;
}