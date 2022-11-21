#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "ThreadPool.h"
using namespace std;


int maincc()
{
    std::mutex mtx;
    ThreadPool pool(4);
    std::vector<std::future<int>> results;
    results.reserve(8);
    for(int i=0; i < 8; ++i)
    {
        results.emplace_back(
                pool.enqueue([i, &mtx]{

                    std::lock_guard<std::mutex> lg(mtx);
                    std::cout << "hello " << i << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    std::cout << " world " << i << std::endl;
                    return i * i;
                })
                );
    }

//    for(auto && result : results) {
//        std::cout << "result:" << result.get() << std::endl;
//    }
    std::cout << std::endl;

    return 0;
}

int main(void) {

    std::mutex mtx;

    try
    {
        ThreadPool tp(1);
        std::vector<std::future<int>> v;
        std::vector<std::future<void>> v1;
        for (int i = 0; i <= 10; ++i)
        {
            auto ans = tp.enqueue([&mtx](int answer) {
                std::lock_guard<std::mutex> lg(mtx);
                std::cout << "answer:" << answer << std::endl;
                return answer; }, i);
            v.push_back(std::move(ans));
        }
        for (int i = 0; i <= 5; ++i)
        {
            auto ans = tp.enqueue([&mtx](const std::string& str1, const std::string& str2)
                              {
                                  std::lock_guard<std::mutex> lg(mtx);
                                  std::cout << (str1 + str2) << std::endl;
                                  return;
                              }, "hello ", "world");
            v1.push_back(std::move(ans));
        }
        for (size_t i = 0; i < v.size(); ++i)
        {
            cout << v[i].get() << endl;
        }
        for(size_t i = 0; i < v1.size(); ++i)
        {
            v1[i].get();
        }
    }
    catch(const std::exception& e)
    {
        std:cout << e.what() << std::endl;
    }


    return 0;
}
