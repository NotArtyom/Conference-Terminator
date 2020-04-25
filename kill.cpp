#include "Kill.h"

void Kill::killingFunc() {
#ifdef __linux__
  system("killall -9 teams");
#elif _WIN32
  system("taskkill /IM Teams.exe /F");
#else
  system("killall teams");
}
#endif
}

void Kill::timer_start(std::function<void(void)> func, int pause) {
  std::thread([func, pause]() {
    auto x = std::chrono::steady_clock::now() +
             1000 * 60 * std::chrono::milliseconds(pause);
    std::this_thread::sleep_until(x);
    func();
  }).detach();
}

bool Kill::check(int time) { return (time >= 0 && time <= 5000); }

void Kill::kill(int time) {
  std::thread([time]() {
    if (check(time)) {
      timer_start(killingFunc, time);
    }
  }).join();
}
