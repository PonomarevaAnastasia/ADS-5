// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size = 0>
class TStack {
 private:
    T arr[size] = {0};
    int obj;

 public:
    TStack() {
        obj = -1;
    }
    void Push(const T& value) {
        if (!isFull()) {
            arr[++obj] = value;
        }
    }
    T get() const {
        return arr[obj];
    }
    T pop() {
        return arr[obj--];
    }
    int GetTop() const { return top; }
    bool isEmpty() const {
        return obj == -1;
    }
    bool isFull() const {
        return obj == size;
    }
};

#endif  // INCLUDE_TSTACK_H_
