#include "node.hh"

class linkedList {
private:
Node* head;
Node* trailer;
public:
linkedList();
~linkedList();

void insertFirst(const MovieEntry& newEntry);
void insertAfter(Node* currentNode, const MovieEntry& newEntry);
void displayAll();
bool isEmpty();

Node* getHead() {return this->head;}

};

linkedList::linkedList()
{
    this->head = NULL;
    this->trailer = NULL;
}

linkedList::~linkedList()
{
    delete this->head;
    delete this->trailer;
}

void linkedList::insertFirst(const MovieEntry& newEntry)
{
    if(this->isEmpty())
   {
        Node* temp = new Node(this->head, newEntry, this->trailer);
        this->head = temp;
        this->trailer = temp;
    }
    else
    {
        Node* temp = new Node(NULL, newEntry, this->head); // Nastepny musi pokazac na poprzedni
        (this->head)->setPrev(temp);                       // Ewentualne danie headowi nexta i preva
        this->head=temp;
    }
}

void linkedList::insertAfter(Node* currentNode, const MovieEntry& newEntry)
{
    Node* temp = new Node();
    temp->setElement(newEntry);
    if(currentNode->getNext() == NULL)
    {
        temp->setNext(this->trailer);
        this->trailer = temp;
    }
    else
    {
        temp->setNext(currentNode->getNext());
        (currentNode->getNext())->setPrev(temp);
    }
    temp->setPrev(currentNode);
    currentNode->setNext(temp);
}

bool linkedList::isEmpty()
{
    return (this->head==NULL);
}

void linkedList::displayAll()
{
    if(this->isEmpty())
    {
    Node* temp = this->head;
    temp->getElement().display();
        while(temp->getNext()!=NULL)
        {
            temp = temp->getNext();
            temp->getElement().display();
        }
    }
}