/**
* @file task.h
* @brief 线程任务基类
* @author fU9ANg (bb.newlife@gmail.com)
* @version v1.0
* @date 2014-01-03
*/

#ifndef _TASK_H_
#define _TASK_H_

#include <glog/logging.h>

#include "Buf.h"
#include "protocol.h"

/**
 * @class task
 * @brief 线程任务基类
 */
class task
{
    public:
        task():autorelease(true){
        }
        virtual ~task(){}
        virtual int work() = 0;
        /**任务完成后是否自动释放*/
        bool autorelease;
        
    private:
};

#endif
