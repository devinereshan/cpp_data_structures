#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H



template <typename T>
class ArrayStack{
    static const int MIN_CAPACITY = 8;
    T* m_arr;
    int m_size;
    int m_capacity;

    void resize(int cap) {
        m_capacity = cap;
        T* b = new T[m_capacity];
        for (int i = 0; i < m_size; i++)
            b[i] = m_arr[i];

        delete[] m_arr;
        m_arr = b;
    }
public:
    ArrayStack() {
        m_size = 0;
        m_capacity = 8;
        m_arr = new T[m_capacity];
    }

    ~ArrayStack() {
        if (m_arr != NULL)
            delete[] m_arr;
    }

    // add 'val' to the top of the stack
    void push(T val) {
        m_arr[m_size] = val;
        m_size++;

        if (m_size == m_capacity) {
            resize(m_capacity * 2);
        }
    }

    // remove the value from the top of the stack and return it
    T pop() {
        --m_size;
        T x = m_arr[m_size];

        if (m_capacity > MIN_CAPACITY && m_size * 3 < m_capacity) {
            resize(m_capacity / 2);
        }

        return x;
    }

    // return the size of the stack
    int size() {
        return m_size;
    }

    // return the capacity of the stack
    int capacity() {
        return m_capacity;
    }
};

#endif