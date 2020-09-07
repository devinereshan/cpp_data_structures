#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template <typename T>
class DoublyLinkedList {
    struct Node {
        T value;
        Node* next;
        Node* prev;
    };

    Node* m_root;
    int m_size;

    Node* getNode(int index);

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void add(T val, int index);
    T get(int index);
    T remove(int index);
    void set(T val, int index);
    int size();

};

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::getNode(int index) {
    Node* temp;
    if (index * 2 < m_size) {
        temp = m_root->next;
        for (int i = 0; i < index; i++)
            temp = temp->next;
    } else {
        temp = m_root;
        for (int i = m_size; i > index; i--)
            temp = temp->prev;
    }

    return temp;
}


template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    m_root = new Node();
    m_root->next = m_root;
    m_root->prev = m_root;
    m_size = 0;
}


template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* temp = m_root->next;
    while(temp != m_root) {
        temp = temp->next;
        delete temp->prev;
    }

    delete temp;
}


template <typename T>
void DoublyLinkedList<T>::add(T val, int index) {
    if (index > m_size) return;

    Node* old = getNode(index);

    Node* n = new Node();
    n->value = val;
    n->prev = old->prev;
    n->next = old;
    n->prev->next = n;
    old->prev = n;

    m_size++;
}

template <typename T>
T DoublyLinkedList<T>::get(int index) {
    return getNode(index)->value;
}

template <typename T>
T DoublyLinkedList<T>::remove(int index) {
    Node* old = getNode(index);
    old->prev->next = old->next;
    old->next->prev = old->prev;
    T x = old->value;

    delete old;
    m_size--;

    return x;
}

template <typename T>
void DoublyLinkedList<T>::set(T val, int index) {
    getNode(index)->value = val;
}

template <typename T>
int DoublyLinkedList<T>::size() {
    return m_size;
}


#endif