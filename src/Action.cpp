#include "Action.h"
#include <algorithm>

template<typename R, typename... Args>
void Action<R, Args...>::add(Function function) {
    m_functions.push_back(function);
}

template<typename R, typename... Args>
void Action<R, Args...>::remove(Function function) {
    auto it = std::find(m_functions.begin(), m_functions.end(), function);
    if (it != m_functions.end()) {
        m_functions.erase(it);
    }
}

template<typename R, typename... Args>
void Action<R, Args...>::clear() {
    m_functions.clear();
}

template<typename R, typename... Args>
void Action<R, Args...>::set(Function function) {
    m_functions.clear(); // remove any existing functions
    m_functions.push_back(function); // add the new function
}

template<typename R, typename... Args>
R Action<R, Args...>::invoke(Args... args) {
    R result;
    for (auto& function : m_functions) {
        result = function(args...);
    }
    return result;
}