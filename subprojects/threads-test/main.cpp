#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// This is basically the same code as the cppreference std::condition_variable example
// here: https://en.cppreference.com/w/cpp/thread/condition_variable

std::mutex mtx;
std::condition_variable cv;

std::string data;
bool isDataReady = false;
bool isDataFinishedProcessing = false;

void doThreadWork() {
  std::unique_lock theLock(mtx);
  cv.wait(theLock, []{return isDataReady;});

  std::cout << "Worker thread is processing data: '" << data << "'\n";
  const std::string half = data.substr(0, data.length() / 2);
  data = half + half;

  isDataFinishedProcessing = true;
  theLock.unlock();
  cv.notify_one();
}

int main() {
  std::thread workerThread(doThreadWork);
  data = "My awesome string";

  {
    std::lock_guard theLock(mtx);
    isDataReady = true;
    std::cout << "Data marked as ready in the main thread\n";
  }
  cv.notify_one();

  {
    std::unique_lock theLock(mtx);
    cv.wait(theLock, []{return isDataFinishedProcessing;});
  }

  std::cout << "Now back to main thread. Processed data: '" << data << "'\n";
  workerThread.join();

	return EXIT_SUCCESS;
}
