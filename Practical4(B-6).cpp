/*Beginning with an empty binary search tree, Construct binary search tree by inserting the values in
the order given. After constructing a binary tree - i. Insert new node, ii. Find number of nodes in longest
path from root, iii. Minimum data value found in the tree, iv. Change a tree so that the roles of the left
and right pointers are swapped at every node, v. Search a value.*/

#include <iostream>
using namespace std;

// Node structure for BST
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

// ===================== BINARY SEARCH TREE CLASS =====================
class Tree {
private:
    Node* root;

    // Recursive function to insert a new node in BST
    Node* insertNode(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }
        if (value < root->data) {
            root->left = insertNode(root->left, value);
        } else {
            root->right = insertNode(root->right, value);
        }
        return root;
    }

    // Recursive function to find height (longest path)
    int findLongestPath(Node* root) {
        if (root == nullptr) return 0;
        int leftPath = findLongestPath(root->left);
        int rightPath = findLongestPath(root->right);
        return max(leftPath, rightPath) + 1;
    }

    // Function to find minimum value in BST
    int findMinimumValue(Node* root) {
        if (root == nullptr) return -1;
        while (root->left != nullptr) {
            root = root->left;
        }
        return root->data;
    }

    // Function to swap left & right pointers at each node (mirror tree)
    Node* swapPointers(Node* root) {
        if (root == nullptr) return nullptr;
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        swapPointers(root->left);
        swapPointers(root->right);
        return root;
    }

    // Recursive search
    bool searchValue(Node* root, int value) {
        if (root == nullptr) return false;
        if (root->data == value) return true;
        if (value < root->data) return searchValue(root->left, value);
        return searchValue(root->right, value);
    }

    // Print BST sideways
    void printTree(Node* root, int indent = 0) {
        if (root == nullptr) return;
        printTree(root->right, indent + 4); // Print right subtree first
        for (int i = 0; i < indent; i++) cout << " ";
        cout << root->data << endl;
        printTree(root->left, indent + 4); // Print left subtree
    }

public:
    // Constructor
    Tree() {
        root = nullptr;
    }

    // Wrapper functions (call private versions)
    void insertNode(int value) {
        root = insertNode(root, value);
        cout << "Node inserted successfully." << endl;
    }

    void findLongestPath() {
        int longestPath = findLongestPath(root);
        cout << "Number of nodes in the longest path from root: " << longestPath << endl;
    }

    void findMinimumValue() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }
        int minVal = findMinimumValue(root);
        cout << "Minimum value in the tree: " << minVal << endl;
    }

    void swapPointers() {
        root = swapPointers(root);
        cout << "Left and right pointers swapped at every node (mirror tree)." << endl;
    }

    void searchValue(int value) {
        if (searchValue(root, value))
            cout << "Value " << value << " found in the tree." << endl;
        else
            cout << "Value " << value << " not found in the tree." << endl;
    }

    void printTree() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }
        cout << "Binary Tree (sideways):\n";
        printTree(root);
    }

    bool isEmpty() {
        return root == nullptr;
    }
};

// ===================== MAIN FUNCTION =====================
int main() {
    Tree binaryTree;
    int choice;

    cout << "\n! ! ! ! ! PRACTICAL :- 03 (B-06) - BINARY SEARCH TREE ! ! ! ! !\n";

    while (true) {
        cout << "\n------------------------------------------------------\n";
        cout << "Menu for Binary Search Tree Operations:\n";
        cout << "1. Insert Node\n";
        cout << "2. Find Number of Nodes in Longest Path from Root\n";
        cout << "3. Find Minimum Data Value\n";
        cout << "4. Swap Left and Right Pointers (Mirror Tree)\n";
        cout << "5. Search a Value\n";
        cout << "6. Print Tree\n";
        cout << "7. Exit\n";
        cout << "------------------------------------------------------\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter the value to insert: ";
            cin >> value;
            binaryTree.insertNode(value);
            break;
        }
        case 2:
            binaryTree.findLongestPath();
            break;
        case 3:
            binaryTree.findMinimumValue();
            break;
        case 4:
            binaryTree.swapPointers();
            break;
        case 5: {
            int value;
            cout << "Enter the value to search: ";
            cin >> value;
            binaryTree.searchValue(value);
            break;
        }
        case 6:
            binaryTree.printTree();
            break;
        case 7:
            cout << "\n- - - TERMINATED SUCCESSFULLY - - -\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
