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
    int height_tree(Node *root) {
        if(root == nullptr || (root->nLeft == nullptr && root->nRight==nullptr)) return 0;
        else{
            int h_left = height_tree(root->nLeft);
            int h_right = height_tree(root->nRight);
            return 1 + max(h_left, h_right);
        }
    }
    int leaf_nums(Node *root) {
        if(root == nullptr) return 0;
        if(root->nLeft == nullptr && root->nRight == nullptr) {
            return 1;
        }
        return leaf_nums(root->nLeft) + leaf_nums(root->nRight);
    }
    int node_depth(Node *root, int data) {
        Node *p = searchNode(root, data);
        if(p == nullptr) return -1;
        int depth = 0;
        while(p->fatherNode != nullptr){
            depth++;
            p = p->fatherNode;
        }
        return depth;
    }
    int count_node(Node *root) {
        if(root == nullptr) return 0;
        else {
            int sum = count_node(root->nLeft) + count_node(root->nRight);
            if(root->nLeft == nullptr && root->nRight == nullptr) {
                if(root->fatherNode->nLeft != nullptr && root->fatherNode->nLeft->getData() == root->getData()) {
                    root->fatherNode->nLeft = nullptr;
                }
                else if(root->fatherNode->nRight != nullptr && root->fatherNode->nRight->getData() == root->getData()) {
                    root->fatherNode->nRight = nullptr;
                }
                root->fatherNode = nullptr;
                delete root;
                return 1 + sum;
            }
        }
    }
    int findMaxNode(Node *root) {
        if(root == nullptr) return -1;
        int maxx = root->getData();
        int a = findMaxNode(root->nLeft);
        int b = findMaxNode(root->nRight);
        a = max(a, maxx);
        b = max(b, maxx);
        return max(a, b);
    }
    bool isBST(Node *root, int limit_left, int limit_right) {
        if(root == nullptr) return true;
        if(root->getData() <= limit_left || root->getData() >= limit_right) {
            return false;
        }
        return isBST(root->nLeft, limit_left, root->getData())
            && isBST(root->nRight, root->getData(), limit_right);
    }
    bool isMHT(Node *root) {
        if(root == nullptr) return true;
        int a = findMaxNode(root);
        if(a == root->getData()) return true;
        else return false;
        return isMHT(root->nLeft) && isMHT(root->nRight);
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


    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)                      (done)
    int remove(int data) {
        Node* p = searchNode(this->root, data);
        if(p == nullptr) {
            return 0;
        }
        else {
            return count_node(p);
        }
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

    // Hàm kiểm tra cây tìm kiếm nhị phân                               (done)
    bool isBinarySearchTree() {
        return isBST(root, INT_MIN, INT_MAX);
    }

    // Hàm kiểm tra cây max-heap                                        (done)
    bool isMaxHeapTree() {
        isMHT(this->root);
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

    // Hàm trả về độ sâu của một Node                                   (done)
    int depth(int data){
        return node_depth(this->root, data);
    }

    // Hàm đếm số lượng lá                                              (done)
    int numOfLeaves() {
        leaf_nums(this->root);
    }

    // Hàm trả về Node có giá trị lớn nhất                              (done)
    int findMax() {
        return findMaxNode(this->root);
    }

    // Hàm trả về Node có nhiều con nhất                                (idunu)
    int findMaxChild();
};

int main(int argc, char const *argv[]) {
    Node* root = new Node(50);             //100
    Tree treeTest(root);
//binary search tree

    if(!treeTest.insertNode(50, 25)) cout << "error\n";
    if(!treeTest.insertNode(50, 75)) cout << "error\n";
    if(!treeTest.insertNode(25, 13)) cout << "error\n";
    if(!treeTest.insertNode(25, 37)) cout << "error\n";
    if(!treeTest.insertNode(75, 63)) cout << "error\n";
    if(!treeTest.insertNode(75, 87)) cout << "error\n";
    if(!treeTest.insertNode(13, 7)) cout << "error\n";
    if(!treeTest.insertNode(13, 19)) cout << "error\n";
    if(!treeTest.insertNode(37, 31)) cout << "error\n";
    if(!treeTest.insertNode(37, 43)) cout << "error\n";
    if(!treeTest.insertNode(63, 57)) cout << "error\n";
    if(!treeTest.insertNode(63, 69)) cout << "error\n";
    if(!treeTest.insertNode(87, 81)) cout << "error\n";
    if(!treeTest.insertNode(87, 93)) cout << "error\n";
    if(!treeTest.insertNode(7, 4)) cout << "error\n";
    if(!treeTest.insertNode(7, 10)) cout << "error\n";
    if(!treeTest.insertNode(19, 16)) cout << "error\n";
    if(!treeTest.insertNode(19, 22)) cout << "error\n";
    if(!treeTest.insertNode(31, 29)) cout << "error\n";
    if(!treeTest.insertNode(31, 34)) cout << "error\n";
    if(!treeTest.insertNode(43, 40)) cout << "error\n";
    if(!treeTest.insertNode(43, 46)) cout << "error\n";
    if(!treeTest.insertNode(57, 54)) cout << "error\n";
    if(!treeTest.insertNode(57, 60)) cout << "error\n";
    if(!treeTest.insertNode(69, 66)) cout << "error\n";
    if(!treeTest.insertNode(69, 72)) cout << "error\n";
    if(!treeTest.insertNode(81, 78)) cout << "error\n";
    if(!treeTest.insertNode(81, 84)) cout << "error\n";
    if(!treeTest.insertNode(93, 90)) cout << "error\n";
    if(!treeTest.insertNode(93, 96)) cout << "error\n";

//max heap tree
/*
    if(!treeTest.insertNode(100, 99)) cout << "error\n";
    if(!treeTest.insertNode(100, 98)) cout << "error\n";
    if(!treeTest.insertNode(99, 97)) cout << "error\n";
    if(!treeTest.insertNode(99, 96)) cout << "error\n";
    if(!treeTest.insertNode(98, 95)) cout << "error\n";
    if(!treeTest.insertNode(98, 94)) cout << "error\n";
    if(!treeTest.insertNode(97, 93)) cout << "error\n";
    if(!treeTest.insertNode(97, 92)) cout << "error\n";
    if(!treeTest.insertNode(96, 91)) cout << "error\n";
    if(!treeTest.insertNode(96, 90)) cout << "error\n";
    if(!treeTest.insertNode(95, 89)) cout << "error\n";
    if(!treeTest.insertNode(95, 88)) cout << "error\n";
    if(!treeTest.insertNode(94, 87)) cout << "error\n";
    if(!treeTest.insertNode(94, 86)) cout << "error\n";
    if(!treeTest.insertNode(93, 85)) cout << "error\n";
    if(!treeTest.insertNode(93, 84)) cout << "error\n";
    if(!treeTest.insertNode(92, 83)) cout << "error\n";
    if(!treeTest.insertNode(92, 82)) cout << "error\n";
    if(!treeTest.insertNode(91, 81)) cout << "error\n";
    if(!treeTest.insertNode(91, 80)) cout << "error\n";
    if(!treeTest.insertNode(90, 79)) cout << "error\n";
    if(!treeTest.insertNode(90, 78)) cout << "error\n";
    if(!treeTest.insertNode(89, 77)) cout << "error\n";
    if(!treeTest.insertNode(89, 76)) cout << "error\n";
    if(!treeTest.insertNode(88, 75)) cout << "error\n";
    if(!treeTest.insertNode(88, 74)) cout << "error\n";
    if(!treeTest.insertNode(87, 73)) cout << "error\n";
    if(!treeTest.insertNode(87, 72)) cout << "error\n";
    if(!treeTest.insertNode(86, 71)) cout << "error\n";
    if(!treeTest.insertNode(71, 70)) cout << "error\n";
*/

    treeTest.preorder();

    treeTest.inorder();

    treeTest.postorder();

    cout << "This is ";
    if(!treeTest.isBinarySearchTree()) cout << "not ";
    cout << "a binary search tree!\n";

    cout << "This is ";
    if(!treeTest.isMaxHeapTree()) cout << "not ";
    cout << "a max heap tree!\n";

    int h_tree = treeTest.height();
    cout << "height: " << h_tree << endl;

    int h_leaves = treeTest.numOfLeaves();
    cout << "leaves: " << h_leaves << endl;

    cout << "Max Node data: " << treeTest.findMax() << endl;

    cout << "Node that you wanna find depth: " << endl;
    int dataa;
    cin >> dataa;
    int depth = treeTest.depth(dataa);
    cout << "Depth: " << depth << endl;

    int removed_node = treeTest.remove(dataa);
    cout << "Removed node: " << removed_node << endl;

    treeTest.preorder();


    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    // Test thử các hàm của lớp cây

    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại

    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    return 0;
}
