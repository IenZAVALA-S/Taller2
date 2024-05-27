#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

#include "Product.h"
#include "Customer.h"
#include "ProductList.h"
using namespace std;
#include <iostream>
void readInventoryTxt(ProductList* productList);
void readAndCreateCustomerQueue(ProductList* productList, queue<Customer>& customerQueue);
int checkPriority(string customerCategory, string preference);



int main()
{
    ProductList* generalProductList;
    queue<Customer> customerQueue;
    readInventoryTxt(generalProductList);
    

}

void readInventoryTxt(ProductList* productList) {
    ifstream file("Inventory.txt"); //opens the Inventory file
    if (!file.is_open())
    {
       cout<<"ERROR: UNABLE TO OPEN FILE.'\n";
        return;
    }
    // Here we define some variables to help in the reading and object construction processes
    string line;
    string* itemName = new string;
    int* itemPrice = new int;
    string* itemID = new string;
    int* itemQuantity = new int;
    string* itemCategory = new string;
    string* itemSub = new string;
    vector<string> parts;
    string* part = new string;
    while (getline(file, line)) {
    
       stringstream lineStream(line);
       //Split the parts of each line and assign them to their respective variable
       while (getline(lineStream, *part, ';')) {
           cout << *part << endl;

       parts.push_back(*part);
       }

       *itemName = string(parts[0]);
       *itemPrice = stoi(parts[1]);
       *itemID = parts[2];
       *itemQuantity = stoi(parts[3]);
       *itemCategory = parts[4];
       *itemSub = parts[5];
       

       Product baseProduct(*itemName, *itemPrice, *itemID, *itemQuantity, *itemCategory, *itemSub);
       productList->addProduct(&baseProduct);
       ;
    }
    file.close();
        
}
int checkPriority(string customerCategory, string preference) {
        if (customerCategory == "Preferencial") {
            if (preference == "Tercera Edad") {
                return 3;
            }
            else if (preference == "Discapacidad") {
                return 2;
            }
            else if (preference == "Embarazada") {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            //In case there's an error in the readings, or their preferencial level is set to NORMAL they get the default value. 
            return 0;
        }
}
void readAndCreateCustomerQueue(ProductList* productList, queue<Customer>& customerQueue) {
    
    ifstream file("Customers.txt"); //We open the file containing Customer data
    if (!file.is_open())
    {
        cout << "ERROR: UNABLE TO OPEN FILE.'\n"; //In case it's unable to open we give an error message.
        return;

    }
    string line;
    queue<Customer> auxQueue;
    while (getline(file, line)) {
        stringstream lineStream(line);
        string part;

        //Here we're gonna separate the readings of each part of the line because
        //Clients have differently sized quantities of products
        // 
        //First we read the name
        getline(lineStream, part,';');
        string name = part;

        getline(lineStream, part, ';');
        string category = part;

        //Here we assign a preference level to the clients depending if they're classified as NORMAL or PREFERENTIAL
        int preferenceLVL;
        if (category != "Normal") {
            getline(lineStream, part, ';');
            string preference = part;
            preferenceLVL = checkPriority(category, preference);
        }
        else {
            //Normal clients don't get any sort of special priorities so they're assigned a 0
            preferenceLVL = 0;
        }
        getline(lineStream, part, ';');
        int prodQTT = stoi(part);
       

        for (int i = 0; i < prodQTT; i++) {
            getline(lineStream, part, ';');
            string productID = part;
            NodeProducts* searchedProd = productList->searchByID(productID);

        }

       
        




    }

}