#include "cycle_buffer.h"


CycleBuffer::CycleBuffer(int size)
:m_read_index(0)
,m_write_index(0)
,m_max_size(size)
,m_expand_par(2)
,flags(-1)
{
    m_pBuffer= new char[m_max_size];
}

CycleBuffer::~CycleBuffer()
{
  	if (nullptr != m_pBuffer)
	{
		delete[] m_pBuffer;
		m_pBuffer = nullptr;
	}
}


uint64_t CycleBuffer::write_to_buffer(const char* Buffer, uint64_t write_size)
{
	uint64_t used_size=m_write_index-m_read_index; //used_size表示已经存储的字节数
	uint64_t remain_size=m_max_size-used_size; //remain_size表示剩余空间
	uint64_t cur_size = m_max_size-m_write_index;//cur_size表示当前能够存储的空间

	if(write_size>remain_size)
	{
		flags=0;
		adjust_buffer();
		expand_buffer(write_size);
		flags=-1;	
	}
	else if(write_size>cur_size)
	{
		flags=0;
		adjust_buffer();
		flags=-1;
	}
	memcpy(&m_pBuffer[m_write_index], Buffer, write_size);				//存储数据
	return write_size;
}
uint64_t CycleBuffer::read_from_buffer(char* Buffer, uint64_t read_size)
{
	uint64_t read_max= m_write_index-m_read_index; //read_max存储的字节数
	if(read_size==0 ||read_max==0)
	{
		return 0;
	}
	if(read_size==-1) //全部读取
	{
		memcpy(Buffer,&m_pBuffer[m_read_index],read_max);
		//m_read_index 读指针要加
	}
	else if(read_size>0){ //读取指定字节
		if(read_size >read_max){
			read_size= read_max;
		}
		memcpy(Buffer,&m_pBuffer[m_read_index],read_size);
		//m_read_index 读指针要加
	}
	return read_size;
}
void CycleBuffer::write_commit(uint64_t write_size)
{
    m_write_index +=write_size;
}
void CycleBuffer::read_commit(uint64_t read_size)
{
    m_read_index += read_size;
}

uint64_t CycleBuffer::readable_bytes() const
{
	if(flags!=-1)
	{
		return 0;
	}
	return m_write_index-m_read_index;
}


void CycleBuffer::adjust_buffer()
{
	if(m_read_index==0)
	{
		return ;
	}
	int used_size=m_write_index-m_read_index;
	if(used_size==0)
	{
		m_write_index=0;
		m_read_index=0;
	}
	else
	{
		//cout << "调整前read_index write_index" << m_read_index << " " << m_write_index << endl;

		memcpy(m_pBuffer,&m_pBuffer[m_read_index],used_size);//将数据拷贝至头部
		m_write_index -=m_read_index;
		m_read_index=0;
	}
	
	//cout << "调整后read_index write_index" << m_read_index << " " << m_write_index << endl;
}


void CycleBuffer::expand_buffer(uint64_t need_size)
{
	uint64_t used_size = m_write_index - m_read_index;	//used_size表示已经存储的字节数
	uint64_t remain_size = m_max_size - used_size;		//remain_size表示剩余空间
	uint64_t expand_size = m_max_size;	
	while (remain_size < need_size) {					//剩余空间不够时扩展，用while表示直到扩展至够用
		expand_size *= m_expand_par;
		remain_size = expand_size - used_size;
	//	cout << "扩展长度中... 总剩余 总长度 " << remain_size << "  " << expand_size << endl;
	}

	char *snew=new char[expand_size]();
	memcpy(snew,m_pBuffer,m_max_size);
	free(m_pBuffer);
	m_pBuffer=snew;
	m_max_size=expand_size;
}