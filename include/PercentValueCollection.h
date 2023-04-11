#pragma once

#include <map>
#include <stdexcept>
#include "PercentValue.h"

template <typename T>
class PercentValueCollection {
public:
    PercentValueCollection();
    void addPercentValue(double minPercent, double maxPercent, T minValue, T maxValue);
    void setPercent(double percent);
    T getValue() const;
    PercentValue<T>* findPercentValue(double percent);

private:
    std::map<std::pair<double, double>, PercentValue<T>> m_percentValues;
    T m_value;
};