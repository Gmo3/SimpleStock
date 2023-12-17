#include <vector>
#include <iostream>
#include <string>

class Stock{
private:
    float price;
    std::string ticker;
    std::vector<float> historicalPrices; //keep track of history to perform analysis
public:
    Stock() = delete; //prevent creation of stock with no values
    Stock(float price, const std::string &ticker);
    float getPrice();
    std::string getTicker();
    void updatePrice(float newPrice);
    const std::vector<float>& getPriceHistory() const;
    void printPrices();
    void simulate();
};