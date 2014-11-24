#include "Tree.h"

int main()
{
/*
    string filename;
    Tree<string> t1;
    Node<string> *aux;
    vector<Node<string>*> *aux2;
    vector<string> num;

    num.push_back("Fate");
    num.push_back("Destiny");
    aux = t1.init("Life");
    aux2 = t1.insert(aux,num);

    num.clear();
    num.push_back("Doom");
    num.push_back("Work");
    num.push_back("Money");
    t1.insert(aux2->at(0),num);

    num.clear();

    num.push_back("Hallelujah");
    num.push_back("Child");
    num.push_back("Konami");
    num.push_back("Contra");

    t1.insert(aux2->at(1),num);
    cout<<"Tree with Strings:"<<endl;
    cout<<"Pre-Order"<<endl;
    t1.preorder(aux);
    cout<<endl;
    cout<<"Post-Order"<<endl;
    t1.posOrder(aux);
*/
/*
    Tree<double> t1;
    Node<double> *aux;
    vector<Node<double>*> *aux2;
    vector<double> num;

    num.push_back(15.5);
    num.push_back(42.42);
    aux = t1.init(3.1456);
    aux2 = t1.insert(aux,num);

    num.clear();
    num.push_back(3.2);
    num.push_back(5.3);
    num.push_back(10.01);
    t1.insert(aux2->at(0),num);

    num.clear();

    num.push_back(68.36);
    num.push_back(52.36);
    num.push_back(485.35);
    num.push_back(156.32);

    t1.insert(aux2->at(1),num);
    cout<<"Tree with Double:"<<endl;
    cout<<"Pre-Order"<<endl;
    t1.preorder(aux);
    cout<<endl;
    cout<<"Post-Order"<<endl;
    t1.posOrder(aux);
*/
    Tree<int> t1;
    Node<int> *aux;
    vector<Node<int>*> *aux2;
    vector<int> num;

    num.push_back(15);
    num.push_back(42);
    aux = t1.init(3);
    aux2 = t1.insert(aux,num);

    num.clear();
    num.push_back(3);
    num.push_back(5);
    num.push_back(10);
    t1.insert(aux2->at(0),num);

    num.clear();

    num.push_back(68);
    num.push_back(52);
    num.push_back(4);
    num.push_back(1);

    t1.insert(aux2->at(1),num);
    cout<<"Tree with Double:"<<endl;
    cout<<"Pre-Order"<<endl;
    t1.preorder(aux);
    cout<<endl;
    cout<<"Post-Order"<<endl;
    t1.posOrder(aux);
    cout<<endl;



    return 0;
}

