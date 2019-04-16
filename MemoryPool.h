#include <stdio.h>
#include <stdlib.h>
#include <list>
#include "THreadLock.h"

#define MEX_MEMORY_SIZE 12
#define MAGIC_CODE 0xffffff
#define MEMORY_BUFFER_SIZE 1024
//#define UINT32 usigned int
typedef usigned int UINT32

struct MemoryBlock {
    void *m_pBlock;
    MemoryBlock() {
        m_pBlock = NULL;
    }
};

class MemoryPool
{
public:
    static MemoryPool &instance() {
        if(NULL == m_pInstance) {
            m_pInstance = new MemoryPool();
        }
        return *m_pInstance;
    }

public:
    ~MemoryPool() {
        close();
    }
    void *GetBuff();
    bool DelBuff(void *buff);
    void DisplayBlocks();

private:
    MemoryPool() { }
    void close();
    void *SetMemoryHead(void *buff, std::list<MemoryBlock*> *pList, MemoryBlock *pBlock);
    void *SetMemoryHead(void *buff);
    bool GetMemoryBlock(void *buff, std::list<MemoryBlock*> *&pList, MemoryBlock *&pBlock);

private:
    static MemoryPool *m_pInstance;
    std::list<MemoryBlock*> m_freeBlocks;
    ThreadLock m_lock;
};

