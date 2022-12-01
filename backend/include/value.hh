#pragma once
#include <string>

class Value {
public:
    Value();
    virtual ~Value() = 0;
};

class IntValue: public Value {
public:
    int value;
public:
    IntValue(int _value);
    ~IntValue() override;
};