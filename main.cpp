#include <iostream>
#include <memory>


int main(){

	int *x = new int;
	*x = 10;
	int *y = x;

	std::shared_ptr<int> p1(x);
	/* 声明 */
	std::weak_ptr<int> wp = p1;
	std::shared_ptr<int> p2 = p1;

	printf("ref: %d\n", wp.use_count());

	p1.reset(); /* 删除智能指针，p1将指向空 */

	printf("ref: %d\n", wp.use_count());
	auto p3 = wp.lock();
	p2.reset(); /* 删除，x的地址将被释放 */

	printf("&x: %p\n", y);

	printf("x: %d\n", *x);

	printf("*p3: %d\n", *p3);
}