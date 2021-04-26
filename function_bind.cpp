#include <iostream>
//#include <functional>



void add(int x, int y){

	printf("%d + %d = %d\n", x, y, x+y);


}


class Test{
public:

	int self_;

	Test(int self)
	: self_(self){}

	int add(int x, int y){
		printf("%d + %d = %d\n", x, y, x+y);
		printf("%d\n", self_);
		return x+y;
	}
};



int main(){
	


	std::function<void (int, int)> func = add;
	

	func(10, 20);

	auto func2 = std::bind(add, 10, 20);

	Test t(10);
	auto func3 = std::bind(&Test::add, &t, 30, 40);
	func3();

}

