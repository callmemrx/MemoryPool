#pragma once
#include "Common.h"

namespace My_MemoryPool
{

class ThreadCache
{
public:
    static ThreadCache& GetInstance()
    {
        static thread_local ThreadCache instance;
        return instance;
    }

    void* allocate(size_t size);
    void deallocate(void* ptr, size_t size);
private:
    ThreadCache()
    {
        //初始化自由链表和大小统计
        freeList_.fill(nullptr);
        freeListSize_.fill(0);
    }

    //从中心缓存获取内存
    void* FetchFromCentralCache(size_t index);
    //归还内存到中心缓存
    void ReturnToCentralCache(void* start, size_t size);

    bool ShouldReturnToCentralCache(size_t index);
private:
    //每个线程的自由链表数组
    std::array<void*, FREE_LIST_SIZE> freeList_;
    std::array<size_t, FREE_LIST_SIZE> freeListSize_;
};

}
