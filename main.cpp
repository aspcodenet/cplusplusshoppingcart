#include <iostream>
#include <sstream>      // std::stringstream
#include "ShoppingCart.h"

//#define MILES_TO_KM(m,yhui) (m * 1.609)*

long double operator"" _kg(long double x)
{
    return x * 1000;
}

//             12.0_kg
// long double x
//  long weightInGrams123 = 12.0_kg; // 12000
//  long weightInGrams1234 = 100.0_g; // 100
// // Player p = p2;
// Gram
long double operator"" _g(long double x) { return x; }

double inline convertMilesToKm(double mi){
    return mi * 1.609;
}


class Font{
public:
    typedef enum {
     Measurement_Pt,
     Measurement_Percent,   
     Measurement_Px,
     Measurement_Em,
    }Measurement;

private:
    Measurement measurement;        
    int value;
public:
    constexpr Font(Measurement measurement, int value):measurement(measurement),value(value){

    }    
};

Font operator"" _em(unsigned long long x) { 
    return Font(Font::Measurement_Em,x); 
}



Font operator"" _pt(unsigned long long x) { 
    return Font(Font::Measurement_Pt,x); }


constexpr Font operator"" _percent(unsigned long long x) { 
    if(x > 1000){
        throw std::invalid_argument("Fel");
    }
    return Font(Font::Measurement_Percent,x); 
    }    



void udlDemo(){
    Font  f1 = 3_em;
    Font  f4 = Font(Font::Measurement_Em,3);
    Font  f2 = 12_pt;
    constexpr Font  f3 = 1100_percent;

    //Font font(Font::Measurement_Em, 3);
//    Font font2(Font::Measurement_Percent, 3);


    // RUNTIME VS COMPILETIME
    // int test;
    //  std::cin >> test;
    //  long rrr = test; // RUNTIME
    // long x = 12345;
    // float f = 13.12;
    //float f = 12.123;
    
    // // ok seems like they are using miles
    // float kilometers = 12 * 1.609; //Jag sprang 12 miles dvs 19.308 km

//    float kilom = MILES_TO_KM(12);
    //float kilom = 12 * 1.609;
    //float kilom2 =  12 * 1.609;
    // convertMilesToKm(12);

    std::string name =  "Stefan";
    
    
    
    //long weightInGrams = 2 * 1000; //What is this?? kg, grams etc etc?
    // long year = -1223; //

    // long weightInGrams = 2000;
    // weightInGrams += 5000;








    long weightInGrams2 = 2.0_kg + 500.0_g;

    std::cout << weightInGrams2 << std::endl;

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