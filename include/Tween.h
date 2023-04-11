#pragma once

#include <functional>
#include "Action.h"

enum class TweenState {
    STOPPED,
    RUNNING,
    PAUSED
};

class Tween
{
public:
    void start(float startValue, float endValue, float duration, std::function<void(Tween*)> onComplete = nullptr);
    void pause();
    void resume();
    void stop();
    void update(float deltaTime);
    float getValue() const;
    TweenState getState() const;

private:
    float m_startValue;
    float m_endValue;
    float m_duration;
    float m_elapsedTime;
    TweenState m_state;
    Action<void, Tween*> m_onComplete;
};