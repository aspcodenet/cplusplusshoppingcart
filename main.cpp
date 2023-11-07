#include <iostream>
#include <sstream>      // std::stringstream
#include "ShoppingCart.h"

#define MILES_TO_KM(m) m * 1.609

void udlDemo(){
    // RUNTIME VS COMPILETIME
    long x = 12345;
    float f = 13.12;
    float kilom = MILES_TO_KM(12);
    float kilometers = 12 * 1.609; //Jag sprang 12 miles dvs 19.308 km
    long weight = 2 * 1000; //What is this?? kg, grams etc etc?
    //weight += 500;
    std::cout << weight << std::endl;

    // long weightInGrams2 = 2.0_kg + 500.0_g;
    // std::cout << weightInGrams << std::endl;

    // UDL med class - FONT och constexpr

}

int main(){
    udlDemo();
    ShoppingCart cart;
    cart.add("Coffee",3 );
    cart.add("Milk",2 );

    std::cout << cart << std::endl;


    std::stringstream strstream;
    strstream << cart ;
    std::string result =  strstream.str();
    
    return 0;
}