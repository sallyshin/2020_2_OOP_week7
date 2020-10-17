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
/* (�ǽ� 1-1) �м���� :
* ��ü�� �Ҹ��ڵ��� �Լ��� ����� �� ȣ��ǹǷ� "Executed in "�� ���� ��µ� ��
* �� �ڿ� "Destructure execution " ������ ��µȴ�.
������ :
Executed in B
Destructor execution: B
Executed in A
Destructor execution: A
*/
/* (�ǽ� 1-2) �м���� :
* ���ÿ� main() -> funcA() -> funcB() ������ ����.
* funcB()���� Test ��ü�� ���� ����ǰ� �� ���� ���ܰ� �߻��ȴ�.
* �׷��� �� ���ܴ� ���� ����� catch�� ã�´�.
* funcB()���� ���ð�ü�� �����Ƿ� �� ��ü�� ���� �Ҹ��ڴ� ���� ���� ���μ������� ȣ��ȴ�.
* funcB���� ���ð�ü ȣ���ѵ� ���ÿ��� �Ҹ�
* funcA���� ���ð�ü ȣ���ѵ� ���ÿ��� �Ҹ�
* funcB()���� funcA()���� ������ main()���� catch������ �ִ�.
* main()���� catch���� ����
������ :
Destructor execution: B
Destructor execution: A
Exception : Exception from funcB!
*/