//Nikole Florence
//COSC-350
#include <iostream>
using namespace std;

//Node class that was given as well as a constructor
class Node
{
    public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

//Binary Tree class
class MyTree
{
    private:
    Node* root;

//First function to add values to the tree
    Node* AddValueToTree(Node* n, int value)
    {
        if(n == nullptr){
            return new Node(value);
        }
        if(value < n->value){
            n->left = AddValueToTree(n->left, value);
        } else {
            n->right = AddValueToTree(n->right, value);
        }
        return n;
    }

//Second function to print the tree in-order
    void DisplayTree_LNR(Node *n)
    {
        if(n->left != nullptr)
        DisplayTree_LNR(n->left);
        cout << n->value << " ";
        if(n->right != nullptr)
        DisplayTree_LNR(n->right);
    }

//Third function to print the tree pre-order
    void DisplayTree_NLR(Node *n)
    {
        cout << n->value << " ";
        if(n->left != nullptr)
        DisplayTree_NLR(n->left);
        if(n->right != nullptr)
        DisplayTree_NLR(n->right);
    }

//Fourth function to print the tree post-order
    void DisplayTree_LRN(Node *n)
    {
        if(n->left != nullptr)
        DisplayTree_LRN(n->left);
        if(n->right != nullptr)
        DisplayTree_LRN(n->right);
        cout << n->value << " ";
    }

//public access to all functions for main function
    public:
    MyTree(): root(nullptr){}

    void AddValueToTree(int value){
        root = AddValueToTree(root, value);
    }

    void DisplayTree_LNR(){
        DisplayTree_LNR(root);
        cout << endl;
    }

    void DisplayTree_NLR(){
        DisplayTree_NLR(root);
        cout << endl;
    }

    void DisplayTree_LRN(){
        DisplayTree_LRN(root);
        cout << endl;
    }
};

//main function given that adds values and displays the trees
int main()
{
    MyTree T;
    T.AddValueToTree(100);
    T.AddValueToTree(50);
    T.AddValueToTree(150);
    T.DisplayTree_LNR(); // this should display 50 100 15
    T.DisplayTree_NLR(); // this should display 100 50 150
    T.DisplayTree_LRN(); // this should display 50 150 100
}