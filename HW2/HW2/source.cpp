#include <iostream>
using namespace std;
class Car
{
	char producer[30]; //���ۻ�
	char model[30]; //�𵨸�
	int since; //���۳⵵
	int price; //����
public:
	void set_model(char* gmodel)
	{
		strcpy_s(model, gmodel);
	}
	char* get_model()
	{
		return model;
	}
	void set_producer(char* gproducer)
	{
		strcpy_s(producer, gproducer);
	}
	char* get_producer()
	{
		return producer;
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