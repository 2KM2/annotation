#include "ProxyTask.h"


CProxyTask::CProxyTask(uint32_t conn_uuid, pdu_handler_t pdu_handler, void* pPdu)
:m_conn_uuid(conn_uuid)
,m_pdu_handler(pdu_handler)
,m_pPdu(pPdu)
{

}


CProxyTask::~CProxyTask()
{
    if(m_pPdu)
    {
        delete m_pPdu;
    }
}


void CProxyTask::run()
{
    if(!m_pPdu){
        
    }else {
        if(m_pdu_handler){
            m_pdu_handler(m_pPdu,m_conn_uuid);
        }
    }
}