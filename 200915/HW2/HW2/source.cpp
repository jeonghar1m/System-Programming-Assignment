#include <iostream>
using namespace std;
class Car
{
	string producer; //���ۻ�
	string model; //�𵨸�
	int since; //���۳⵵
	int price; //����
public:
	void set_model(char* gmodel)
	{
		model = gmodel;
	}
	void set_producer(char* gproducer)
	{
		producer = gproducer;
	}
	void set_price(int gprice)
	{
		price = gprice;
	}
	void set_since(int gsince)
	{
		since = gsince;
	}
	void render()
	{
		cout << "�Է��Ͻ� ������ ������� " << producer << "�Դϴ�." << endl;
		cout << "�Է��Ͻ� ������ �𵨸��� " << model << "�Դϴ�." << endl;
		cout << "�Է��Ͻ� ������ ������ " << price << "�Դϴ�." << endl;
		cout << "�Է��Ͻ� ������ ���۳⵵�� " << since << "�Դϴ�." << endl;
	}
};
int main()
{
	Car car;
	char producer[30] = {};
	char model[30] = {};
	int price;
	int since;
	cout << "������ �����縦 �Է����ּ���: ";
	cin >> producer;
	cout << "������ �𵨸��� �Է����ּ���: ";
	cin >> model;
	cout << "������ ������ �Է����ּ���: ";
	cin >> price;
	cout << "������ ���۳⵵�� �Է����ּ���: ";
	cin >> since;
	car.set_producer(producer);
	car.set_model(model);
	car.set_price(price);
	car.set_since(since);
	car.render();
	return 0;
}