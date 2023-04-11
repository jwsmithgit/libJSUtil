#pragma once

#include <vector>
#include <functional>

template <typename R, typename... Args>
class Action
{
public:
    typedef std::function<R(Args...)> Function;

    void add(Function function);
    void remove(Function function);
    void clear();
    void set(Function function);
    R invoke(Args... args);

private:
    std::vector<Function> m_functions;
};