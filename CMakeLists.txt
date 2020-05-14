cmake_minimum_required(VERSION 3.15)
project(theFirstApp)

set(CMAKE_CXX_STANDARD 14)

add_executable(theFirstApp main.cpp Sequence/ArraySequence/DynamicArray/DynamicArray.cpp Sequence/ArraySequence/DynamicArray/DynamicArray.h Sequence/ListSequence/LinkedList/LinkedList.cpp Sequence/ListSequence/LinkedList/LinkedList.h Sequence/Sequence.h Sequence/ListSequence/LinkedListSequence.cpp Sequence/ListSequence/LinkedListSequence.h Sequence/ArraySequence/ArraySequence.cpp Sequence/ArraySequence/ArraySequence.h DiagonalMatrix.cpp DiagonalMatrix.h Complex/Complex.cpp Complex/Complex.h)