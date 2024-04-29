#ifndef ResaleProduct_H
#define ResaleProduct_H

#include "Product.h"

class ResaleProduct : public Product{
private:
    int profit_margin_;

public: 
    ResaleProduct(int id, float price, int p_marg) : Product(id,price), profit_margin_(p_marg) {}
    int get_profit_margin() const {return profit_margin_;}
    void set_profit_margin(int margin) {profit_margin_ = margin;}
    float get_sell_price() const {
        float i = float(price_ * profit_margin_) / 100.0f; 
        return i + price_;
    }
};
#endif