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
TEST_CASE("TASK C"){
  //std::string res1, res2;
  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};
  Movie movie3 = {"Pirates of the Caribbean", ACTION, 155};
  Movie movie4 = {"Blazing Saddles", COMEDY, 95};
  TimeSlot morning = {movie1, {9, 15}};
  TimeSlot daytime = {movie2, {12, 15}};
  TimeSlot evening = {movie2, {16, 45}};
  TimeSlot night = {movie3,{20,00}};
  TimeSlot dawn = {movie4, {5,30}};
  printTimeSlot(morning);
  //CHECK(res1 == "Back to the Future 1 (116min) [starts at 9:15, ends by 11:11]");
}
TEST_CASE("TASK D"){
  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};
  Movie movie3 = {"Pirates of the Caribbean", ACTION, 155};
  Movie movie4 = {"Blazing Saddles", COMEDY, 95};
  TimeSlot morning = {movie1, {9, 15}};
  TimeSlot daytime = {movie2, {12, 15}};
  TimeSlot evening = {movie2, {16, 45}};
  TimeSlot night = {movie3,{20,00}};
  TimeSlot dawn = {movie4, {5,30}};
  printTimeSlot(morning);
  TimeSlot next;
  next = scheduleAfter(evening,movie2);
  CHECK(next.startTime.h == 18);
  CHECK(next.startTime.m == 59);
}
TEST_CASE("TASK E"){
  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};
  Movie movie3 = {"Pirates of the Caribbean", ACTION, 155};
  Movie movie4 = {"Blazing Saddles", COMEDY, 95};
  TimeSlot morning = {movie1, {9, 15}};
  TimeSlot daytime = {movie2, {12, 15}};
  TimeSlot evening = {movie2, {16, 45}};
  TimeSlot night = {movie3,{20,00}};
  TimeSlot dawn = {movie4, {5,30}};
  TimeSlot noon = {movie4, {12, 00}};
  CHECK(timeOverlap(daytime,noon)==true);
  CHECK(timeOverlap(noon,daytime)==true);
  CHECK(timeOverlap(dawn,evening)==false);
  CHECK(timeOverlap(daytime,morning)==false);

}

// etc.
