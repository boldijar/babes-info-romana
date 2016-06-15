#include <iostream>
using namespace std;
 
class Q
{
public:
    Q() : numarator(0), numitor(1) {  }
    Q(int a, int b) : numarator(a), numitor(b) {  }
    Q(const Q& a) : numarator(a.numarator), numitor(a.numitor) {  }
 
    Q operator+ (const Q& other)
    {
        Q newRez(numarator, numitor);
 
        newRez.numitor *= other.numitor; 
        newRez.numarator *= other.numitor;
 
        newRez.numarator += other.numarator * numitor;
 
        for (int i = 2; i <= newRez.numitor; ++i)
            while (newRez.numitor % i == 0 && newRez.numarator % i == 0)
            {
                newRez.numitor /= i;
                newRez.numarator /= i;
            }
        return newRez;
    }
 
    Q operator/ (const Q& other)
    {
        Q newRez(numarator, numitor);
 
        newRez.numarator *= other.numitor;
        newRez.numitor *= other.numarator;
 
        for (int i = 2; i <= newRez.numitor; ++i)
            while (newRez.numitor % i == 0 && newRez.numarator % i == 0)
            {
                newRez.numitor /= i;
                newRez.numarator /= i;
            }
 
        if (!newRez.numitor)
            throw std::exception("Division by zero!");
 
        return newRez;
    }
 
    friend ostream& operator<< (ostream &out, const Q& obj)
    {
        out << obj.numarator << "/" << obj.numitor;
        return out;
    }
 
private:
    int numarator;
    int numitor;
};
 
int main()
{
    Q a, b(2, 3), c(b);
 
    std::cout << b + c;
    try
    {
        std::cout << b / a;
    }
    catch (std::exception& err)
    {
        std::cout << err.what();
    }
 
    return 0;
}