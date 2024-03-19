//
// Created by zhangchuang on 2024/3/6.
//

#pragma once
#include <queue>
#include <thread>
#include <mutex>  // pthread_mutex_t
#include <condition_variable> // pthread_condition_t
// 异步写日志的日志队列


template<typename T>
class LockQueue{

public:
    // 多个worker线程都会写日志queue
    void Push(const T &data){
        // std::lock_guard 主要用于简化对互斥锁的使用，帮助避免忘记在代码中手动释放互斥锁而导致的资源泄漏或死锁等问题
        std::lock_guard<std::mutex> lock(m_mutex);
        m_queue.push(data);
        m_condvariable.notify_one();
    }

    // 一个线程都=写
    T Pop(){
        // 虚假唤醒的存在意味着在使用条件变量时，不能仅仅依赖于条件的检查来决定是否进入临界区或者继续等待。
        // 正确的做法是在条件变量的 wait() 函数调用后，使用一个循环来检查条件是否满足，如果条件不满足，则继续等待，直到条件满足为止。
        std::unique_lock<std::mutex> lock(m_mutex);
        while (m_queue.empty()){
            // 日志队列为空，线程进入wait状态
            m_condvariable.wait(lock);
        }
        T data =m_queue.front();
        m_queue.pop();
        return data;
    }

private:

    std::queue<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_condvariable;
};