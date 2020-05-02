//
// Created by fell2 on 31.03.2020.
//

#include "../Sequence.h"
#include "LinkedList/LinkedList.h"

#ifndef THEFIRSTAPP_LINKEDLISTSEQUENCE_H
#define THEFIRSTAPP_LINKEDLISTSEQUENCE_H

template<class T>
class LinkedListSequence : public Sequence<T> {
private:
    LinkedList<T> *list;
public:
    LinkedListSequence(T *items, int count);

    LinkedListSequence();

    LinkedListSequence(const LinkedListSequence<T> &linkedList);

    int getLength() const override;

    T getFirst() const override;

    T getLast() const override;

    T get(const int i) const override;

    Sequence<T> *getSubsequence(const int startIndex, const int endIndex) const override;

    void append(T value) override;

    void prepend(T value) override;

    virtual void set(int index, T value) override;

    void insertAt(const int index, T value) override;

    Sequence<T> *concat(Sequence<T> *list) override;

    void print() override;

    ~LinkedListSequence() = default;
};

#endif //THEFIRSTAPP_LINKEDLISTSEQUENCE_H
