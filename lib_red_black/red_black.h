// Copyright 2025 <Victor Klimovich>
#pragma once

#include <utility>
#include <iostream>
#include <string>
#include <queue>
#include "../lib_node/Node.cpp"

class RedBlackTree {
 private:
    RBNode* root;
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
     int lenBlack() {
         RBNode* node = root;
         int sumBlack = 0;
         while (true) {
             if (node->color == BLACK) ++sumBlack;
             if (node->left == nullptr) return ++sumBlack;
             else node = node->left;
         }
     }

 private:
     void LeftSwapPlaces(RBNode*& gradDad, RBNode*& Dad, RBNode*& son) {
         son->parent = gradDad;
         son->left = Dad;
         Dad->parent = son;
         Dad->right = nullptr;
         gradDad->right = son;

     }
     void RightSwapPlaces(RBNode*& gradDad, RBNode*& Dad, RBNode*& son) {
         son->parent = gradDad;
         son->right = Dad;
         Dad->parent = son;
         Dad->left = nullptr;
         gradDad->left = son;
     }

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
            LeftSwapPlaces(RBNodeGrandDad ,RBNodeDad, currentNode);
            RBNodeDad->color = BLACK;
            currentNode->color = RED;
         }
         else if (RBNodeDad->left == currentNode) {
             RightSwapPlaces(RBNodeGrandDad, RBNodeDad, currentNode);
             RBNodeDad->color = BLACK;
             currentNode->color = RED;
         }

         //�������� ��� ������� �� �����
         if (false) {
             RBNodeGrandDad->parent = RBNodeDad;
             RBNodeGrandDad->right = nullptr;
             RBNodeDad->left = RBNodeGrandDad;
             root = RBNodeDad;
         }
         else if (false) {
             RBNodeGrandDad->parent = RBNodeDad;
             RBNodeGrandDad->right = nullptr;
             RBNodeDad->left = RBNodeGrandDad;
             root = RBNodeDad;
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

    // true - �������� ����� | false - ������� ��������� ���������� �� �����  
    bool insertBST(RBNode*& currentNode, RBNode* newNode) {
        if (newNode->data == currentNode->data) return false;


        if (newNode->data > currentNode->data) {
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
    public:
    void displayTrea() {
        RBNode* node = root;
        std::queue<RBNode*> myQueue;
        std::queue<RBNode*> nowQueue;
        int sizeWindow = 110;
        int countHight = 0;
        myQueue.push(root);
        while (!myQueue.empty() || !nowQueue.empty()) {
            int sizeQ = myQueue.size();
            while (!myQueue.empty()) {
                RBNode* nowNode = myQueue.front();
                nowQueue.push(nowNode);
                myQueue.pop();
                for(int i = 0; i < (sizeWindow / (sizeQ + 1)); i++)
                std::cout << " ";
                if (nowNode != nullptr) {
                std::cout << nowNode->data << "";
                }
                else {
                    std::cout << "E" << "";
                }

            }
            countHight++;
            if (countHight >= 6) { return; }
            while (!nowQueue.empty())
            {
                if (nowQueue.front() == nullptr) {
                    myQueue.push(nullptr);
                    myQueue.push(nullptr);
                    nowQueue.pop();
                    continue;
                }
                if (nowQueue.front()->left != nullptr)
                {
                    myQueue.push(nowQueue.front()->left);
                }
                else
                {
                    myQueue.push(nullptr);
                }

                if (nowQueue.front()->right != nullptr)
                {
                    myQueue.push(nowQueue.front()->right);
                }
                else
                {
                    myQueue.push(nullptr);
                }

                nowQueue.pop();

            }
            std::cout << "\n";
        }

    }

};

