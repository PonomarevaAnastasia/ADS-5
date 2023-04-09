// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
   private:
    T arr[100];
    int Obj;
 public:
    Tstack() :Obj(-1) {}
    void push(T value) {
      if (isFull()) {
        throw std::string("Stack is full");
      } else {
        arr[++Obj] = value;
      }
    }
      const T& pop() {
      if (isEmpty()) {
        throw std::string("Stack is empty");
      } else {
        return arr[Obj--];
      }
    }
    bool isEmpty()const {
      return Obj == -1;
    }
    bool isFull()const {
      return Obj == size - 1;
    }
    const T& get()const {
      return arr[Obj];
    }
};

#endif  // INCLUDE_TSTACK_H_
