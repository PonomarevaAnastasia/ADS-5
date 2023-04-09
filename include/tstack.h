// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
  private:
    T arr[100];
    int obj;
 public:
    Tstack() :obj(-1) {}
    void push(T value) {
      if (isFull()) {
        throw std::string("Stack is full");
      } else {
        arr[++obj] = value;
      }
    }
      const T& pop() {
      if (isEmpty()) {
        throw std::string("Stack is empty");
      } else {
        return arr[obj--];
      }
    }
    bool isEmpty()const {
      return obj == -1;
    }
    bool isFull()const {
      return obj == size - 1;
    }
    const T& get()const {
      return arr[obj];
    }
};

#endif  // INCLUDE_TSTACK_H_
