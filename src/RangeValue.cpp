#include "RangeValue.h"

template <typename T>
RangeValue<T>::RangeValue(T min, T max, T val)
{
    minValue = min;
    maxValue = max;
    setValue(val);
}

template <typename T>
T RangeValue<T>::getMinValue() const
{
    return minValue;
}

template <typename T>
T RangeValue<T>::getMaxValue() const
{
    return maxValue;
}

template <typename T>
T RangeValue<T>::getValue() const
{
    return value;
}

template <typename T>
void RangeValue<T>::setValue(T val)
{
    if (val < minValue)
    {
        value = minValue;
    }
    else if (val > maxValue)
    {
        value = maxValue;
    }
    else
    {
        value = val;
    }
}

template class RangeValue<int>;
template class RangeValue<float>;
template class RangeValue<double>;