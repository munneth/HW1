#include "timer.h"
#include <iostream>
#include <iomanip>
// used documentation provided by w3 schools
// starts timer
void Timer::Reset() {
  start = std::chrono::high_resolution_clock::now();
}
// ends the timer which will be called at end of each test to gather microsecond time
double Timer::getMicroseconds() {
  auto end = std::chrono::high_resolution_clock::now();
  // get total duration here 
  auto duration = std::chrono::duration<double, std::micro>(end - start).count();
  return duration;
}

// printed the elapsed time in microseconds as specified by the assignment rounds to 3 decimals
void Timer::printElapsedTime() {
  double time = getMicroseconds();
  std::cout << "CPU time: " << std::fixed << std::setprecision(3) << time << " microseconds" << std::endl;
}
