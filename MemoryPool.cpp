#include "MemoryPool.h"
#include <iostream>

MemoryPool * MemoryPool::m_pInstance = NULL;

void *MemoryPool::GetBuff() {
    //添加线程安全
    //Mutex mutex(m_lock);
    
    void *pBuff = NULL;

    if(m_freeBlocks.empty()) {

    }


}

bool MemoryPool::DelBuff(void *buff) {

}

void MemoryPool::DisplayBlocks() {

}

void MemoryPool::close() {

}

void *MemoryPool::SetMemoryHead(void *buff, std::list<MemoryBlock*> *pList, MemoryBlock *pBlock) {

}

void *MemoryPool::SetMemoryHead(void *buff) {

}

void *MemoryPool::GetMemoryHead(void *buff, std::list<MemoryBlock*> *&pList, MemoryBlock *&pBlock) {

}
