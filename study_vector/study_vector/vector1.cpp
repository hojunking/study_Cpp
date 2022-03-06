#include <iostream>
#include <vector>
#include <string>

using namespace std;
void about_capacity(void); //capacity�� ũ��Ȯ��
void using_size_type(void); // vector ����(size_type, iterater)
void vector_with_string(void); // string�� ���� vector

int main(void) {
	//about_capacity();
	//using_size_type();
	vector_with_string();
}
void vector_with_string(void) {
	vector<string> v;
	v.push_back("�ȳ� ����!");
	v.push_back("�ȳ� ȣ��!");
	v.push_back("���ϴ�~?");
	v.push_back("�� ������ ����?");
	v.push_back("���� �ò�����?");

	cout << "v.front : " << v.front() << "\n";
	cout << "v.back : " << v.back() << "\n";
	//front - back / begin - end (capacity)
	vector<string>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << " /";
	}

	cout << "\n";
	v.pop_back(); // ������ ���һ���
	for (iter = v.begin(); iter !=v.end(); iter++)
		cout << *iter << " /";
	cout << "\n";

	for (iter = v.begin(); iter != v.end(); iter++) {
		if (*iter == "���ϴ�~?") { //���ϴ�~? erase
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
	
	//iterator ����ϱ�
	vector<int>::iterator iter; //iterator qustn
	for (iter = v.begin(); iter !=v.end(); iter++) {
		cout << *iter << " ";
	}
}
void about_capacity(void) {
	vector<int> v;

	cout << "v // size() // capacity()" << "\n";
	for (int i = 0; i < 65; i++) {
		v.push_back(i + 1); //vector �ڿ��� �ϳ��� �ֱ�
		cout << "[" << v[i] << " , " << v.size() << " , " << v.capacity()
			<< "]" << "\n";
	}
}