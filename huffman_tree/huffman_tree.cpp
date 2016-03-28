#include "huffman_tree.h"
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>

using namespace std;
using namespace utils;

void HuffmanTree::build(vector<double> weights, vector<void*> data) {
    priority_queue<hftree_t*, vector<hftree_t*>, hftree_cmp> min_heap;
    size_t n = weights.size();
    if(n == 0) {
        fprintf(stderr, "WARN: weights size is 0.\n");
        return;
    }
    if(data.size() != n) {
        fprintf(stderr, "ERROR: weights size is not equal to data size.\n");
        return;
    }
    for(size_t i=0; i<n; i++) {
        hftree_t* node = new hftree(data[i], weights[i]);
        min_heap.push(node);
    }
    while(min_heap.size() > 1) {
        hftree_t* rchild = min_heap.top();
        min_heap.pop();
        hftree_t* lchild = min_heap.top();
        min_heap.pop();
        double weight = rchild->weight + lchild->weight;
        hftree_t* root = new hftree_t(weight);
        root->left = lchild;
        root->right = rchild;
        min_heap.push(root);
    }
    this->root = min_heap.top();
    min_heap.pop();

    inorderTraversal();
}

void HuffmanTree::inorderTraversal() {
    stack<hftree_t*> s;
    hftree_t* node = root;
    string encoding;
    if(node) {
        s.push(node);
        node = node->left;
    }
    while(node) {
        encoding.push_back('1');
        s.push(node);
        node = node->left;
    }
    while(!s.empty()) {
        node = s.top();
        s.pop();
        if(!node->left && !node->right) {
            encodings[node->data] = encoding;
        }
        if(!encoding.empty()) encoding.erase(encoding.end() - 1);
        if(node->right) {
            node = node->right;
            encoding.push_back('0');
            s.push(node);
            while(node) {
                encoding.push_back('1');
                s.push(node);
                node = node->left;
            }
        }
    }
}

void HuffmanTree::clear() {
    queue<hftree_t*> q;
    if(root) {
        q.push(root);
    }
    while(!q.empty()) {
        hftree_t* node = q.front();
        q.pop();
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
        node->left = node->right = NULL;
        delete node;
    }
}

string HuffmanTree::getEncoding(const void* data) {
    string ret;
    if(encodings.find() != encodings.end()) {
        ret = encodings[data];
    }
    return ret;
}