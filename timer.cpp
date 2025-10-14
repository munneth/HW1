#include "timer.h"
#include <iostream>
#include <iomanip>

void Timer::Reset() {
  start = std::chrono::high_resolution_clock::now();
}

double Timer::getMicroseconds() {
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration<double, std::micro>(end - start).count();
  return duration;
}

void Timer::printElapsedTime() {
  double time = getMicroseconds();
  std::cout << "CPU time: " << std::fixed << std::setprecision(3) << time << " microseconds" << std::endl;
}
