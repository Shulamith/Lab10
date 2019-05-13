#include "funcs.h"
#include "time.h"
#include <iostream>
#include <string>

// Sample function

std::string greet(std::string name){
  return "Hello "+name+"!";
}
void printTime(Time time) {
    std::cout << time.h << ":" << time.m;
}
int minutesSinceMidnight(Time time){
  int minutes;
  minutes = (time.h * 60) + time.m;
  return minutes;
}
int minutesUntil(Time earlier, Time later){
  int min_earlier, min_later,ans;
  min_earlier = minutesSinceMidnight(earlier);
  min_later = minutesSinceMidnight(later);
  ans = min_later - min_earlier;
  return ans;
}
Time addMinutes(Time time0, int min){
  Time result;
  int temp_min;
  int temp_hrs;
  temp_min = time0.m + min;
  // if (min>=60) {
    temp_hrs = temp_min / 60 + time0.h;
    temp_min = temp_min % 60;

  // }
  result.h = temp_hrs;
  result.m = temp_min;
  return result;
}
void printMovie(Movie mv){
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}
void printTimeSlot(TimeSlot ts){
  //std::string ans = "";
  std::string title, genre, duration, startTimeH, startTimeM, endTimeH, endTimeM;
  Time endtime = addMinutes(ts.startTime, ts.movie.duration);
  std::cout << ts.movie.title << " " << ts.movie.genre << " (" << ts.movie.duration << "min)";
  std::cout << " [starts at " << ts.startTime.h << ":" << ts.startTime.m << ", ends by " << endtime.h;
  std::cout << ":" << endtime.m << "]" <<std::endl;
  // title = ts.movie.title;
  // genre = ts.movie.genre;
  // duration = ts.movie.duration;
  // startTimeH = std::to_string(ts.startTime.h);
  // startTimeM = ts.startTime.m;
  // endTimeH = endtime.h;
  // endTimeM = endtime.m;
  // ans = ans + title + " " + genre + " (" + duration + "min)";
  // ans = ans + " [starts at " + startTimeH + ":" + startTimeM + ", ends by " + endTimeH + ":" + endTimeM; + "]\n";
  // return ans;
}
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
  TimeSlot next;
  next.movie = nextMovie;
  next.startTime = addMinutes(ts.startTime, ts.movie.duration);
  printTimeSlot(next);
  return next;
}
bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
  int min_difference;
  bool overlap;
  Time endtime1 = addMinutes(ts1.startTime, ts1.movie.duration);
  Time endtime2 = addMinutes(ts2.startTime, ts2.movie.duration);
  min_difference = minutesUntil(ts1.startTime, ts2.startTime);
  if (min_difference>=0) {
    if (minutesUntil(endtime1,ts2.startTime)<0) {
      return true;
    }
    else {
      return false;
    }
  }
  else{
    if (minutesUntil(endtime2,ts1.startTime)<0) {
      return true;
    }
    else{
      return false;
    }
  }
}
