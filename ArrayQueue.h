#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

template<typename T>
class ArrayQueue {
    static const int MIN_CAPACITY = 8;
    T* m_arr;
    int m_capacity;
    int m_front;
    int m_back;

    void resize(int cap) {
        T* b = new T[cap];
        int size = m_back - m_front;
        for (int i = 0; i < size; i++)
            b[i] = m_arr[(i + m_front) % m_capacity];

        delete[] m_arr;
        m_arr = b;
        m_front = 0;
        m_back = size;
        m_capacity = cap;
    }

public:
    ArrayQueue() {
        m_capacity = MIN_CAPACITY;
        m_front = 0;
        m_back = 0;
        m_arr = new T[m_capacity];
    }

    ~ArrayQueue() {
        if (m_arr != NULL)
            delete[] m_arr;
    }


    void enqueue(T val) {
        m_arr[m_back % m_capacity] = val;
        m_back++;

        if (m_back - m_front == m_capacity)
            resize(m_capacity * 2);
    }

    T dequeue() {
        T x = m_arr[m_front % m_capacity];
        m_front++;
        if (m_capacity > MIN_CAPACITY && (m_back - m_front) * 3 < m_capacity)
            resize(m_capacity / 2);

        return x;
    }

    T peek() {
        return m_arr[m_front % m_capacity];
    }

    int size() {
        return m_back - m_front;
    }
};

#endif