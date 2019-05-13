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



// Write your function signatures / prototypes here
