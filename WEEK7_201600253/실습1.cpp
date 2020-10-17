#include <iostream>
#include <stdexcept>

class Test {
public:
	Test(char id) : id_(id) {}
	~Test() {
		std::cout << "Destructor execution: " << id_ << std::endl;
	}
private:
	char id_;
};
int funcB() {
	Test r('B');
	// throw std::runtime_error("Exception from funcB!\n");
	std::cout << "Executed in B" << std::endl;
	return 0;
}
int funcA() {
	Test r('A');
	funcB();
	std::cout << "Executed in A" << std::endl;
	return 0;
}
int main() {
	try {
		funcA();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what();
	}
}
/* (실습 1-1) 분석결과 :
* 객체의 소멸자들은 함수가 종료될 때 호출되므로 "Executed in "이 먼저 출력된 후
* 그 뒤에 "Destructure execution " 문장이 출력된다.
실행결과 :
Executed in B
Destructor execution: B
Executed in A
Destructor execution: A
*/
/* (실습 1-2) 분석결과 :
* 스택에 main() -> funcA() -> funcB() 순으로 들어간다.
* funcB()에서 Test 객체가 먼저 실행되고 그 다음 예외가 발생된다.
* 그러면 이 예외는 가장 가까운 catch문 찾는다.
* funcB()에는 로컬객체가 있으므로 이 객체에 대한 소멸자는 스택 해제 프로세서에서 호출된다.
* funcB에서 로컬객체 호출한뒤 스택에서 소멸
* funcA에서 로컬객체 호출한뒤 스택에서 소멸
* funcB()에도 funcA()에도 없지만 main()에는 catch구문이 있다.
* main()에서 catch구문 실행
실행결과 :
Destructor execution: B
Destructor execution: A
Exception : Exception from funcB!
*/