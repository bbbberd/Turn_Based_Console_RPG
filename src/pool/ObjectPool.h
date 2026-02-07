#pragma once
#include <vector>

template <typename T>
class ObjectPool {
private:
    std::vector<T*> pool;

public:
    ~ObjectPool() {
        for (auto* obj : pool)
            delete obj;
    }

    T* GetObject() {
        if (pool.empty())
            return new T();
        T* obj = pool.back();
        pool.pop_back();
        return obj;
    }

    void ReturnObject(T* obj) {
        pool.push_back(obj);
    }
};
