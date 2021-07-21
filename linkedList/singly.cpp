/**
 * @brief Program to implement generic singly linked list
 * @author Ajay Biswas
 *
 */

#include<iostream>

template<class T>
class Node
{
    public:
    T data;
    Node* next;
};

/**
 * Prints elements of a linked list
 *
 * @tparam head Start of the list
 * @return void
 */
template<class T>
void printList(Node<T>* head)
{
    Node<T>* trav = head;

    while(trav != nullptr)
    {
        std::cout<<trav->data<<" ";
        trav = trav->next;
    }
    std::cout<<"\n";
}

/**
 * Insert elements at the end of a Linked List
 *
 * @tparam head Start of the list
 * @tparam value Value to be inserted
 * @return void
 */
template<class T>
void insertEnd(Node<T>* &head, T value)
{
    Node<T>* temp = new Node<T>();
    temp->data = value;
    temp->next = nullptr;

    Node<T>* trav = head;

    if(trav == nullptr)
    {
        head = temp;
    }
    else
    {
        while(trav->next != nullptr)
        {
            trav = trav->next;
        }
        trav->next = temp;
    }
}

/**
 * Insert elements at the start of a Linked List
 *
 * @tparam head Start of the list
 * @tparam value Value to be inserted
 * @return void
 */
template<class T>
void insertBeg(Node<T>* &head, T value)
{
    Node<T>* temp = new Node<T>();
    temp->data = value;
    temp->next = nullptr;

    temp->next = head;
    head = temp;
}

/**
 * Insert elements at a particular position 
 * of a linked list
 *
 * @tparam head Start of the list
 * @param index Position to be inserted starting from 0
 * @tparam value Value to be inserted
 * @return void
 */
template<class T>
void insertAt(Node<T>* &head, int index, T value)
{
    if(index < 0)              
    {
        std::cerr<<"Wrong index\n";
        return;
    }
    else if(index == 0)                 // same as insert at beginning
    {
        insertBeg(head,value);
        return;
    }

    Node<T>* temp = new Node<T>();
    temp->data = value;
    temp->next = nullptr;

    Node<T>* trav = head;
    int count = 0;

    while(trav->next != nullptr && count < index-1)   // check overflow also
    {
        trav = trav->next;
        count++;
    }

    Node<T>* behind = trav->next;       // nodes after index (can be nullptr too)

    if(count == index-1)                // trav-next is at index 
    {
        trav->next = temp;
        temp->next = behind;
    }
    else
    {
        std::cerr<<"Wrong index\n";
        return;
    }
    
}


int main()
{
    Node<int>* head = nullptr;

    insertEnd(head,1);
    insertEnd(head,2);
    insertEnd(head,3);
    insertEnd(head,4);
    insertEnd(head,5);
    insertEnd(head,6);
    insertEnd(head,7);

    insertAt(head,6,-1);

    printList(head);

    return 0;
}