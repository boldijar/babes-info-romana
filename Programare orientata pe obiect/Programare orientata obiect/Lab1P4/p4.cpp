// 4. Determina primele n cifre din scrierea fractiei subunitare
//    k/m = 0.c1c2c3..., pentru k si m numere naturale date.

#include <iostream>
using namespace std;

int power10(float x){
	int pzece = 1, i;
	for (i=1; i<=x; i++){
		pzece = pzece * 10;
	}
	return pzece;
}

int zecimal(float a, float b, int c){
	float x, pzece;
	x = a/b;
	pzece = power10(c);
	x = int(x * pzece);
	return x;

}



int main() {

  float  k, m, n;
  int x, y;

  cout << "read k: ";
  cin >> k;
  cout << "read m: ";
  cin >> m;
  cout << "read n: ";
  cin >> n;

  x = zecimal(k,m,n);
  y = power10(n);
  x = x % y;
  cout << x << endl;
  return 0;
}
