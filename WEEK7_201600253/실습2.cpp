#include <iostream>
/*) 아래 C 스타일 예외처리 문을 try, catch, throw 를 활용하여 바꾸어 보시오.
(단, 예외는 out_of_range("Invalid Input!!")을 사용할것.
main 함수의 catch 문에서 "Invalid Input"을 예외 인자로 받아 출력할것.)
*/
bool funcA() {
	int c;
	std::cout << "input(number) : ";
	std::cin >> c;
	if (c < 10) //Let's assume this is exception
		throw std::out_of_range("Invalid input!!");
	return true;
}
int main() {

	try {
		funcA();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}
	return 0;
}