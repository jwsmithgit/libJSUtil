#pragma once

template<typename T>
class RangeValue
{
public:
    RangeValue(T min, T max, T val);
    T getMinValue() const;
    T getMaxValue() const;
    T getValue() const;
    void setValue(T val);

private:
    T minValue;
    T maxValue;
    T value;
};
