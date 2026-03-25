//Single Responsibility Principle - SRP
//SRP violated code

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
        void addProduct(unique_ptr<Product> p) {
            products.push_back(move(p));
        }
        
        vector<unique_ptr<Product>>& getProducts() {
            return products;
        }
        
        double calculateTotal() {
            double total = 0;
            for(auto &p: products) {
                total += p->price;
            }
            
            return total;
        }
        
        void printInvoice() {
            cout<<"Shopping cart invoice : "<<endl;
            for(auto &p: products) {
                cout<<p->name<<" - $"<<p->price<<endl;
            }
            cout<<"Total : $"<<calculateTotal()<<endl;
        }
        
        void saveToDatabase() {
            cout<<"saving shopping cart to database..."<<endl;
        }
};

int main() {
    
    ShoppingCart cart;
    
    cart.addProduct(make_unique<Product>("Laptop", 1500));
    cart.addProduct(make_unique<Product>("Mouse", 50));
    
    cart.printInvoice();
    cart.saveToDatabase();
    
    return 0;
}





//Single Responsibility Principal - SRP
//SRP followed code
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
    void addProduct(unique_ptr<Product> p) {
        products.push_back(move(p)); // transfer ownership
    }

    const vector<unique_ptr<Product>>& getProducts() {
        return products;
    }

    double calculateTotal() {
        double total = 0;
        for (auto &p : products) {
            total += p->price;
        }
        return total;
    }
};

class ShoppingCartPrinter {
private:
    ShoppingCart& cart; // no ownership

public:
    ShoppingCartPrinter(ShoppingCart& cart) : cart(cart) {}

    void printInvoice() {
        cout << "Shopping Cart Invoice" << endl;
        for (auto &p : cart.getProducts()) {
            cout << p->name << " - $" << p->price << endl;
        }
        cout << "Total : $" << cart.calculateTotal() << endl;
    }
};

class ShoppingCartStorage {
private:
    ShoppingCart& cart; // no ownership

public:
    ShoppingCartStorage(ShoppingCart& cart) : cart(cart) {}

    void saveToDatabase() {
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main() {
    auto cart = make_unique<ShoppingCart>(); // owner

    cart->addProduct(make_unique<Product>("Laptop", 1500));
    cart->addProduct(make_unique<Product>("Mobile", 500));

    ShoppingCartPrinter printer(*cart); // pass reference
    printer.printInvoice();

    ShoppingCartStorage db(*cart); // pass reference
    db.saveToDatabase();

    return 0;
}
