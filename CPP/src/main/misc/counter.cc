#include "counter.h"

#include <stdio.h>

// Returns the current counter value, and increments it.
int Counter::Increment() { return counter_++; }

// Returns the current counter value, and decrements it.
// counter can not be less than 0, return 0 in this case
int Counter::Decrement() {
  if (counter_ == 0) {
    return counter_;
  } else {
    return counter_--;
  }
}

// Prints the current counter value to STDOUT.
void Counter::Print() const { printf("%d", counter_); }