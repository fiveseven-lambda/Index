#include <iostream>

class Index{
	size_t val;
	const size_t n;
public:
	constexpr Index(const size_t n, size_t val = 0): n(n), val(val){}
	bool operator()(size_t r = 0){
		return val < n - r;
	}
	operator size_t() const {
		return val;
	}
	operator size_t &(){
		return val;
	}
	Index operator,(const Index &i) const {
		return Index(n, val * i.n + i.val);
	}
};

int main(){
	int a[60];
	for(Index i(60); i(); ++i) a[i] = i;

	for(Index i(5); i(); ++i){
		for(Index j(6); j(); ++j){
			std::cout << "(";
			for(Index k(2); k(); ++k){
				std::cout << a[i, j, k] << "),"[k(1)];
			}
			std::cout << "\n "[j(1)];
		}
	}

	const Index i(10, 5), j(6, 2);
	std::cout << "(" << i << ", " << j << ") = " << (i, j) << std::endl;

	constexpr Index k(10, 5), l(6, 2);
	std::cout << "(" << k << ", " << l << ") = " << (k, l) << std::endl;
}
