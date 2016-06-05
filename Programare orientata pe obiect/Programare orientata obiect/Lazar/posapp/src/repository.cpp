#include "domain.h"

namespace Domain {

ProductRepository::ProductRepository() {
	entities.push_back(new Product(1, "Cola", 5));
	entities.push_back(new Product(2, "Pepsi", 4));
}

ProductRepository::~ProductRepository() {
	//TODO: delete products from heap
}

Product* ProductRepository::findById(const int id) const {
	for (size_t i = 0; i < entities.size(); i++) {
		if (entities[i]->getCode() == id) {
			return entities[i];
		}
	}
	return 0;
}

void ProductRepository::save(Product* entity) {
	throw NotYetImplementedError("Product.save is not yet implemented.");
}

Sale* SaleRepository::findById(const int id) const {
	throw NotYetImplementedError("Sale.findById is not yet implemented.");
}

void SaleRepository::save(Sale* entity) {
	if (entity->isValid()) {
		entities.push_back(entity);
	} else {
		throw ValidationError("Sale is invalid.");
	}
}

SaleRepository::~SaleRepository() {
}

}
