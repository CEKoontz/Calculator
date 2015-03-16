// Default Constructor
template <typename T, typename V>
Add <T, V>::Add(void)
	:rank_(0)
{

}


// Default Destructor
template <typename T, typename V>
Add <T, V>::~Add(void) {

}


// Precedence
template <typename T, typename V>
int Add <T, V>::precedence(void) {
	return this->rank_;
}


// Operate
template <typename T, typename V>
T Add <T, V>::operate(T & a, T & b) {
	return (a + b);
}