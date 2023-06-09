#include "PercentValue.h"

template <typename T>
void PercentValue<T>::setPercent(double percent)
{
    if (percent < 0)
    {
        percent = 0;
    }
    else if (percent > 100)
    {
        percent = 100;
    }
    this->setValue(this->getMinValue() + static_cast<T>((this->getMaxValue() - this->getMinValue()) * percent / 100.0));
}

template class PercentValue<int>;
template class PercentValue<float>;
template class PercentValue<double>;