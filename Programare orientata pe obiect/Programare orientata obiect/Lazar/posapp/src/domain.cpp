#include "domain.h"

namespace Domain {

void Sale::addSaleItem(double quantity, Product* product) {
	if (quantity < 0) {
		throw ValidationError("Quantity must be positive");
	}
	saleItems.push_back(new SaleItem(quantity, product));
}

double Sale::getTotal() const {
	double total = 0;
	for (size_t i = 0; i < saleItems.size(); i++) {
		total += saleItems[i]->getSubtotal();
	}
	return total;
}

Sale::~Sale() {
	//TODO: delete all allocated items
}

void POS::newSale() {
	if (sale != 0) {
		delete sale;
	}
	sale = new Sale();
}

Product* POS::getProductByCode(int productCode) {
	return productRepository->findById(productCode);
}

void POS::enterSaleItem(double quantity, Product* product) {
	sale->addSaleItem(quantity, product);
}
double POS::getSaleTotal() {
	return sale->getTotal();
}

void POS::endSale() {
	saleRepository->save(sale);
}

}

