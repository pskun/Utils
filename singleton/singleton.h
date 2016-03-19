#ifndef _SINGLETON_H
#define _SINGLETON_H

template<typename T>
class Singleton {
private:
    class object_creator {
        object_creator() { Singleton<T>::instance(); }
        inline void do_nothing() const {}
    };

    static object_creator creator;
public:
    typedef T object;
    static object& instance() {
        static object obj;
        creator.do_nothing();
        return obj;
    }
};

template <typename T> typename Singleton<T>::object_creator Singleton<T>::creator;

#endif