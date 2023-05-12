#include <iostream>
#include "Time.h"

using namespace std;


int main() {
    Time t(34, 92);
    Time t1(53, 23);
    t = t + t1;
    t.Show();
    return 0;
}
