#pragma once

#include <functional>
#include "Action.h"

class Tween
{
public:
    Tween(float startValue, float endValue, float duration, std::function<void(Tween*)> onComplete = nullptr);
    void update(float deltaTime);
    float getValue() const;

private:
    float m_startValue;
    float m_endValue;
    float m_duration;
    float m_elapsedTime;
    Action<void, Tween*> m_onComplete;
};