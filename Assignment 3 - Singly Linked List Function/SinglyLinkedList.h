//
//  
//  SinglyLinkedList.h
//
//  Created by Ariel Katz on 2/7/23.
//  Modified by Eisig Liang on 9/9/24
//

#ifndef SLinkedList_h
#define SLinkedList_h

#include "ListType.h"
#include <assert.h>
using namespace std;

template <class Type>
class SinglyLinkedList: public ListType<Type> {
public:
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      // Returns true if searchItem is in the

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //newItem becomes head and count is incremented by 1.

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //newItem becomes tail and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing
      //               deleteItem is deleted from the list
      //               and count is decremented by 1.

};

template <class Type>
bool SinglyLinkedList<Type>::
                   search(const Type& searchItem) const
{
    NodeType<Type> *current; //pointer to traverse the list
    current = this->head; //start search at the beginning

    //as long as there is more to search
    //and the node hasn't been found - keep searching
    while (current != NULL )
        if (current->data == searchItem)
            return true;
        else{
            current = current->next; //step forward
        }
    
    return false;
}//end search


template <class Type>
void SinglyLinkedList<Type>::insertFirst(const Type& newItem){
    //Create a new Node
    NodeType<Type> *newNode = new NodeType<Type>;
    newNode->data = newItem;
    newNode->next = this->head;//Have the new node point to the first node with data
    
    //Update the Linked List head to point at the new Node
    this->head = newNode;

    // update count!
    this->count += 1;
    
}

template <class Type>
void SinglyLinkedList<Type>::insertLast(const Type& newItem){
    // Complete your code here!
	//insertLast code
    
    //Create a new node
    NodeType<Type>* newNode = new NodeType<Type>;
    newNode->data = newItem;
    newNode->next = NULL;

    //Traverse the list
    NodeType<Type>* current = this->head; //pointer to traverse the list
    while (current->next != NULL) {
        current = current->next;
    }

    //Update the Linked List tail to point at the new Node
    current->next = newNode;

    //update count
    this->count += 1;
}

template <class Type>
void SinglyLinkedList<Type>::deleteNode(const Type& deleteItem){

    assert(! this->isEmptyList());
    NodeType<Type> *prevNode {nullptr};
    NodeType<Type> *current = this->head;
    
    
    // Edge case: what if head is item to be deleted??
    if(current->data == deleteItem){
        this->head = current->next;
    } else {
        while (current != NULL) { //Changed this to check if current is NULL, otherwise it'll skip the last one
            //is current data item to be deleted?
            if(current->data == deleteItem){
                prevNode->next = current->next;
                break;
            }
            prevNode = current;
            current = current->next; //step forward
        }
    }
    
    this->count -= 1;
    
}



#endif /* SLinkedList_h */
