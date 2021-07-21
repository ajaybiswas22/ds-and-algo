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
    Node* prev;
};

/**
 * Prints elements of a Doubly linked list
 *
 * @tparam head Start of the list
 * @tparam tail End of the List
 * @param reverse If true, then the list will be printed in reverse
 * @return void
 */
template<class T>
void printListDoubly(Node<T>* head, Node<T>* tail, bool reverse = false)
{
    if(head == nullptr)
    {
        std::cerr<<"List is empty\n";
        return;
    }

    if(reverse == false)
    {
        Node<T>* trav = head;
        while(trav != nullptr)
        {
            std::cout<<trav->data<<" ";
            trav = trav->next;
        }
    }
    else
    {
        Node<T>* trav = tail;
        while(trav != nullptr)
        {
            std::cout<<trav->data<<" ";
            trav = trav->prev;
        }
    }
    
    std::cout<<"\n";
}

/**
 * Creates a new Node for Double Linked List
 *
 * @tparam value Value to be inserted
 * @return Node of Type T
 */
template<class T>
Node<T>* newNodeD(T value)
{
    Node<T>* temp = new Node<T>();
    temp->data = value;
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}

/**
 * Insert elements at the end of a Doubly Linked List
 *
 * @tparam head Start of the List
 * @tparam tail End of the List
 * @tparam value Value to be inserted
 * @return void
 */
template<class T>
void insertEnd(Node<T>* &head, Node<T>* &tail, T value)
{
    Node<T>* temp = newNodeD(value);

    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        Node<int>* previous = tail;
        tail->next = temp;
        tail = temp;
        tail->prev = previous;
    }
}

/**
 * Insert elements at the start of a Linked List
 *
 * @tparam head Start of the list
 * @tparam tail End of the List
 * @tparam value Value to be inserted
 * @return void
 */
template<class T>
void insertBeg(Node<T>* &head, Node<T>* &tail, T value)
{
    Node<T>* temp = newNodeD(value);

    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        Node<int>* after = head;
        head->prev = temp;
        head = temp;
        head->next = after;
    }
}

/**
 * Insert elements at a particular position 
 * of a linked list
 *
 * @tparam head Start of the list
 * @tparam tail End of the List
 * @param index Position to be inserted starting from 0
 * @tparam value Value to be inserted
 * @return void
 */
template<class T>
void insertAt(Node<T>* &head, Node<T>* &tail, int index, T value)
{
    if(index < 0)              
    {
        std::cerr<<"Wrong index\n";
        return;
    }
    else if(index == 0)                 // same as insert at beginning
    {
        insertBeg(head,tail,value);
        return;
    }

    Node<T>* temp = newNodeD(value);

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
        temp->prev = trav;
        temp->next = behind;
        behind->prev = temp;
    }
    else
    {
        std::cerr<<"Wrong index\n";
        return;
    }
    
}

/**
 * Delete elements from the end of a Doubly Linked List
 *
 * @tparam head Start of the List
 * @tparam tail End of the List
 * @return void
 */
template<class T>
void deleteEnd(Node<T>* &head, Node<T>*  &tail)
{
    if(head == nullptr)
    {
        std::cerr<<"No node to Delete (List Empty)\n";
        return;
    }

    if(tail->prev == nullptr)
    {
        Node<T>* temp = tail;
        
        head = nullptr;
        tail = nullptr;
        free(temp);
    }
    else
    {
        Node<T>* temp = tail;        
        tail = tail->prev;
        tail->next = nullptr;

        free(temp);
    }
}

/**
 * Delete elements from the beginning of a Doubly Linked List
 *
 * @tparam head Start of the List
 * @tparam tail End of the List
 * @return void
 */
template<class T>
void deleteBeg(Node<T>* &head, Node<T>* &tail)
{
    if(head == nullptr)
    {
        std::cerr<<"No node to Delete (List Empty)\n";
        return;
    }

    if(head->next == nullptr)
    {
        Node<T>* temp = head;
        
        head = nullptr;
        tail = nullptr;
        free(temp);
    }
    else
    {
        Node<T>* temp = head;        
        head = head->next;
        head->prev = nullptr;

        free(temp);
    }
}

/**
 * Delete elements from the secified index of a Doubly Linked List
 *
 * @tparam head Start of the List
 * @tparam tail End of the List
 * @param index Index to be deleted
 * @return void
 */
template<class T>
void deleteAt(Node<T>* &head, Node<T>* &tail, int index)
{
    if(head == nullptr)
    {
        std::cerr<<"No node to Delete (List Empty)\n";
        return;
    }

    if(index == 0)
    {
        deleteBeg(head,tail);
        return;
    }
    if(index < 0)              
    {
        std::cerr<<"Wrong index\n";
        return;
    }

    Node<T>* trav = head;
    int count = 0;

    while(trav->next != nullptr && count < index)
    {
        trav = trav->next;
        count++;
    }

    if(count == index && trav->next != nullptr)
    {
        trav->prev->next = trav->next;
        trav->next->prev = trav->prev;
        free(trav);
    }
    else if(count == index && trav->next == nullptr)
    {
        deleteEnd(head,tail);
        return;
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
    Node<int>* tail = nullptr;
    insertBeg(head,tail,1);
    insertEnd(head,tail,2);
    insertEnd(head,tail,3);
    
    deleteAt(head,tail,4);

    printListDoubly(head,tail,true);

    return 0;
}