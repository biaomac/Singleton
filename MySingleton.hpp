#ifndef MYSINGLETON_HPP
#define MYSINGLETON_HPP

#include "Singleton.hpp"

void testSingleton();

class QString;
struct MySingletonPrivate; // MySingleton的数据执有对象. 使用Qt的数据隐藏模式.

/**
 * @brief The MySingleton class: 演示怎么使用Singleton宏简化单例的实现.
 * 因为单例的代码很多都是模板代码, 使用宏可以减少不必要的重复劳动。
 *
 * 需要自己提供构造函数与析构函数的实现。因为这两个函数在很多情况下是必须的, 且内容都不一样。
 * 如果构造函数与析构函数没有内容则可以使用下面的宏减少工作量:
 * DECLARE_SINGLETON_DEFAULT_CONSTRUCTOR 和 DECLARE_SINGLETON_DEFAULT_DESTRUCTOR.
 */
class MySingleton {
    DECLARE_SINGLETON(MySingleton) // [[1]]

public:
   void setNumber(int number);
   int getNumber() const;

   void setName(const QString &name);
   QString getName() const;

private:
   MySingletonPrivate *data;
};

#endif // MYSINGLETON_HPP
