#include <iostream>
using namespace std;
 
template <class T>
class list
{
public:
    list()
    {
        nrelemente = 0;
        nrelementeMAX = 8;
        
        elems = (T*)malloc(sizeof(T) * 8);
 
        for (int i = 0; i < 8; ++i)
            elems[i] = NULL;
    }
 
    void push_back(T elem)
    {
        if (nrelemente == nrelementeMAX)
        {
            nrelementeMAX *= 2;
            elems = (T*)realloc(elems, sizeof(T) * nrelementeMAX);
        }
 
        elems[nrelemente++] = elem;
    }
 
    class iterator
    {
    public:
        iterator(int _current, T* elemsRef) : current(_current), elems(elemsRef) { }
 
        T& operator* () const { return elems[current]; }
 
        T& operator++ () { return elems[++current]; }
 
        bool operator!= (iterator itr) { return current != itr.current; }
 
    private:
        int current;
        T* elems;
    };
 
    iterator begin() { return iterator(0, elems); }
    iterator end() { return iterator(nrelemente, elems); }
 
private:
    int nrelemente;
    int nrelementeMAX;
 
    T* elems;
};
 
 
int main()
{
    list<int> l;
 
    for (int i = 0; i < 16; ++i)
    	l.push_back(i);
 
    for (list<int>::iterator itr = l.begin(); itr != l.end(); ++itr)
        std::cout << *itr << " ";
 
    return 0;
}