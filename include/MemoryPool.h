#pragma once
#include "ThreadCache.h"

namespace My_MemoryPool
{

class MemoryPool
{
public:
    static void* allocate(size_t size)
    {
        return ThreadCache::GetInstance().allocate(size);
    }

    static void deallocate(void* ptr, size_t size)
    {
        ThreadCache::GetInstance().deallocate(ptr, size);
    }
};

}