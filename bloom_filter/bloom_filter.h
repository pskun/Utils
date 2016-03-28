#ifndef _BLOOM_FILTER_H
#define _BLOOM_FILTER_H

namespace utils {

class BloomFilter {
public:
    BloomFilter() = default;
    virtual ~BloomFilter() = default;

    virtual void init();

    virtual void insert(const char* const data) = 0;

    virtual size_t find(const char* const data) = 0;

    virtual void clear() = 0;
};

}

#endif