#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    int count = 0;
    auto start = chrono::steady_clock::now();

    while (count < 100)
    {
        auto loop_start = chrono::steady_clock::now();

        // 카운트 증가 및 출력
        count++;
        cout << "카운트 : " << count;

        // 현재 시간 측정
        auto now = chrono::steady_clock::now();

        // 경과 시간 계산
        chrono::duration<double, milli> elapsed = now - loop_start;

        // 밀리초 단위로 경과 시간 출력
        cout << " 밀리초: " << elapsed.count() << "ms" << endl;

        // 다음 카운트 출력까지 남은 시간 계산
        auto next_target = start + chrono::seconds(count);
        auto sleep_duration = next_target - chrono::steady_clock::now();

        // 남은 시간 동안 대기
        this_thread::sleep_for(sleep_duration);
    }

    return 0;
}