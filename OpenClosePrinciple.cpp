/*
  Definition:
    A class should be open for extension but close for modification
*/

// Followed Code OCP - Open Close Principle

#include<iostream>
#include<vector>
#include<memory>

using namespace std;

class Product {
    public:
        string name;
        double price;
        
        Product(string name, double price) {
            this->name = name;
            this->price = price;
        }
};

class ShoppingCart {
    private:
        vector<unique_ptr<Product>> products;
    public:
        void addProduct(unique_ptr<Product> product) {
            products.push_back(move(product));
        }
        
        vector<unique_ptr<Product>>& getProducts() {
            return products;
        }
        
        double calculateTotalPrice() {
            double total = 0;
            for(auto &p: products) {
                total += p->price;
            }
            
            return total;
        }
};

class ShoppingCartPrinter {
    private:
        ShoppingCart &cart;
    public:
        ShoppingCartPrinter(ShoppingCart &cart) : cart(cart) {}
        
        void invoicePrinter() {
            cout<<"Products invoice is : "<<endl;
            for(auto &p: cart.getProducts()) {
                cout<<"Name : "<<p->name<<", Price : "<<p->price<<endl;
            }
            cout<<"Total price : "<<cart.calculateTotalPrice()<<endl;
        }
};

class ShoppingCartStorage {
    private:
        ShoppingCart &cart;
    public:
        ShoppingCartStorage(ShoppingCart &cart) : cart(cart) {}
        
        void saveToSQLServer() {
            cout<<"Data is saved to SQL Server..."<<endl;
        }
        
        void saveToMongoDB() {
            cout<<"Data is saved to MongoDB..."<<endl;
        }
        
        void saveToCassandra() {
            cout<<"Data is saved to Cassandra..."<<endl;
        }
};

int main() {
    
    auto cart = make_unique<ShoppingCart>();
    
    cart->addProduct(make_unique<Product>("Laotop", 15000));
    cart->addProduct(make_unique<Product>("Mobile", 500));
    
    ShoppingCartPrinter printer(*cart);
    printer.invoicePrinter();
    
    ShoppingCartStorage storage(*cart);
    storage.saveToSQLServer();
    storage.saveToMongoDB();
    storage.saveToCassandra();
    
    return 0;
}
