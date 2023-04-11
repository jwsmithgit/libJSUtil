#include "Tween.h"
#include "utils.h"

Tween::Tween(float startValue, float endValue, float duration, std::function<void(Tween*)> onComplete) : m_startValue(startValue),
                                                                                                   m_endValue(endValue),
                                                                                                   m_duration(duration),
                                                                                                   m_elapsedTime(0.0f)
{
    if (onComplete)
    {
        m_onComplete.set(onComplete);
    }
}

void Tween::update(float deltaTime)
{
    m_elapsedTime += deltaTime;

    if (m_elapsedTime >= m_duration)
    {
        m_elapsedTime = m_duration;
        m_onComplete.invoke(this);
    }
}

float Tween::getValue() const
{
    float t = m_elapsedTime / m_duration;
    return lerp(m_startValue, m_endValue, t);
}