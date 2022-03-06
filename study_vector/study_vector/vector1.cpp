#include <iostream>
#include <vector>
#include <string>

using namespace std;
void about_capacity(void); //capacity의 크기확인
void using_size_type(void); // vector 예제(size_type, iterater)
void vector_with_string(void); // string을 넣은 vector

int main(void) {
	//about_capacity();
	//using_size_type();
	vector_with_string();
}
void vector_with_string(void) {
	vector<string> v;
	v.push_back("안녕 현정!");
	v.push_back("안녕 호준!");
	v.push_back("뭐하눙~?");
	v.push_back("왜 연락이 없어?");
	v.push_back("왤케 시끄러워?");

	cout << "v.front : " << v.front() << "\n";
	cout << "v.back : " << v.back() << "\n";
	//front - back / begin - end (capacity)
	vector<string>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << " /";
	}

	cout << "\n";
	v.pop_back(); // 마지막 원소삭제
	for (iter = v.begin(); iter !=v.end(); iter++)
		cout << *iter << " /";
	cout << "\n";

	for (iter = v.begin(); iter != v.end(); iter++) {
		if (*iter == "뭐하눙~?") { //뭐하눙~? erase
			v.erase(iter);
			break;
		}
	}
	for (iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " /";
	cout << "\n";
	cout << "v.size() : " << v.size() << "\n";
	cout << "v.capacity() : " << v.capacity();
}
void using_size_type(void) {
	vector<int> v;
	v.push_back(21);
	v.push_back(32);
	v.push_back(53);
	v.push_back(64);
	v.push_back(15);
	v.push_back(11);

	vector<int>::size_type i = 0; //vector size_type
	
	for (i; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
	cout << "\n";
	
	//iterator 사용하기
	vector<int>::iterator iter; //iterator qustn
	for (iter = v.begin(); iter !=v.end(); iter++) {
		cout << *iter << " ";
	}
}
void about_capacity(void) {
	vector<int> v;

	cout << "v // size() // capacity()" << "\n";
	for (int i = 0; i < 65; i++) {
		v.push_back(i + 1); //vector 뒤에서 하나씩 넣기
		cout << "[" << v[i] << " , " << v.size() << " , " << v.capacity()
			<< "]" << "\n";
	}
}