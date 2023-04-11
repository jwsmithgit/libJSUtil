#include "Tween.h"
#include "util.h"

void Tween::start(float startValue, float endValue, float duration, std::function<void(Tween *)> onComplete)
{
    m_startValue = startValue;
    m_endValue = endValue;
    m_duration = duration;
    m_elapsedTime = 0.0f;
    m_state = TweenState::RUNNING;

    m_onComplete.clear();
    if (onComplete)
    {
        m_onComplete.set(onComplete);
    }
}

void Tween::pause()
{
    if (m_state == TweenState::RUNNING)
    {
        m_state = TweenState::PAUSED;
    }
}

void Tween::resume()
{
    if (m_state == TweenState::PAUSED)
    {
        m_state = TweenState::RUNNING;
    }
}

void Tween::stop()
{
    m_state = TweenState::STOPPED;
}

void Tween::update(float deltaTime)
{
    if (m_state != TweenState::RUNNING) {
        return;
    }

    m_elapsedTime += deltaTime;

    if (m_elapsedTime >= m_duration)
    {
        m_state = TweenState::STOPPED;
        m_elapsedTime = m_duration;
        m_onComplete.invoke(this);
    }
}

float Tween::getValue() const
{
    if (m_state != TweenState::RUNNING) {
        return m_startValue;
    }

    float t = m_elapsedTime / m_duration;
    return lerp(m_startValue, m_endValue, t);
}

TweenState Tween::getState() const
{
    return m_state;
}