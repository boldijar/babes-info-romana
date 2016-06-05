#ifndef DOMAIN_H_
#define DOMAIN_H_

#include <string>
#include <vector>

using namespace std;

namespace Domain {

class Product {
public:
	Product(int code, string description, double price) :
			code(code), description(description), price(price) {
	}
	double getCode() const {
		return code;
	}
	double getPrice() const {
		return price;
	}
	const string& getDescription() const {
		return description;
	}
private:
	int code;
	string description;
	double price;
};

class SaleItem {
public:
	SaleItem(double quantity, Product* product) :
			quantity(quantity), product(product) {
	}
	double getSubtotal() const {
		return quantity * product->getPrice();
	}
private:
	double quantity;
	Product* product;
};

class Sale {
public:
	void addSaleItem(double quantity, Product* product);
	double getTotal() const;
	bool isValid() {
		return saleItems.size() > 0;
	}
	~Sale();
private:
	vector<SaleItem*> saleItems;
};

template<typename Entity, typename Id>
class AbstractRepository {
public:
	virtual Entity* findById(const Id id) const = 0;
	virtual void save(Entity* entity) = 0;
	virtual ~AbstractRepository() {
	}
protected:
	vector<Entity*> entities;
};

class ProductRepository: public AbstractRepository<Product, int> {
public:
	ProductRepository();
	virtual Product* findById(const int id) const;
	virtual void save(Product* entity);
	virtual ~ProductRepository();
};

class SaleRepository: public AbstractRepository<Sale, int> {
public:
	virtual Sale* findById(const int id) const;
	virtual void save(Sale* entity);
	virtual ~SaleRepository();
};

class POS {
public:
	POS(ProductRepository* productRepository, SaleRepository* saleRepository) :
			sale(0), productRepository(productRepository), saleRepository(
					saleRepository) {
	}
	void newSale();
	Product* getProductByCode(int productCode);
	void enterSaleItem(double quantity, Product* product);
	double getSaleTotal();
	void endSale();
private:
	Sale* sale;
	ProductRepository* productRepository;
	SaleRepository* saleRepository;
};

class Error {
public:
	Error(string message) :
			message(message) {
	}
	const string& getMessage() const {
		return message;
	}
private:
	string message;
};
class NotYetImplementedError: public Error {
public:
	NotYetImplementedError(string message) :
			Error(message) {
	}
};
class ValidationError: public Error {
public:
	ValidationError(string message) :
			Error(message) {
	}
};

}

#endif /* DOMAIN_H_ */
