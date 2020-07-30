#include <iostream>
using namespace std;

/* Self-Assignment */

/* Implemnting Assignment Operator */
class collar {};
class dog {
	collar* pCollar;
	// copy everything from rhs to itself
	dog& operator = (const dog& rhs) {
		if (this == &rhs)
			return *this;
		
		// delete pCollar; ----> should delete after create new pCollar not before;
		// ow the returning gives issues if you delete it (ie: delete pCollar itself will also delete rhs) 
		collar* pOriginCollar = pCollar;
		pCollar = new collar(*rhs.pCollar);
		delete pOriginCollar;
		return *this;
	}
};

/* Delegation */
class cat {
	collar* pCollar;
	cat& operator = (const cat& rhs) {
		*pCollar = *rhs.pCollar; // member by member copying of collars or call collar's operator = 
		return *this;
	}
	
};
int main() {
	dog dog1;
	dog dog2;
}