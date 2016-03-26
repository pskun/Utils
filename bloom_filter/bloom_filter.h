#ifndef _BLOOM_FILTER_H
#define _BLOOM_FILTER_H

namespace bloomfilter {

class BloomFilter {
public:
    BloomFilter() = default;
    virtual ~BloomFilter() = default;

    template <typename T>
    virtual insert(const T &t) = 0;

    template <typename T>
    virtual size_t find(const T &t) = 0;

    virtual void clear() = 0;
};

}

#endif