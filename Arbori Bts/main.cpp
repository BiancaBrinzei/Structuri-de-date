#include <iostream>

using namespace std;


// Binary Search Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Search Tree class
class BST {
private:
    Node* root;

    Node* insertNode(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertNode(root->left, value);
        } else if (value > root->data) {
            root->right = insertNode(root->right, value);
        }

        return root;
    }

    Node* searchNode(Node* root, int value) {
        if (root == nullptr || root->data == value) {
            return root;
        }

        if (value < root->data) {
            return searchNode(root->left, value);
        }

        return searchNode(root->right, value);
    }

    void inOrderTraversal(Node* root) {
        if (root != nullptr) {
            inOrderTraversal(root->left);
            std::cout << root->data << " ";
            inOrderTraversal(root->right);
        }
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    bool search(int value) {
        Node* result = searchNode(root, value);
        return (result != nullptr);
    }

    void inOrder() {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    bst.inOrder();  // Output: 20 30 40 50 60 70 80

    std::cout << "Search 40: " << (bst.search(40) ? "Found" : "Not found") << std::endl;  // Output: Found
    std::cout << "Search 90: " << (bst.search(90) ? "Found" : "Not found") << std::endl;  // Output: Not found

    return 0;
}
