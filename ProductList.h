#pragma once
#include "Product.h"
#include "NodoProducts.h" 
class ProductList{
    private:
        NodeProducts* head;

    public:
        ProductList();

        void addProduct(Product* product);
        NodeProducts* searchByID(string id);
        NodeProducts* searchByName(string name);
        bool modifyQuantity(string id, int newQuantity);
};