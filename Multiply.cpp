// Default Constructor
template <typename T, typename V>
Multiply <T, V>::Multiply(void)
	:rank_(1)
{

}


// Default Destructor
template <typename T, typename V>
Multiply <T, V>::~Multiply(void) {

}


// Precedence
template <typename T, typename V>
int Multiply <T, V>::precedence(void) {
	return this->rank_;
}


// Operate
template <typename T, typename V>
T Multiply <T, V>::operate(T & a, T & b) {
	return (a * b);
}