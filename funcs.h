#pragma once

#include <iostream>
#include "time.h"

// sample signature
std::string greet(std::string name);
void printTime(Time time);
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
void printMovie(Movie mv);
void printTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2);



// Write your function signatures / prototypes here
