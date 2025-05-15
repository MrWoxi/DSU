// Copyright 2025 <Victor Klimovich>
#pragma once

class Node {
public:
    int data;               
    Node* left;         
    Node* right;        
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

enum Color { RED, BLACK };

class RBNode {
public:
    int data;               
    Color color;          
    RBNode* left;         
    RBNode* right;        
    RBNode* parent;    
    RBNode(int value) : data(value), color(BLACK), left(nullptr), right(nullptr), parent(nullptr) {}
};