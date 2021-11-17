#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <QCoreApplication>
#include <iostream>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class BinaryTree {
  private:
    struct Node {
    string sData; // represents name
    int iData;    // represents place on top ten list
    Node *left;    // left child (left subtree)
    Node *right;   // right child (right subtree)
    };

    Node *root;
    queue<string> treeQueue;
    stack<string> treeStack;
    void insert(Node *&, Node *&);
    bool compareTo(Node *&, string);
    string display(Node *) const;
    Node* newNode(int data);
public:
    BinaryTree() {
        root = nullptr;
    }
    void insertNode(string, int);
    string searchNode(string);
    void removeMin();
    bool isEmpty();
    string display() { return display(root); }
    void remove(string);
    void deleteNode(string, Node *&);
    void makeDeletion(Node *&);
    int height(Node* node);
    int callHeight() { return height(root); }
    void createSideTree();
    void createDrinkTree();
    void getUserDecisions(Node* node);
    void callGetUserDecisions() { getUserDecisions(root); }
};
int BinaryTree::height(Node* node)
{
    if (node == NULL)
        return 0;
    else {
        int leftHeight = height(node->left); //These will branch left and right and keep branching to cover the whole tree
        int rightHeight = height(node->right);
        if (leftHeight > rightHeight) {      //Uses Largest
            return (leftHeight + 1);         //returns height of left subarray if larger
        }
        else {
            return (rightHeight + 1);//returns height of right subarray if larger
        }
    }
}

string BinaryTree::display(Node *nodePtr) const {
    string data;
   if (nodePtr) {
       data += display(nodePtr->left);
       data = data + nodePtr->sData + "\n";
       data += display(nodePtr->right);
   }
   return data;
}

bool BinaryTree::isEmpty() {
   Node *nodePtr = root;
   return (nodePtr == NULL); //If empty root should be null
}

void BinaryTree::removeMin() {
    Node *nodePtr = root;
    while(nodePtr->left != NULL) //Follows left until it hits null
        nodePtr = nodePtr->left;
    remove(nodePtr->sData); //Removes min
}

void BinaryTree::insertNode(string name, int key) {
    Node *newNode = nullptr;

    //Creating new node and storing values
    newNode = new Node;
    newNode->sData = name; //Name value
    newNode->iData = key; //Position on List
    newNode->left = newNode->right = nullptr;

    //insert node
    insert(root, newNode);
}

void BinaryTree::insert(Node *&nodePtr, Node *&newNode) {
    if (nodePtr == nullptr) //if statements place them in tree by first character then second etc.
        nodePtr = newNode;
    else if (newNode->iData < nodePtr->iData)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

bool BinaryTree::compareTo(Node *&nodePtr, string input) {
    return (nodePtr->sData == input); //Sees if strings equal, returns bool
}


string BinaryTree::searchNode(string search) {
    Node *nodePtr = root;

    while (nodePtr) {
        if (compareTo(nodePtr, search)) //If match
            return to_string(nodePtr->iData) + ": " + nodePtr->sData;
        else if (search < nodePtr->sData) //If search less than then its in left tree
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right; //Else right tree
    }
    return "Can not find: " + search;
}

void BinaryTree::remove(string search) {
    deleteNode(search, root);
}
void BinaryTree::deleteNode(string search, Node *&nodePtr) {
    if (search < nodePtr->sData)
        deleteNode(search, nodePtr->left); //Searching left part of tree for value
    else if (search > nodePtr->sData)
        deleteNode(search, nodePtr->right); //Searching right part of tree for value
    else
        makeDeletion(nodePtr); //When found it calls makeDeletion and passes NodePtr
}
void BinaryTree::makeDeletion(Node *&nodePtr) {
    Node *tempNodePtr = nullptr; //Temp ptr

    if (nodePtr == nullptr)
        cout << "Node is empty" << endl;
    else if (nodePtr->right == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left; //Reattach left child node
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right; //Reattach right child node
        delete tempNodePtr;
    }
    else { //If node has two children
        tempNodePtr = nodePtr->right;
        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left; //Shifts Nodes and Reattaches child nodes
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr; //deletes temp ptr
    }
}
void BinaryTree::createDrinkTree() {
    insertNode("Do you want milk?", 7);
    insertNode("Do you want White Milk?", 2);
    insertNode("\nHave White Milk", 1);
    insertNode("Do you want Chocolate Milk", 5);
    insertNode("\nHave Chocolate Milk", 3);
    insertNode("\nHave Strawberry Milk", 6);
    insertNode("Do you want Juice?", 14);
    insertNode("Do you want Apple Juice?", 9);
    insertNode("\nHave Apple Juice", 8);
    insertNode("Do you want Grape Juice?", 12);
    insertNode("\nHave Grape Juice", 11);
    insertNode("\nHave Orange Juice", 13);
    insertNode("\nHave Water", 15);
}

void BinaryTree::createSideTree() {
    insertNode("Do you want fruit?", 7);
    insertNode("Do you want something sweet?", 2);
    insertNode("\nHave Pineapple", 1);
    insertNode("Do you want an apple", 5);
    insertNode("\nHave an Apple", 3);
    insertNode("\nHave an Orange", 6);
    insertNode("Do you want something green?", 14);
    insertNode("Do you want Lettuce?", 9);
    insertNode("\nHave Lettuce", 8);
    insertNode("Do you want Brocolli?", 12);
    insertNode("\nHave Brocolli", 11);
    insertNode("\nHave Peas", 13);
    insertNode("Do you want Carrots", 16);
    insertNode("\nHave Carrots", 15);
    insertNode("\nHave Cauliflower", 17);
}

void BinaryTree::getUserDecisions(Node *nodePtr) {
    string userInput = "";
    if (nodePtr->left != NULL) {
        cout << nodePtr->sData << endl;
        cin >> userInput;
        while(userInput != "y" && userInput != "n") {
            cout << "user input should be 'y' or 'n'" << endl;
            cin >> userInput;
        }
        if(userInput == "y") {
            getUserDecisions(nodePtr->left);
        }
        else {
            getUserDecisions(nodePtr->right);
        }
    }
    if (nodePtr->left == nullptr) {
        cout << nodePtr->sData << endl;
    }
}
#endif // BINARYTREE_H
