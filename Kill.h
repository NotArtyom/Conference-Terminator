#ifndef KILL_H
#define KILL_H

#include <chrono>
#include <functional>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <thread>

class Kill
{
public:
    static void killingFunc();
    static void timer_start(std::function<void(void)> func, int pause);
    static bool check(int time);
    static void kill(int time);
};

#endif // KILL_H
