#include<iostream>
using namespace std;

class Node{
    public:
        int key;
        Node* parent;
        Node* left;
        Node* right;

        Node(int val){
            key = val;
            left = NULL;
            right = NULL;
            parent = NULL;
        }
        void print() {
            cout << key ;
        }
        void print_all() {
            cout << "Value: key" << parent << "(" << left << "," << right << ")" << endl;
        }
};

class Tree {
    private:
       Node *root = NULL;
       int counter{0};
    public:
       Tree(int val) {
        this->root = new Node(val);
       }
       ~Tree() {
        cout << "Destroying tree" << endl;
       }
       Node* find_right_sibling(Node* me) {
        Node* p_node = me->parent;
        cout << "Finding right sibling of " << me->key;
        counter++;
        if(p_node == NULL) return NULL;

        if(p_node->right == me) {
            p_node = find_right_sibling(p_node);
        } else {
            p_node = p_node->right;
            cout << "Found right sibling: " << p_node->key;
        }
        return p_node;
       }
       void print_time_complexity() {
        cout << "Traversals: " << counter;
       }

       Node* find_left_sibling(Node* me) {

       }
    
       int insert(int element) {
        cout << "inserting node in tree: " << element << endl;
        Node* el = new Node(element);
        Node* p_node = root;
        Node* p_first_sibling = p_node->left;
        if(p_first_sibling)
            cout << "First sibling: " << p_first_sibling->key << endl;
        while(p_node != NULL){
            if(p_node->left == NULL){
                cout << "Inserting on left: " << element << endl;
                p_node->left = el;
                el->parent = p_node;
                break;
            } else if(p_node->right == NULL){
                cout << "Inserting on right: " << element << endl;
                p_node->right = el;
                el->parent = p_node;
                break;
            } else {
                p_node = find_right_sibling(p_node);
                if(p_node == NULL) {
                    cout << "This layer of nodes is finished: " << endl << endl << endl;
                    cout << "Current_sibling: " << p_first_sibling->key << endl;
                    p_node = p_first_sibling;
                    cout << p_node->key << endl;
                    counter++;
                    p_first_sibling = p_node->left;
                }               
            }
        }


        return 0;
       }
       bool remove(int val) {
        cout << "removing node in tree: " << val << endl;
        return false;
       }
       int find(int val) {
        cout << "finding node in tree: " << val << endl;
        return 0;
       }
       void print() {
        cout << "printing only values" << endl;
       }
       void print_all() {
        cout << "printing all values and left, right pointers" << endl;
       }

};

int main(){
    Tree* tree = new Tree(1);
    for(int i=0; i < 100; i++) {
        tree->insert(i);
    }
    tree->print_time_complexity();
    delete(tree);
    return 0;
}