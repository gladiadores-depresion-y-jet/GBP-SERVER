//
// Created by dcamachog1501 on 24/04/19.
//

#ifndef GBP_SERVER_LIST_H
#define GBP_SERVER_LIST_H


#include "Node.h"
template <class T>
class List
{
private:
    Node<T>* head;
    int length;
    List<T>* next;
public:
    List()
    {
        this->head= nullptr;
        this->length=0;
        this->next= nullptr;
    }
    void add(T v)
    {
        Node<T>* n= new Node<T>(v,++length);
        if(this->head== nullptr)
        {
            this->head=n;
        }
        else
        {
            Node<T>* temp= this->head;
            while(temp->getNext()!= nullptr)
            {
                temp=temp->getNext();
            }
            temp->setNext(n);
        }

    }
    void del(int o)
    {
        Node<T>* temp=this->head;
        if(temp->getOrder()==o)
        {
            this->head=temp->getNext();
            temp->purge();
            delete(temp);
            Node<T>* temp2= this->head;
            while(temp2!= nullptr)
            {
                temp2->setOrder(temp2->getOrder()-1);
                temp2=temp2->getNext();
            }
            temp2= nullptr;
            delete(temp2);
        }
        else
        {
            while (temp->getNext()->getOrder() != o) {
                temp = temp->getNext();
            }
            Node<T> *temp2 = temp->getNext();
            temp->setNext(temp2->getNext());
            temp2->purge();
            temp = temp->getNext();
            while (temp != nullptr) {
                temp->setOrder(temp->getOrder() - 1);
                temp = temp->getNext();
            }
            delete (temp);
            delete (temp2);
        }
        length--;
    }
    List<T>* getNext()
    {
        return this->next;
    }
    int getLength()
    {
        return this->length;
    }
    void setNext(List<T>* l)
    {
        this->next=l;
    }
    Node<T>* getHead()
    {
        return this->head;
    }
    void purge()
    {
        int l=this->length;
        for(int i=1;i<=l;i++)
        {
            del(1);
        }
    }
};


#endif //GBP_SERVER_LIST_H
