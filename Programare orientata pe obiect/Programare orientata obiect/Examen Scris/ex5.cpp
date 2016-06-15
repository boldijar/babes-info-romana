#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class SaleItem{
public:
    int code,price;
    SaleItem(int c,int p):code(c),price(p){}
    SaleItem& operator=(SaleItem& s){
        code=s.code;
        price=s.price;
        return *this;
    }
};
class Sale{
public:
    std::vector<SaleItem*> vector;
    void add(SaleItem s){
        SaleItem* s1=new SaleItem(s);
        vector.push_back(s1);
    }
};
class Discount{
public:
    virtual double calc(Sale sale)=0;
    virtual ~Discount(){}
};
class DiscountSum:public Discount{
private:
    std::vector<Discount*> discount_vector;
public:
    void addDiscountSum(Discount* d){
        discount_vector.push_back(d);
    }

    double calc(Sale sale){
        double s=0;
        std::for_each(discount_vector.begin(),discount_vector.end(),[&](Discount* t){
        	s+=t->calc(sale);
        	});
        return s;
    }

};
class DiscountItem:public Discount{
private:
    int code,precetange;
public:
    DiscountItem(int c,int p):code(c),precetange(p){}
    double calc(Sale sale){
        auto it =std::find_if(sale.vector.begin(),sale.vector.end(),[&](SaleItem* d){return d->code==code;});
        return (*it)->price*precetange*0.01;
    }
};
int main(int argc, char *argv[])
{

    Sale s;
    SaleItem b(1,1900);
    s.add(b);
    SaleItem c(2,678.3);
    s.add(c);
    SaleItem d(3,459.2);
    s.add(d);

    Discount* d1=new DiscountItem(1,10);
    Discount* d2=new DiscountItem(2,15);
    Discount* d3=new DiscountItem(3,10);

    DiscountSum* total=new DiscountSum();
    total->addDiscountSum(d1);
    total->addDiscountSum(d2);
    total->addDiscountSum(d3);

    std::cout<<total->calc(s);
}