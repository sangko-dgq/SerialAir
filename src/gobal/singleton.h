/*** 
 * @Author: sangko-dgq 2201225826@qq.com
 * @Date: 2022-06-18 15:16:21
 * @LastEditors: sangko-dgq 2201225826@qq.com
 * @LastEditTime: 2022-06-21 21:27:59
 * @FilePath: \SerialAir_Sangko\src\gobal\singleton.h
 * @Description: 
 * @
 * @Copyright (c) 2022 by sangko-dgq 2201225826@qq.com, All Rights Reserved. 
 */

#pragma once

#include <QMutex>
#include <QScopedPointer>

template <typename T>
class Singleton
{
public:
    static T &getInstance();
    Singleton(const Singleton &other) = default;
    Singleton<T> &operator=(const Singleton &other) = default;

private:
    static QMutex mutex;
    static QScopedPointer<T> instance;
};

template <typename T> QMutex Singleton<T>::mutex;
template <typename T> QScopedPointer<T> Singleton<T>::instance;

template<typename T>
T &Singleton<T>::getInstance()
{
    if (instance.isNull()) {
        mutex.lock();
        if (instance.isNull()) {
            instance.reset(new T());
        }
        mutex.unlock();
    }
    return *instance.data();
}

#define SINGLETON(Class) \
    private: \
    Class(); \
    ~Class(); \
    Class(const Class &other); \
    Class &operator =(const Class &other); \
    friend class Singleton<Class>; \
    friend struct QScopedPointerDeleter<Class>;



