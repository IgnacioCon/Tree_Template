#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>


using namespace std;


class Node
{
private:
    int data;
    Node *parent;
    vector<Node *> childs;

public:

    Node(int data);
    Node(int data, Node *parent);

    Node *getParent() const;
    void setParent(Node *value);
    int getData();
    void setData(int value);
    vector<Node *> *getChilds();
    Node *getChildByPos(int pos);
    void setChilds(int pos, Node *newNode);
    void setChildSize(int size);
    int getChildSize();

};

Node::Node(int data)
{
    this->data =data;
    this->parent =NULL;
    childs.clear();
}

Node::Node(int data, Node *parent)
{
    this->data = data;
    this->parent = parent;
    childs.clear();
}


Node *Node::getParent() const
{
    return parent;
}

void Node::setParent(Node *value)
{
    parent = value;
}

int Node::getData()
{
    return this->data;
}

void Node::setData(int value)
{
    data = value;
}

vector<Node *> *Node::getChilds()
{
    return &childs;
}

Node *Node::getChildByPos(int pos)
{
    return childs[pos];
}


void Node::setChilds(int pos, Node *newNode)
{
    childs[pos] = newNode;
}

void Node::setChildSize(int size)
{
    childs.resize(size);
}

int Node::getChildSize()
{
    return childs.size();
}

//---------------------------------TREE---------------------------------------------------//

class Tree
{
private:
    Node *root;
    Node *current;

public:
    Tree();
    Node *init(int data);
    vector<Node *> *insert(Node *ref, vector<int> data);
    void preorder(Node *n);
    void posOrder(Node *n);

    Node *getRoot() const;
    void setRoot(Node *value);
    Node *getCurrent() const;
    void setCurrent(Node *value);
};



Tree::Tree():root(NULL),current(NULL)
{

}


Node *Tree::getRoot() const
{
    return root;
}

void Tree::setRoot(Node *value)
{
    root = value;
}

Node *Tree::getCurrent() const
{
    return current;
}

void Tree::setCurrent(Node *value)
{
    current = value;
}



Node *Tree::init(int data)
{
    if(root == NULL)
    {
        root = new Node(data);
        current = root;

    }

    return root;
}

vector<Node *> *Tree::insert(Node *ref, vector<int> data)
{
    current = ref;
    current->setChildSize(data.size());

    for(unsigned int i=0; i<data.size(); i++)
    {
        Node *newNode = new Node(data.at(i));
        newNode->setParent(current);
        current->setChilds(i,newNode);
    }

    //vector<Node *> tempchilds = current->getChilds();

    return current->getChilds();

}

void Tree::preorder(Node *n)
{
    if(n==NULL) return;

    cout<< n->getData()<<endl;

    for(int i=0; i<n->getChildSize();i++)
    {
        preorder(n->getChildByPos(i));
    }
}

void Tree::posOrder(Node *n)
{
    if(n==NULL) return;


    for( int i=0; i<n->getChildSize();i++)
    {
        posOrder(n->getChildByPos(i));
    }

    cout<<n->getData()<<endl;
}





#endif // TREE_H
