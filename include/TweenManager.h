#pragma once

#include <vector>
#include "Tween.h"

class TweenManager
{
public:
    void update(float deltaTime);
    void add(Tween* tween);
    void remove(Tween* tween);
    void clear();

private:
    std::vector<Tween *> m_tweens;
    std::vector<Tween *> m_tweensToRemove;
};