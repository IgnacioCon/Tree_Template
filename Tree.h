#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

template<class T>
class Node
{
private:
    T data;
    Node *parent;
    vector<Node *> childs;

public:

    Node(T data);
    Node(T data, Node *parent);

    Node<T> *getParent() const;
    void setParent(Node *value);
    T getData();
    void setData(T value);
    vector<Node<T> *> *getChilds();
    Node<T> *getChildByPos(int pos);
    void setChilds(int pos, Node *newNode);
    void setChildSize(int size);
    int getChildSize();

};

template<class T>
Node<T>::Node(T data)
{
    this->data =data;
    this->parent =NULL;
    childs.clear();
}

template<class T>
Node<T>::Node(T data, Node *parent)
{
    this->data = data;
    this->parent = parent;
    childs.clear();
}

template<class T>
Node<T> *Node<T>::getParent() const
{
    return parent;
}

template<class T>
void Node<T>::setParent(Node *value)
{
    parent = value;
}

template<class T>
T Node<T>::getData()
{
    return this->data;
}

template<class T>
void Node<T>::setData(T value)
{
    data = value;
}

template<class T>
vector<Node<T> *> *Node<T>::getChilds()
{
    return &childs;
}

template<class T>
Node<T> *Node<T>::getChildByPos(int pos)
{
    return childs[pos];
}

template<class T>
void Node<T>::setChilds(int pos, Node *newNode)
{
    childs[pos] = newNode;
}

template<class T>
void Node<T>::setChildSize(int size)
{
    childs.resize(size);
}

template<class T>
int Node<T>::getChildSize()
{
    return childs.size();
}

//---------------------------------TREE---------------------------------------------------//

template<class U>
class Tree
{
private:
    Node<U> *root;
    Node<U> *current;
    string filename;

public:
    Tree();
    Node<U> *init(U data);
    vector<Node<U> *> *insert(Node<U> *ref, vector<U> data);
    void preorder(Node<U> *n);
    void posOrder(Node<U> *n);
//    void inOrder(Node<U> *n);

    Node<U> *getRoot() const;
    void setRoot(Node<U> *value);
    Node<U> *getCurrent() const;
    void setCurrent(Node<U> *value);
    void createGraph(Node<U> *n);
    void preOrder(Node<U> *n);
    string getFilename() const;
    void setFilename(const string &value);
};


template<class U>
string Tree<U>::getFilename() const
{
    return filename;
}

template<class U>
void Tree<U>::setFilename(const string &value)
{
    filename = value;
}

template<class U>
Tree<U>::Tree():root(NULL),current(NULL)
{

}

template<class U>
Node<U> *Tree<U>::getRoot() const
{
    return root;
}

template<class U>
void Tree<U>::setRoot(Node<U> *value)
{
    root = value;
}

template<class U>
Node<U> *Tree<U>::getCurrent() const
{
    return current;
}

template<class U>
void Tree<U>::setCurrent(Node<U> *value)
{
    current = value;
}



template<class U>
Node<U> *Tree<U>::init(U data)
{
    if(root == NULL)
    {
        root = new Node<U>(data);
        current = root;

    }

    return root;
}

template<class U>
vector<Node<U> *> *Tree<U>::insert(Node<U> *ref, vector<U> data)
{
    current = ref;
    current->setChildSize(data.size());

    for(unsigned int i=0; i<data.size(); i++)
    {
        Node<U> *newNode = new Node<U>(data.at(i));
        newNode->setParent(current);
        current->setChilds(i,newNode);
    }


    return current->getChilds();

}

template<class U>
void Tree<U>::preorder(Node<U> *n)
{
    if(n==NULL) return;

    cout<< n->getData()<<endl;

    for(int i=0; i<n->getChildSize();i++)
    {
        preorder(n->getChildByPos(i));
    }
}

template<class U>
void Tree<U>::posOrder(Node<U> *n)
{
    if(n==NULL) return;


    for( int i=0; i<n->getChildSize();i++)
    {
        posOrder(n->getChildByPos(i));
    }

    cout<<n->getData()<<endl;
}

/*
template<class U>
void Tree<U>::inOrder(Node<U> *n)
{
    if(n=NULL) return;

    for(int i =0; i<n->getChildSize();i++)
    {
        inOrder(n->getChildByPos(i));
        cout<<n->getData()<<endl;
        inOrder(n->getChildByPos(i));
    }


}
*/

template<class U>
void Tree<U>::createGraph(Node<U> *n)
{
    ofstream file;
    file.open(this->getFilename().c_str());
    if(file.is_open())
    {
       file<<"graph{ "<<endl;

       for(int i=0; i<n->getChildSize();i++)
       {
           file<<n->getData()<<" -- ";
           preOrder(n->getChildByPos(i));

       }

//    file<<"}"<<endl;
     file.close();

    }


}
template<class U>
void Tree<U>::preOrder(Node<U> *n)
{
    ofstream file;
    file.open(this->getFilename().c_str(), ios::app);
    if(file.is_open())
    {
    if(n==NULL){ file<<"\n"; return;}

      file<<n->getData()<<endl;
    for(int i=0; i<n->getChildSize();i++)
    {
        file<<n->getData()<<" -- ";
        preOrder(n->getChildByPos(i));

    }

     file.close();
    }



}


#endif // TREE_H
