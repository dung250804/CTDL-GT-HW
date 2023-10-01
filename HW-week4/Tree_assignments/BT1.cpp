#include <iostream>
#include <cmath>
using namespace std;

// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    //con trái
    Node* nLeft;
    //con phải
    Node* nRight;


public:
    //constructor 1
    Node() {
        data = NULL;
        fatherNode = nullptr;
        nLeft = nullptr;
        nRight = nullptr;
    }
    //constructor 2
    Node(int data) {
        this->data = data;
        fatherNode = nullptr;
        nLeft = nullptr;
        nRight = nullptr;
    }

    int getData(){
        return this->data;
    }

    friend class Tree;
};

// Lớp Cây
class Tree {
private:
    // Chứa một Node gốc
    Node* root;

    //search
    Node* searchNode(Node *root, int key) {
        if(root == nullptr || root->data == key)
            return root;
        Node* p = searchNode(root->nLeft, key);
        if(p == nullptr)
        {
            return searchNode(root->nRight, key);
        }
    }

    void pre_order(Node *root) {
        if(root == nullptr) return;
        cout << root->data << " ";
        pre_order(root->nLeft);
        pre_order(root->nRight);
    }
    void in_order(Node *root) {
        if(root == nullptr) return;
        in_order(root->nLeft);
        cout << root->data << " ";
        in_order(root->nRight);
    }
    void post_order(Node *root) {
        if(root == nullptr) return;
        post_order(root->nLeft);
        post_order(root->nRight);
        cout << root->data << " ";
    }

    //Height
    int height_tree(Node *root) {
        if(root == nullptr || (root->nLeft == nullptr && root->nRight==nullptr)) return 0;
        else{
            int h_left = height_tree(root->nLeft);
            int h_right = height_tree(root->nRight);
            return 1 + max(h_left, h_right);
        }
    }
public:

    //constructor 1
    Tree() {
        root = nullptr;
    }
    //constructor 2
    Tree(Node* newNode) {
        this->root = newNode;
    }
    //constructor 3
    Tree(int data) {
        this->root = new Node(data);
    }

    void insertRootData(int data) {
        this->root = new Node(data);
    }

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data                               (done)
    bool insertNode(int father, int data) {
        Node* newNode = new Node(data);
        Node* p = searchNode(this->root, father);

        if (p != nullptr) {
            if((p->nLeft && p->nLeft->getData() == data) || (p->nRight && p->nRight->getData() == data)) return false;
            if (p->nLeft == nullptr) {
                p->nLeft = newNode;
                newNode->fatherNode = p;
                return true;
            } else if (p->nRight == nullptr) {
                p->nRight = newNode;
                newNode->fatherNode = p;
                return true;
            }
        }
        return false;
    }
    // Hàm in ra các Node theo thứ tự preorder                          (done)
    void preorder() {
        if(this->root != nullptr){
            cout << "Pre-Order list: ";
            pre_order(this->root);
            cout << endl;
        }
    }

    // Hàm in ra các Node theo thứ tự postorder                         (done)
    void postorder() {
        if(this->root != nullptr){
            cout << "Post-Order list: ";
            post_order(this->root);
            cout << endl;
        }
    }

    // Hàm kiểm tra cây nhị phân                                        (auto-done)
    bool isBinaryTree() {
    }

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân       (done)
    void inorder() {
        if(this->root != nullptr){
            cout << "In-Order list: ";
            in_order(this->root);
            cout << endl;
        }
    }

    // Hàm trả về độ cao của cây                                        (done)
    int height() {
        return height_tree(this->root);
    }

};

int main(int argc, char const *argv[]) {

    int N, M;
    cin >> N >> M;
    Tree treeTest;
    if(M > 0) {
        int u, v;
        cin >> u >> v;
        treeTest.insertRootData(u);
        treeTest.insertNode(u, v);
    }
    for (int i = 0; i < M-1; ++i) {
        int u, v;
        cin >> u >> v;
        treeTest.insertNode(u, v);
    }


    cout << "height: " << treeTest.height() << endl;

    treeTest.preorder();

    treeTest.postorder();

    treeTest.inorder();
}


