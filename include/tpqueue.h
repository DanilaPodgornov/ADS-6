// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T *arr;
    int head, tail, count;

 public:
    TPQueue();
    ~TPQueue();
    void push(T value);
    T pop();
    bool isEmpty() const;
    bool isFull() const;
};

template<typename T, int size>
inline TPQueue<T, size>::TPQueue():head(0), tail(0), count(0) {
    this->arr = new T[size];
}

template<typename T, int size>
inline TPQueue<T, size>::~TPQueue() {
    delete [] arr;
}

template<typename T, int size>
inline void TPQueue<T, size>::push(T value) {
    if (isFull()) {
        throw std::string("Queue is Full!");
    } else {
        int temp;
        if (tail == 0) {
            temp = size - 1;
        } else {
            temp = --tail;
        }
        while (value.prior > arr[temp].prior) {
            arr[++temp % size] = arr[temp];
            temp--;
        }
        arr[temp] = value;
        count++;
        tail = ++tail % size;
    }
}

template<typename T, int size>
inline T TPQueue<T, size>::pop() {
    if (isEmpty) {
        throw std::string("Queue is Empty!");
    } else {
        int out = head;
        count--;
        head = ++head % size;
        return arr[out];
    }
}

template<typename T, int size>
inline bool TPQueue<T, size>::isEmpty() const {
    return count == 0;
}

template<typename T, int size>
inline bool TPQueue<T, size>::isFull() const {
    return count == size;
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
