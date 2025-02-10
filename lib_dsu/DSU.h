// Copyright 2025 <Victor Klimovich>
#pragma once

#include <iostream>
#include <utility>
#include <algorithm>
#include <stdexcept>

class DSU {
    int _size;
    int* _parent;
    int* _rank;

public:
    DSU(int size = 0);
    ~DSU();
    void make_set(int elem);
    int find(int elem);
    void union_sets(int first, int second);
    void clear();
};

DSU::DSU(int size) : _size(size) {
    _parent = new int[size];
    _rank = new int[size];
    for (int i = 0; i < size; ++i) {
        make_set(i + 1); 
    }
}

DSU::~DSU() {
    delete[] _parent;
    delete[] _rank;
}

void DSU::make_set(int elem) {
    if (elem <= 0 || elem > _size) {
        throw std::logic_error("Input Error: Element out of bounds.");
    }

    elem--; 

    _parent[elem] = elem;
    _rank[elem] = 0;
}

int DSU::find(int elem) {
    if (elem <= 0 || elem > _size) {
        throw std::logic_error("Input Error: Element out of bounds.");
    }

    elem--; 

    if (_parent[elem] != elem) {
        _parent[elem] = find(_parent[elem]); 
    }
    return _parent[elem];
}

void DSU::union_sets(int first, int second) {
    
    int root1 = find(first);
    _parent[second] = root1;

}

void DSU::clear() {
    delete[] _parent;
    delete[] _rank;
    _size = 0;
    _parent = nullptr;
    _rank = nullptr;
}
