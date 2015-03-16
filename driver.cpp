#include <iostream>
#include <memory>
#include "StackElementFactory.h"
#include "Evaluator.h"

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::shared_ptr;

int main(void) {
	std::string exp;
	StackElementFactory <int> factory = StackElementFactory <int>();
	Queue <shared_ptr < ExpressionElement <int, Stack <int> > > > pfe;
	int result;

	getline(cin, exp);
	while (exp != "QUIT") {
		if (parse(exp, pfe)) {
			if (evaluate(pfe, result))
				cout << result << endl;
			else
				cout << "evaluation error" << endl;
		}
		else {
			cout << "parsing error" << endl;
		}

		// Get new input
		getline(cin, exp);
		pfe.clear();
	}

	return 1;
}