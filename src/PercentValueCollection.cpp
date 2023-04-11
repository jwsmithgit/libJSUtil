#include "PercentValueCollection.h"
#include <stdexcept>

template <typename T>
PercentValueCollection<T>::PercentValueCollection() : m_value(0) {}

template <typename T>
void PercentValueCollection<T>::addPercentValue(double minPercent, double maxPercent, T minValue, T maxValue)
{
    m_percentValues[{minPercent, maxPercent}] = PercentValue<T>(minValue, maxValue);
}

template <typename T>
void PercentValueCollection<T>::setPercent(double percent)
{
    PercentValue<T> *percentValue = findPercentValue(percent);
    if (percentValue == nullptr)
    {
        throw std::out_of_range("Percentage value not found");
    }
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
    for (auto &[range, percentValue] : m_percentValues)
    {
        if (percentValue.isPercentInRange(percent))
        {
            return &percentValue;
        }
    }
    return nullptr;
}