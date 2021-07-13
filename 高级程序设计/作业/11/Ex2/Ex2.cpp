#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <algorithm>

using namespace std;
using namespace std::placeholders;
/* 求导数函数，对某个函数f在点x0处求得导数
* f'(x0) = (f(x0)-f(x0-d))/d
* params:
* x: x0
* d: d
* f: f
*/
double derivative(double x, double d, double (*f)(double)) {
	return (f(x) - f(x - d)) / d;
}

auto bind_derivative(double x, double d) {
	return std::bind(derivative, x, d, _1);
}

auto bind_derivative(double x) {
	return [x](double d) {return std::bind(derivative, x, d, _1); };
}

int main() {
	std::vector<double (*)(double)> funcs = { sin, cos, tan, exp, sqrt, log, log10 };
	// ⽬标函数
	auto d1 = bind_derivative(1, 0.000001); // 在x=1处求导数的函数d1
	auto d2 = bind_derivative(1)(0.000001); // 在x=1处求导数的函数d2
	std::vector<double> result1, result2;
	std::transform(funcs.begin(), funcs.end(), std::back_inserter(result1), d1);
	std::transform(funcs.begin(), funcs.end(), std::back_inserter(result2), d2);
	// result1的结果与result2的结果相同
	return 0;
}