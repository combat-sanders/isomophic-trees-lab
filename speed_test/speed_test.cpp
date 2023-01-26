//
// Created by bazdu on 27.01.2023.
//

#include "speed_test.h"
#include "manual.h"
#include "isomorphic.h"
#include "generator.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

void launch_speed_results() {
    for (int i = 1000; i < 1000000; i += 5000) {
        vector<int> tree1 = generate_tree(i);
        vector<int> tree2 = generate_tree(i);
        auto start = high_resolution_clock::now();
        is_isomorphic(tree1, tree2);
        auto stop = high_resolution_clock::now();
        cout << i << ' ' << duration_cast<milliseconds>(stop - start).count() << endl;
    }
}