#ifndef _UTILS_BASIC_BLOOM_FILTER_H
#define _UTILS_BASIC_BLOOM_FILTER_H

#include "bloom_filter.h"

namespace utils {

class BasicBloomFilter : public BloomFilter {
public:
    BasicBloomFilter() = default;
    BasicBloomFilter(const BasicBloomFilter &filter) = default;

    virtual void init();

    virtual void insert(const char* const data);

    virtual size_t find(const char* const data);

    virtual void clear();

private:
    unsigned char * bitvector;
    size_t nElements;
    unsigned long long nbits;
};

}

#endif