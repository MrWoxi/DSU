// Copyright 2025 <Victor Klimovich>
#pragma once

#include <iostream>
#include <vector>

enum Color { RED, BLACK };

struct RBNode {
    int data;               
    Color color;          
    RBNode* left;         
    RBNode* right;        
    RBNode* parent;    

    RBNode(int value) : data(value), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    RBNode* root;

    
    void rotateLeft(RBNode*& node);
    void rotateRight(RBNode*& node);
    void fixViolation(RBNode*& node);

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int value);
    void inorder(); 
    void inorderHelper(RBNode* node);
};