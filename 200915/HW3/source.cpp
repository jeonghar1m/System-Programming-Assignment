#include <iostream>
using namespace std;
class Car
{
	string producer;
	string model;
	int since; //���۳⵵
	int price ; //����
	string promodel; //���ۻ� + �𵨸�
public:
	void set_model(string gmodel)
	{
		model = gmodel;
	}
	void set_producer(string gproducer)
	{
		producer = gproducer;
	}
	void set_promodel(string gpromodel)
	{
		promodel = gpromodel;
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
		cout << "-----------------------------------------" << endl;
		cout << promodel << endl;
	}
};
int main()
{
	Car car;
	/*char producer[30] = {};
	char model[30] = {};*/
	string producer;
	string model;
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
	string promodel = producer + " " + model;
	car.set_producer(producer);
	car.set_model(model);
	car.set_price(price);
	car.set_since(since);
	car.set_promodel(promodel);
	car.render();
	return 0;
}