#include "PercentValueCollection.h"

template <typename T>
PercentValueCollection<T>::PercentValueCollection() : m_value(0) {}

template <typename T>
void PercentValueCollection<T>::addPercentValue(double minPercent, double maxPercent, T minValue, T maxValue)
{
    m_percentValues[{minPercent, maxPercent}] = new PercentValue<T>(minValue, maxValue, minValue);
}

template <typename T>
void PercentValueCollection<T>::setPercent(double percent)
{
    PercentValue<T> *percentValue = findPercentValue(percent);
    percentValue->setPercent(percent);
    m_value = percentValue->getValue();
}

template <typename T>
T PercentValueCollection<T>::getValue() const
{
    return m_value;
}

template <typename T>
PercentValue<T> *PercentValueCollection<T>::findPercentValue(double percent)
{
    for (auto& it : m_percentValues) {
        auto key = it.first;
        auto value = it.second;

        if (key.first <= percent && percent <= key.second) {
            return value;
        }
    }

    return nullptr;
}

template class PercentValueCollection<int>;
template class PercentValueCollection<float>;
template class PercentValueCollection<double>;