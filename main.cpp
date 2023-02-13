#include "isomorphic.h"
#include "manual.h"
#include "generator.h"
#include "speed_test.h"
#include <bits/stdc++.h>
#include "speed_test.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main () {
    // Запуск ручных тестов
    cout << "-----manual------" << endl;
   // run_manual();
    // Запуск тестов производительности
    cout << "-----speed------" << endl;
     launch_speed_results();
}