#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "funcs.h"
#include "doctest.h"

// Write test cases here
TEST_CASE("Task A"){
  Time t1 = {4,30};
  Time t2 = {22,59};
  Time t3 = {0,0};
  CHECK(minutesSinceMidnight(t1) == 270);
  CHECK(minutesSinceMidnight(t2) == 1379);
  CHECK(minutesSinceMidnight(t3) == 0);
  CHECK(minutesUntil({10,30},{13,40})==190);
  CHECK(minutesUntil({13,40},{10,30})==-190);
}

TEST_CASE("Task B"){
  Time result = addMinutes({8,10},75);
  CHECK(result.h == 9);
  CHECK(result.m == 25);
}

// etc.
