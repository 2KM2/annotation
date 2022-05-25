#pragma once
/**
 * @file HandlerMap.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "ProxyTask.h"
#include <map>
#include <unistd.h>
#include <stdio.h>
#include <functional>
using namespace std;



using HandlerMap_t =map<uint32_t,pdu_handler_t>;
//
class CHandlerMap
{



private:
    static CHandlerMap *s_handler_instance;
    HandlerMap_t  m_handler_map;
};