#pragma once
#include <cstddef>
#include <atomic>
#include <array>

namespace My_MemoryPool
{

constexpr size_t ALIGNMENT = 8;
constexpr size_t MAX_BYTES = 256 * 1024; //256KB
constexpr size_t FREE_LIST_SIZE = MAX_BYTES / ALIGNMENT;

struct BlockHeader {
    size_t size;  //内存块大小
    bool   used;  //是否使用
    BlockHeader* next; //指向下一个内存块
};

class SizeClass //大小类管理
{
public:
    static size_t RoundUp(size_t bytes)
    {
        return (bytes + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1);
    }

    static size_t GetIndex(size_t bytes)
    {
        bytes = std::max(bytes, ALIGNMENT);
        return (bytes + (ALIGNMENT - 1)) / ALIGNMENT - 1;
    }
};

}
