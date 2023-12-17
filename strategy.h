#include "stock.h"

class Strategy{
private:
std::vector<Stock> stocks;
public:
    Strategy(const std::vector<Stock>& stocks);
    void addStock(const Stock &newStock);
    float buyFourPattern(std::string ticker);
};