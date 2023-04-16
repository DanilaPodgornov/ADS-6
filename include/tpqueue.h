// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T *arr;
    int head, tail, count;

 public:
    TPQueue():head(0), tail(0), count(0) {
        arr = new T[size];
    }

    ~TPQueue() {
        delete[] arr;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void push(const T& value) {
        if (size != count) {
            int temp = tail;
            for (int i = head; i < tail; i++) {
                if (value.prior > arr[i].prior) {
                    temp = i;
                    break;
                }
            }
            for (int i = tail; i > temp; i--) {
                arr[i % size] = arr[(i - 1) % size];
            }
            arr[temp % size] = value;
            tail = (tail + 1) % size;
            count++;
        }
    }

    T& pop() {
        if (isEmpty()) {
            return NULL;
        } else {
            T out = arr[head];
            head = (head + 1) % size;
            count--;
            return out;
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
