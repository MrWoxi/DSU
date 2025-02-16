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
    RBNode(int value) : data(value), color(BLACK), left(nullptr), right(nullptr), parent(nullptr) {}
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
            RepaintingRBNode(newNode);
        }
    }
    std::pair<RBNode*, bool> SearchBST_render(int target) {
        std::pair<RBNode*, bool> result = searchBST(root, target);
        std::cout << result.second;
        return result;
    }
    std::pair<RBNode*, bool> SearchBST(int target) {
        std::pair<RBNode*, bool> result = searchBST(root, target);
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

     void RepaintingRBNode(RBNode*& currentNode) {
         if (currentNode == root) return;

         RBNode* RBNodeDad = currentNode->parent;
         if (RBNodeDad == nullptr) return; 
         if (RBNodeDad->color == BLACK) return;

         RBNode* RBNodeGrandDad = RBNodeDad->parent;
         RBNode* RBNodeUncle = nullptr;

         if (RBNodeGrandDad != nullptr) {
             if (RBNodeGrandDad->left == RBNodeDad) {
                 RBNodeUncle = RBNodeGrandDad->right;
             }
             else {
                 RBNodeUncle = RBNodeGrandDad->left;
             }
         }


         if (RBNodeUncle != nullptr && RBNodeUncle->color == RED) {
             RBNodeUncle->color = BLACK;
             RBNodeDad->color = BLACK;
             if (RBNodeGrandDad != root) {
                 RBNodeGrandDad->color = RED;
             }
             currentNode = RBNodeGrandDad; 
             RepaintingRBNode(currentNode); 
             return;
         }

        
         
         if (RBNodeDad->right == currentNode) { 
             currentNode->left = RBNodeDad;
             RBNodeDad->right = nullptr;
         }
         else { 
             currentNode->right = RBNodeDad;
             RBNodeDad->left = nullptr; 
         }

        
         RBNodeDad->color = BLACK;
         currentNode->color = RED;

         
         if (RBNodeGrandDad != nullptr) {
             if (RBNodeGrandDad->left == RBNodeDad) {
                 RBNodeGrandDad->left = currentNode;
             }
             else {
                 RBNodeGrandDad->right = currentNode;
             }
         }
         else {
             root = currentNode; 
         }
     }


     std::pair<RBNode*, bool> searchBST(RBNode* node, int target) {

        if (node == nullptr) {
            return { nullptr , false };
        }

        if (node->data == target) {

            return { node , true };
        }

        if (target < node->data) {
            return searchBST(node->left, target);
        }
        else {
            return searchBST(node->right, target);
        }

     }

    // true - добавлен новый | false - элемент сущесвует добавление не будет  
    bool insertBST(RBNode*& currentNode, RBNode* newNode) {
        if (newNode->data == currentNode->data) return false;


        if (newNode->data < currentNode->data) {
            if (currentNode->left == nullptr) {
                newNode->parent = currentNode;
                newNode->color = RED;
                currentNode->left = newNode;
                return true;
            }
            insertBST(currentNode->left, newNode);
            
        }
        else {
            if (currentNode->right == nullptr) {
                newNode->parent = currentNode;
                newNode->color = RED;
                currentNode->right = newNode;
                return true;
            }
            insertBST(currentNode->right, newNode);
        }

    }

};

