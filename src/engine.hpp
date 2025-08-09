#pragma once

#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

#include "core/position.hpp"

constexpr unsigned int SEARCH_DEPTH = 2;

extern std::thread       search_thread;
extern std::atomic<bool> stop_flag;
// extern std::mutex              search_mutex;
// extern std::condition_variable cv;

void start_thinking(const Position& p);
void stop_thinking();
