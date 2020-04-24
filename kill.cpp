#include "kill.h"

void Kill::killingFunc() {
  // std::cout << "Love you, sweetie" << std::endl;
  system("taskkill /IM Teams.exe /F");
}

void Kill::timer_start(std::function<void(void)> func, int pause) {
  std::thread([func, pause]() {
    auto x = std::chrono::steady_clock::now() +
             1000 * 60 * std::chrono::milliseconds(pause);
    std::this_thread::sleep_until(x);
    func();
  }).join();
}

bool Kill::check(int time) { return (time >= 0 && time <= 5000); }

void Kill::kill(int time) {
  std::thread([time]() {
    if (check(time)) {
      timer_start(killingFunc, time);
    }
  }).join();
}
