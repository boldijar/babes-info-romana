#ifndef STR_H_
#define STR_H_

#include <string>
#include <iostream>
using namespace std;

namespace utils
{

/*
 * wrapper class for the std string to be used for the type of map keys
 * (should overload the "==" operator and implement "hashCode())"
 */
class String
{
public:
	String(string s) : str(s){}
	string getValue() {return str;}
	void setValue(string s) {str = s;}
	int hashCode()
	{
		int sum = 0;
		for(unsigned i = 0; i < str.length(); i++)
			sum += str[i];
	    return sum;
	}
	bool operator == (const String& s) const {return str == s.str;}
	friend ostream& operator << (ostream& out, const String& s)
	{
		out << s.str;
		return out;
	}
private:
	string str;
};

/*
 * returns a hashCode for a String object
 * (sum of ASCII codes of all its characters)
 */
/*int String::hashCode()
{
	int sum = 0;
	for(unsigned i = 0; i < str.length(); i++)
		sum += str[i];
    return sum;
}
*/
} /*namespace util*/

#endif /* STR_H_ */
