#ifndef _UTILS_HUFFMAN_TREE_H
#define _UTILS_HUFFMAN_TREE_H

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

namespace utils {

typedef struct hftree {
    double weight;
    const void* data;
    struct hftree* left;
    struct hftree* right;

    hftree(const double w): weight(w), data(NULL), left(NULL), right(NULL) {};
    hftree(const void* d): data(d), weight(0.0), left(NULL), right(NULL) {};
    hftree(const void* d, const double w): data(d), weight(w), left(NULL), right(NULL) {};

    ~hftree() {};

} hftree_t;

struct hftree_cmp {
    bool operator() (const hftree_t* a, const hftree_t* b) {
        return a->weight > b->weight;
    }
};

class HuffmanTree {
private:
    hftree_t* root;
    unordered_map<const void*, string> encodings;

    void inorderTraversal();

public:
    string getEncoding(const void* data);

    void build(vector<double> weights, vector<void*> datas);

    void clear();

    HuffmanTree(): root(NULL) {};
    ~HuffmanTree() {clear();};

};

}

#endif