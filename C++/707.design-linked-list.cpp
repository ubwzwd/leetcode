/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 *
 * https://leetcode.com/problems/design-linked-list/description/
 *
 * algorithms
 * Easy (21.01%)
 * Likes:    358
 * Dislikes: 484
 * Total Accepted:    33.4K
 * Total Submissions: 159.6K
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * Design your implementation of the linked list. You can choose to use the
 * singly linked list or the doubly linked list. A node in a singly linked list
 * should have two attributes: val and next. val is the value of the current
 * node, and next is a pointer/reference to the next node. If you want to use
 * the doubly linked list, you will need one more attribute prev to indicate
 * the previous node in the linked list. Assume all nodes in the linked list
 * are 0-indexed.
 * 
 * Implement these functions in your linked list class:
 * 
 * 
 * get(index) : Get the value of the index-th node in the linked list. If the
 * index is invalid, return -1.
 * addAtHead(val) : Add a node of value val before the first element of the
 * linked list. After the insertion, the new node will be the first node of the
 * linked list.
 * addAtTail(val) : Append a node of value val to the last element of the
 * linked list.
 * addAtIndex(index, val) : Add a node of value val before the index-th node in
 * the linked list. If index equals to the length of linked list, the node will
 * be appended to the end of linked list. If index is greater than the length,
 * the node will not be inserted. If index is negative, the node will be
 * inserted at the head of the list.
 * deleteAtIndex(index) : Delete the index-th node in the linked list, if the
 * index is valid.
 * 
 * 
 * Example:
 * 
 * 
 * MyLinkedList linkedList = new MyLinkedList();
 * linkedList.addAtHead(1);
 * linkedList.addAtTail(3);
 * linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
 * linkedList.get(1);            // returns 2
 * linkedList.deleteAtIndex(1);  // now the linked list is 1->3
 * linkedList.get(1);            // returns 3
 * 
 * 
 * Note:
 * 
 * 
 * All values will be in the range of [1, 1000].
 * The number of operations will be in the range of [1, 1000].
 * Please do not use the built-in LinkedList library.
 * 
 * 
 */
class MyLinkedList {
private:
    // doubly linked list
    struct LinkedListNode
    {
        int val;
        LinkedListNode* next;
        LinkedListNode* prev;
    };
    LinkedListNode* head;
    LinkedListNode* tail;
    int size;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= size || index < 0)
            return -1;
        LinkedListNode* cur = head;
        for(int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkedListNode* temp = new LinkedListNode;
        temp->val = val;
        temp->next = head;
        head = temp;
        if(size == 0)   tail = temp;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedListNode* temp = new LinkedListNode;
        temp->val = val;
        if(size == 0){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size)
            return;
        if(index <= 0) addAtHead(val);
        else if(index == size)  addAtTail(val);
        else{
            LinkedListNode* temp = new LinkedListNode;
            temp->val = val;
            LinkedListNode* cur = head;
            for(int i = 0; i < index - 1; i++){
                cur = cur->next;
            }
            // now cur is at index-1
            temp->prev = cur;
            temp->next = cur->next;
            cur->next = temp;
            cur = temp->next;
            cur->prev = temp;
            size++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=size || index < 0) return;
        // remove the head
        else if(index == 0){
            LinkedListNode* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
        else{
            LinkedListNode* cur = head;
            for(int i = 0; i < index - 1; i++){
                cur = cur->next;
            }
            LinkedListNode* temp = cur->next;
            if(index < size - 1){
                cur->next = temp->next;
                temp->next->prev = temp->prev;
            }
            else{
                // index is the tail
                cur->next = temp->next;
                tail = cur;
            }
            delete temp;
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

