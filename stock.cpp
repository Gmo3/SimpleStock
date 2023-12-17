#include "stock.h"
#include <random>
#include <chrono>
Stock::Stock(float price, const std::string &ticker) : price(price), ticker(ticker){

}

float Stock::getPrice(){
    return price;
}
std::string Stock::getTicker(){
    return ticker;
}
void Stock::updatePrice(float newPrice){
        historicalPrices.push_back(price);
        price = newPrice;
    }
 

const std::vector<float>& Stock::getPriceHistory() const{
    return historicalPrices;
}

void Stock::simulate(){
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 eng(seed);
    std::uniform_real_distribution<> distr(-5.0, 5.0); // define range for random change.
    historicalPrices.push_back(price);
    for(int i =0; i < 800; i++){
        float change = distr(eng);
        price +=change;
        if(price < 0) price = 0;
        historicalPrices.push_back(price);
    }
    printPrices();
}

void Stock::printPrices(){
    for(int i =0; i < historicalPrices.size(); i++){
        std::cout << historicalPrices[i] << std::endl;
    }
    std::cout << std::endl;
}