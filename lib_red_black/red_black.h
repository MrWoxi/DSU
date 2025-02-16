// Copyright 2025 <Victor Klimovich>
#pragma once

#include <utility>
#include <iostream>
#include <string>

enum Color { RED, BLACK };

class RBNode {
public:
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
    void sortTree() {
        
    }

 public:
    RedBlackTree() : root(nullptr) {}

    void insert(int value) {
        RBNode* newNode = new RBNode(value);
        if (root == nullptr) {
            root = newNode;
            root->color = BLACK; 
            return;
        }
        bool flagNewNode = insertBST(root, newNode);
        if (flagNewNode) {
            sortTree();
        }
    }
    std::pair<RBNode*, bool> renderSearchBST(int target) {
        std::pair<RBNode*, bool> result = searchBST(root, target, 0);
        std::cout << result.second;
        return result;
    }
    std::pair<RBNode*, bool> SearchBST(int target) {
        std::pair<RBNode*, bool> result = searchBST(root, target, 0);
        return result;
    }
    RBNode* min() {
        RBNode* node = root;
        if (node == nullptr) return nullptr;
        while (true) {
            if (node->left != nullptr) {
                node = node->left;
                continue;
            }
            return node;
            
        }
    }
    RBNode* max() {
        RBNode* node = root;
        if (node == nullptr) return nullptr;
        while (true) {
            if (node->right != nullptr) {
                node = node->right;
                continue;
            }
            return node;

        }
    }

 private:

     std::pair<RBNode*, bool> searchBST(RBNode* node, int target,int num) {

        if (node == nullptr) {
            return { nullptr , false };
        }

        if (node->data == target) {

            return { node , true };
        }

        if (target < node->data) {
            return searchBST(node->left, target, ++num);
        }
        else {
            return searchBST(node->right, target, ++num);
        }

     }

    bool insertBST(RBNode*& currentNode, RBNode* newNode) {
     
        if (currentNode == nullptr) {
            currentNode = newNode;
            newNode->parent = currentNode;
            return true;
        }

        if (newNode->data == currentNode->data) {
            return false;
        }


        if (newNode->data < currentNode->data) {
            if (currentNode->left == nullptr) {
                currentNode->left = newNode;
                newNode->parent = currentNode;
                return true;
            }
            insertBST(currentNode->left, newNode);
            
        }
        else {
            if (currentNode->right == nullptr) {
                currentNode->right = newNode;
                newNode->parent = currentNode;
                return true;
            }
            insertBST(currentNode->right, newNode);
        }

    }

};

