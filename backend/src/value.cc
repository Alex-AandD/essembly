#include "backend/include/value.hh"

namespace Essembly {
/* here all the values */
Value::Value() { }
Value::~Value() { }

IntValue::IntValue(int val): value(val) { }
IntValue::~IntValue() { }

}