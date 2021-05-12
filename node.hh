#include <iostream>
#include <cstdlib>
#include "MovieEntry.hh"

class Node {
    private:
    MovieEntry elem;
    Node* next;
    Node* prev;

    public:
    Node();
    Node(Node* newPrev, MovieEntry newElem, Node* newNext);
    Node(const Node& newNode);
    ~Node();
    MovieEntry getElement() {return this->elem;}
    Node* getNext() {return this->next;}
    Node* getPrev() {return this->prev;}
    void setElement(MovieEntry newElem) {this->elem=newElem;}
    void setNext(Node*  newNext) {this->next=newNext;}
    void setPrev(Node*  newPrev) {this->next=newPrev;}
};

Node::Node()
{
    this->prev = NULL;
    this->next = NULL;
}

Node::Node(Node* newPrev, MovieEntry newElem, Node* newNext)
{
    this->elem = newElem;
    this->next = newNext;
    this->prev = newPrev;
}

Node::Node(const Node& newNode)
{
    this->elem = newNode.elem;
    this->next = newNode.next;
    this->prev = newNode.prev;
}

Node::~Node()
{
    delete this->next;
    delete this->prev;
}

