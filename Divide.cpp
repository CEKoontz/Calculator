// Default Constructor
template <typename T, typename V>
Divide <T, V>::Divide(void) 
	:rank_(1)
{

}


// Default Destructor
template <typename T, typename V>
Divide <T, V>::~Divide(void) {

}


// Precedence
template <typename T, typename V>
int Divide <T, V>::precedence(void) {
	return this->rank_;
}


// Operate
template <typename T, typename V>
T Divide <T, V>::operate(T & a, T & b) {	
	if (b == 0)
		throw divide_by_zero();

	return (a / b);
}