//#include<iostream>
//#include<string>
//
//class Person {
//	std::string name;
//public:
//	Person() : Person("") {}
//	Person(std::string n) : name(n) {}
//
//	std::string GetName() {
//		return name;
//	}
//};
//
//class Student :public Person {
//	std::string name;
//public:
//	Student(std::string n): name(n){}
//	std::string GetName() {
//		return name;
//	}
//};
//
//int main() {
//	Student s1("ȫ�浿");
//	std::cout << "Student : " << s1.GetName() << std::endl;
//	std::cout << "Person : " << s1.Person::GetName() << std::endl;
//	return 0;
//}

#include<stdio.h>

void swap(int* a, int* b)
{
	*a = 20;
	*b = 30;
}

int main()
{
	int a = 0;
	int b = 0;
	swap(&a, &b);

	printf("%d, %d", a, b);
}