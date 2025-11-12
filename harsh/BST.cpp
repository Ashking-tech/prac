#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
    Node* root;

    // Helper to create new node
    Node* createNode(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    // Recursive insert
    Node* insertNode(Node* root, int val) {
        if (root == NULL)
            return createNode(val);
        if (val < root->data)
            root->left = insertNode(root->left, val);
        else if (val > root->data)
            root->right = insertNode(root->right, val);
        return root;
    }

    // Recursive inorder traversal (sorted order)
    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    // Search node recursively
    Node* searchNode(Node* root, int val) {
        if (root == NULL || root->data == val)
            return root;
        if (val < root->data)
            return searchNode(root->left, val);
        return searchNode(root->right, val);
    }

    // Find minimum value node (for deletion)
    Node* findMin(Node* root) {
        while (root->left != NULL)
            root = root->left;
        return root;
    }

    // Delete node recursively
    Node* deleteNode(Node* root, int val) {
        if (root == NULL)
            return root;

        if (val < root->data)
            root->left = deleteNode(root->left, val);
        else if (val > root->data)
            root->right = deleteNode(root->right, val);
        else {
            // Node found
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Node with 2 children
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

public:
    BST() { root = NULL; }

    void insert(int val) {
        root = insertNode(root, val);
        cout << "Inserted: " << val << endl;
    }

    void search(int val) {
        Node* res = searchNode(root, val);
        if (res)
            cout << "Node " << val << " found in BST.\n";
        else
            cout << "Node not found.\n";
    }

    void remove(int val) {
        root = deleteNode(root, val);
        cout << "Deleted (if existed): " << val << endl;
    }

    void display() {
        if (root == NULL)
            cout << "BST is empty.\n";
        else {
            cout << "Inorder Traversal (Sorted): ";
            inorder(root);
            cout << endl;
        }
    }
};

int main() {
    BST bst;
    int ch, val;

    do {
        cout << "\n===== BINARY SEARCH TREE MENU =====\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Search Node\n";
        cout << "4. Display BST (Inorder)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            bst.insert(val);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            bst.remove(val);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> val;
            bst.search(val);
            break;

        case 4:
            bst.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (ch != 5);

    return 0;
}
  