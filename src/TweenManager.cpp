#include "TweenManager.h"
#include <algorithm>

void TweenManager::update(float deltaTime)
{
    // Iterate over the tweens vector and update each tween
    for (auto tween : m_tweens)
    {
        tween->update(deltaTime);
    }

    // Iterate over the tweens to remove vector and remove each tween
    for (auto tween : m_tweensToRemove)
    {
        remove(tween);
    }
    m_tweensToRemove.clear();
}

void TweenManager::add(Tween *tween)
{
    m_tweens.push_back(tween);
}

void TweenManager::remove(Tween *tween)
{
    // If the tween is in the to-remove list, remove it
    auto it = std::find(m_tweensToRemove.begin(), m_tweensToRemove.end(), tween);
    if (it != m_tweensToRemove.end())
    {
        m_tweensToRemove.erase(it);
    }

    // Otherwise, add it to the to-remove list
    else
    {
        m_tweensToRemove.push_back(tween);
    }
}

void TweenManager::clear()
{
    m_tweens.clear();
    m_tweensToRemove.clear();
}