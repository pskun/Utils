#include "huffman_tree.h"

#include <vector>

using namespace std;
using namespace utils;

int main() {
    vector<void*> data;
    char* arr[5] = {"a", "ab", "cd", "e", "ba"};
    for(int i=0; i<5; i++) {
        data.push_back((void*) arr[i]);
    }

    vector<double> weights;
    weights.push_back(0.18);
    weights.push_back(0.1);
    weights.push_back(0.07);
    weights.push_back(0.2);
    weights.push_back(0.11);

    HuffmanTree* p = new HuffmanTree;
    p->build(weights, data);

    
}