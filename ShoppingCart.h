#ifndef __SHOPPING_CART_H
#define __SHOPPING_CART_H
#include <vector>
#include <string>
#include <iostream>
#include <ostream>

// HEADER - way for me (as a coder) to see the "INTERFACE"

class ShoppingCartItem{
public:
	int getPrice() { return count * price;}
    void add(int count);
    void remove(int count);
    ShoppingCartItem(std::string productName, int price, int count);
    std::string getName(){return productName;}
    friend std::ostream &operator<<(std::ostream &stream,const ShoppingCartItem&item);
private:    
	int count;
	int price;
	std::string productName; // best practice
};


class ShoppingCart{
public:
	int getTotalPrice();
    void add(std::string productName, int count);
    void remove(std::string productName, int count);
    friend std::ostream &operator<<(std::ostream &stream,const ShoppingCart&cart);
private:    
    int getProductPrice(std::string productName){return 100 - productName.length();}
    std::vector<ShoppingCartItem> items;
};





#endif // __SHOPPING_CART_H