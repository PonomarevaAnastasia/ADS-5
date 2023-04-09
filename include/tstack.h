// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
    static constexpr int size = 100;
    type arr[size];
    int Obj = -1;
    
 public:
    TStack() = default;
    type get() const {
        return arr[Obj];
    }
    bool isEmpty() const {
        return Obj == -1;
    }
    bool isFull() const {
        return Obj == size - 1;
    }
    void pop() {
        if (!isEmpty()) {
            --Obj;
        }
    }
    void push(type Item) {
        if (!isFull()) {
            arr[++Obj] = Item;
        }
    }
};

#endif  // INCLUDE_TSTACK_H_
