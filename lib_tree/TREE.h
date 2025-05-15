// Copyright 2025 <Victor Klimovich>
#pragma once

#include <utility>
#include "../lib_node/Node.cpp"


class Tree {
    int _size;
    Node* _root;
public:
    Tree();
    Tree(int value);
    ~Tree();
    void insert(int value);
    int* get_left();
    int get_size();
};

Tree::Tree() : _root(nullptr), _size(0) {}
Tree::Tree(int value){
    _size = 1;
    Node* newNode = new Node(value);
    _root = newNode;
}
Tree::~Tree(){ delete[] _root;}

void Tree::insert(int value) {
    Node* newNode = new Node(value);

    if (_root == nullptr) { _root = newNode; _size++; return; }

    Node* current = _root;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (value < current->data) { current = current->left; }
        else if (value > current->data) { current = current->right; }
        else { delete newNode; return; }
    }
    _size++;
    if (value < parent->data) { parent->left = newNode; }
    else { parent->right = newNode; }
}
int* Tree::get_left(){
    Node* current = _root;
    int* data = new int[5]; 
    int index = 0;

    while (current != nullptr && index < 5) {
        data[index] = current->data;
        current = current->left;
        index++;
    }

    return data; 
    
}
int Tree::get_size() { return _size; }

