#include "strategy.h"
Strategy::Strategy(const std::vector<Stock>& stocks) : stocks(stocks){

}
void Strategy::addStock(const Stock &newStock){
        stocks.push_back(newStock);
    }

float Strategy::buyFourPattern(std::string ticker){
    float profitMade = 0;
    int stockToTest = 0;
    for(; stockToTest < stocks.size(); stockToTest++){
        if(stocks[stockToTest].getTicker() == ticker){
            break;
        }
    }
    if(stockToTest == stocks.size()) return 0.0f;

    std::vector<float> temp = stocks[stockToTest].getPriceHistory();
    int count = 0;
    for(int i =1; i < temp.size(); i++){
        if(temp[i] < temp[i-1]){
            count++;
        } else{
            count = 0;
        }
        if(count > 4 && i < temp.size()-1){
            profitMade+= temp[i]-temp[i+1];
            count = 0;
            i++;
        }
    }
    return profitMade;
}