#pragma once

#include "RangeValue.h"

template<typename T>
class PercentValue : public RangeValue<T>
{
public:
    PercentValue(T min, T max, T val) : RangeValue<T>(min, max, val) {}
    void setPercent(double percent);
};