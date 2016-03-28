#ifndef _UTILS_OBJECT_H
#define _UTILS_OBJECT_H

namespace utils {

class BloomObject {
private:
    void* const data = NULL;
    size_t size;

public:
    BloomObject(): data(d), size(s) {};
    void const* getData() const {
        return data;
    }
    size_t getSize() {
        return size;
    }
};

}

#endif