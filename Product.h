#include <iostream>
using namespace std;
#pragma once


class Product
{
private: 
	string name;
	float price;
	string iD;
	int stock; 
	string category;
	string subcategory;
public:
	Product(string name, float price, string iD, int stock, string category, string subcategory);
	// Getters
	float getPrice();
	string getID();
	string getName();
	int getQuantity();
	string getCategory();
	string getSubCategory();

	// Setters
	void setPrice(float newPrice);
	void setID(string newID);
	void setQuantity(int newStock);

};

