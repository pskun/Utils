#ifndef _BASIC_BLOOM_FILTER_H
#define _BASIC_BLOOM_FILTER_H

#include "bloom_filter.h"

namespace bloomfilter {

class BasicBloomFilter : public BloomFilter {
public:
    BasicBloomFilter() = default;
    BasicBloomFilter(const BasicBloomFilter &filter) = default;

    template <typename T>
    virtual insert(const T &t);

    template <typename T>
    virtual size_t find(const T &t);

    virtual void clear();
};

}

#endif