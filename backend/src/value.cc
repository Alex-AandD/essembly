#include "backend/include/value.hh"

/* here all the values */
Value::Value() { }
Value::~Value() { }

IntValue::IntValue(int val): value(val) { }
IntValue::~IntValue() { }