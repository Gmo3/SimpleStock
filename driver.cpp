#include <iostream>
#include "strategy.h"

int main(){
    Stock apple(345.02, "APL");
    apple.simulate();
    std::vector<Stock> stocks;
    stocks.push_back(apple);
    Strategy test1(stocks);

    std::cout << test1.buyFourPattern("APL");
    return 0;
}