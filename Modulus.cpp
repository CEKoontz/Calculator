// Default Constructor
template <typename T, typename V>
Modulus <T, V>::Modulus(void)
	:rank_(1) {

}


// Default Destructor
template <typename T, typename V>
Modulus <T, V>::~Modulus(void) {

}


// Precedence
template <typename T, typename V>
int Modulus <T, V>::precedence(void) {
	return this->rank_;
}


// Operate
template <typename T, typename V>
T Modulus <T, V>::operate(T & a, T & b) {
	return (a % b);
}