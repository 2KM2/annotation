#pragma once
#include "base/Task.h"
#include <unistd.h>
#include <iostream>
#include <functional>
using namespace std;
//等价于 typedef void (*pdu_handler_t)(CImPdu* pPdu, uint32_t conn_uuid);
using pdu_handler_t=std::function<void(void *, uint32_t )>;
class CProxyTask:public CTask{

public:
    CProxyTask(uint32_t conn_uuid, pdu_handler_t pdu_handler, void* pPdu);
	virtual ~CProxyTask();
    
	virtual void run();

private:
    uint32_t m_conn_uuid;
    pdu_handler_t m_pdu_handler;
    void *m_pPdu;
};