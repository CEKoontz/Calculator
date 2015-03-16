// Default Constructor
template <typename T, typename V>
Subtract <T, V>::Subtract(void)
	:rank_(0)
{

}


// Default Destructor
template <typename T, typename V>
Subtract <T, V>::~Subtract(void) {

}


// Precedence
template <typename T, typename V>
int Subtract <T, V>::precedence(void) {
	return this->rank_;
}


// Operate
template <typename T, typename V>
T Subtract <T, V>::operate(T & a, T & b) {
	return (a - b);
}