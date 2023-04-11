#pragma once

#include "RangeValue.h"

template<typename T>
class PercentValue : public RangeValue<T>
{
public:
    void setPercent(double percent);
};