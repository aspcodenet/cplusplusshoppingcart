#include "ShoppingCart.h"


std::ostream &operator<<(std::ostream &stream,const ShoppingCartItem&item){
    stream << item.productName << " " <<  item.count << "*" << item.price << "=" << item.count * item.price   << std::endl;
    return stream;
}

std::ostream &operator<<(std::ostream &stream,const ShoppingCart&cart){
    stream << "SHOPPINGCART" << std::endl;
    for(auto &item : cart.items){
        stream << item << std::endl;
    }
    return stream;
}


// So naive
void ShoppingCart::add(std::string productName, int count) {
    //Check if product IS in the shoppingcart - items
    for(auto &item : items){
        if(item.getName() == productName)
        {
            item.add(count);
            return;
        }
    }
    items.push_back(ShoppingCartItem(productName,getProductPrice(productName), count));
}


void ShoppingCart::remove(std::string productName, int count) {
    //Check if product IS in the shoppingcart - items
    for(auto &item : items){
        if(item.getName() == productName)
        {
            item.remove(count);
            return;
        }
    }
}


void ShoppingCartItem::add(int count){
    this->count += count;
}
void ShoppingCartItem::remove(int count){
    this->count -= count;
    if(this->count < 0){
        this->count = 0;
    }
}

ShoppingCartItem::ShoppingCartItem(std::string productName, int price, int count)
:productName(productName), price(price), count(count)
{
}