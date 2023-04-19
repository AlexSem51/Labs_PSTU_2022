#include "accrual.h"

using namespace std;

int main() {
    accrual r, r1, r2;
    r.Init(300, 12);
    
    r.Read();
    r.Show();
    r.Summa();

    r2.Init(3923, 23);
    
    r1.Init(5, 0);
    
    return 0;
}
