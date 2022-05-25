#pragma once
#include <string.h>
#include <stdint.h>
#include <malloc.h>
#include <unistd.h>
#include <iostream>
using namespace std;

#define MAX_PREALLOC 1024
class CycleBuffer
{

public:
    CycleBuffer(int size=1024*1024);
    ~CycleBuffer();
public:    
	uint64_t write_to_buffer(const char* Buffer, uint64_t write_size); // 写入操作，返回成功写入的字节数
	uint64_t read_from_buffer(char* Buffer, uint64_t read_size);  // 读取操作，返回实际读取的字节数
	void write_commit(uint64_t write_size);   // 写入成功后更新m_nIn值
	void read_commit(uint64_t read_size);    // 读取成功后更新m_nOunt值
	uint64_t readable_bytes() const;
    uint64_t peek_read() const { return m_read_index;}							//指向准备读的位置（调试用）
	uint64_t peek_write()const { return m_write_index;}						//指向准备写的位置（调试用）
private:
    void adjust_buffer();
    void expand_buffer(uint64_t need_size);		//扩展缓冲区长度
private:
   char * m_pBuffer;//数据
   uint64_t m_read_index;//读指针的位置
   uint64_t m_write_index;//写指针的位置
   uint64_t m_max_size;//缓冲区的长度
   uint64_t m_expand_par;//扩展因子
   int flags;// -1 没有扩容  0 扩容
};