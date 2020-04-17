//
// Created by fell2 on 24.03.2020.
//

#ifndef THEFIRSTAPP_DYNAMICARRAY_H
#define THEFIRSTAPP_DYNAMICARRAY_H


template<class T>
class DynamicArray {
private:
    T *items;
    int count{};
public:
    DynamicArray();

    DynamicArray(T *items, int count);

    DynamicArray(int count);

    DynamicArray(const DynamicArray<T> &dynamicArray);

    T get(int index);

    int getSize();

    T *getItems();

    DynamicArray<T> *getSubArray(int startIndex, int endIndex);

    void set(int index, T value);

    void resize(int newSize);

    void print();
};

#endif //THEFIRSTAPP_DYNAMICARRAY_H
