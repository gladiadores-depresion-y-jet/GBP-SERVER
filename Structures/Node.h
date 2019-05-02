//
// Created by dcamachog1501 on 24/04/19.
//

#ifndef GBP_SERVER_NODE_H
#define GBP_SERVER_NODE_H

template <class T>
class Node
{
private:
    T value;
    int order;
    Node* next;
public:
    Node()
    {
        this->next= nullptr;
    }
    Node(T v,int o)
    {
        this->value=v;
        this->order=o;
        this->next= nullptr;
    }
    T getValue()
    {
        return value;
    }
    Node* getNext()
    {
        return next;
    }
    void setNext(T v,int o)
    {
        Node<T>* n= new Node(v,o);
        this->next=n;

    }
    void setNext(Node<T>* node)
    {
        this->next=node;
    }
    int getOrder()
    {
        return this->order;
    }
    void purge()
    {
        this->order=0;
        this->value= nullptr;
        this->next= nullptr;
    }
    void setOrder(int o)
    {
        this->order=o;
    }
};


#endif //GBP_SERVER_NODE_H
