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
    int union_sets(int first, int second);
    void clear();
    int get_size();
    int get_rank(int num);
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

int DSU::get_size() {
    return _size;
}


void DSU::make_set(int elem) {
    if (elem <= 0 || elem > _size) {
        throw std::logic_error("Input Error: Element out of bounds.");
    }

    elem--; 

    _parent[elem] = elem;
    _rank[elem] = 0;
}

int DSU::find(int elem) { // elem = 10
    if (elem <= 0 || elem > _size) {
        throw std::logic_error("Input Error: Element out of bounds.");
    }

    elem--; // elem = 9

    return _parent[elem];
}

int DSU::get_rank(int num) {
    return _rank[find(num)];
}

int DSU::union_sets(int first, int second) { // first = 1, second = 10
    
    int root1 = find(first);// root1 = 0
    int root2 = find(second);// root2 = 9

    if (_rank[root1] == 0) {
        _rank[root1] = 1;
    }
    else 
    {
        _rank[root1] += _rank[root2];
    }
    _parent[root2] = root1;
    return 0;


}

void DSU::clear() {
    delete[] _parent;
    delete[] _rank;
    _size = 0;
    _parent = nullptr;
    _rank = nullptr;
}
