#pragma once

/**
 * @brief 任务的基类
 * 
 */
class CTask{
public:
    CTask() { }
    virtual void ~CTask() { }
    virtual void run()=0;
};