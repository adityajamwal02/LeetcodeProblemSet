/// Interval Trees

#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int low, high;
};

struct Node {
    Interval interval;
    int max;
    Node* left;
    Node* right;
};

Node* newNode(Interval i) {
    Node* node = new Node;
    node->interval = i;
    node->max = i.high;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, Interval i) {
    if (root == NULL)
        return newNode(i);

    int l = root->interval.low;
    if (i.low < l)
        root->left = insert(root->left, i);
    else
        root->right = insert(root->right, i);

    if (root->max < i.high)
        root->max = i.high;

    return root;
}

bool doOverlap(Interval i1, Interval i2) {
    if (i1.low <= i2.high && i2.low <= i1.high)
        return true;
    return false;
}

Interval* search(Node* root, Interval i) {
    if (root == NULL)
        return NULL;

    if (doOverlap(root->interval, i))
        return &(root->interval);

    if (root->left != NULL && root->left->max >= i.low)
        return search(root->left, i);

    return search(root->right, i);
}

int main() {
    Node* root = NULL;
    root = insert(root, {15, 20});
    root = insert(root, {10, 30});
    root = insert(root, {17, 19});
    root = insert(root, {5, 20});
    root = insert(root, {12, 15});
    root = insert(root, {30, 40});

    cout << "Interval tree created!" << endl;

    Interval i = {14, 16};
    Interval* res = search(root, i);
    if (res == NULL)
        cout << "No overlap found" << endl;
    else
        cout << "Overlaps with [" << res->low << ", " << res->high << "]" << endl;

    return 0;
}
