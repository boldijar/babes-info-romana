#include "ui.h"
#include "domain.h"
#include <iostream>

using namespace Ui;
using namespace Domain;

class Application {
public:
	Application();
	~Application();
	void run();
private:
	ProductRepository* productRepository;
	SaleRepository* saleRepository;
	POS* pos;
	Menu* menuPos;
	MenuItem* menuItemNewSale;
	Menu* menuReports;
	MenuItem* menuItemSalesReport;
	MenuItem* menuItemMonetaryReport;
	NewSale* newSale;
	SaleReport saleReport;
	MonetaryReport monetaryReport;
};

Application::Application() {
	productRepository = new ProductRepository();
	saleRepository = new SaleRepository();
	pos = new POS(productRepository, saleRepository);
	menuPos = new Menu("POS");
	newSale = new NewSale(pos);
	menuItemNewSale = new MenuItem("New sale", newSale);
	menuReports = new Menu("Reports");
	menuItemSalesReport = new MenuItem("Sales report", &saleReport);
	menuItemMonetaryReport = new MenuItem("Monetary report", &monetaryReport);
	menuReports->add(menuItemSalesReport);
	menuReports->add(menuItemMonetaryReport);
	menuPos->add(menuItemNewSale);
	menuPos->add(menuReports);
}

Application::~Application() {
	delete productRepository;
	delete saleRepository;
	delete newSale;
	delete menuItemNewSale;
	delete menuItemSalesReport;
	delete menuItemMonetaryReport;
	delete menuReports;
	delete menuPos;
}

void Application::run() {
	try {
		menuPos->execute();
	} catch (...) {
		cout << "An unknown exception has occurred.";
	}
}

int main() {
	Application application;
	application.run();
	return 0;
}
