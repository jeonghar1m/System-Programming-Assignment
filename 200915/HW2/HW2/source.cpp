#include <iostream>
using namespace std;
class Car
{
	string producer; //제작사
	string model; //모델명
	int since; //제작년도
	int price; //가격
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
		cout << "입력하신 차량의 제조사는 " << producer << "입니다." << endl;
		cout << "입력하신 차량의 모델명은 " << model << "입니다." << endl;
		cout << "입력하신 차량의 가격은 " << price << "입니다." << endl;
		cout << "입력하신 차량의 제작년도는 " << since << "입니다." << endl;
	}
};
int main()
{
	Car car;
	char producer[30] = {};
	char model[30] = {};
	int price;
	int since;
	cout << "차량의 제조사를 입력해주세요: ";
	cin >> producer;
	cout << "차량의 모델명을 입력해주세요: ";
	cin >> model;
	cout << "차량의 가격을 입력해주세요: ";
	cin >> price;
	cout << "차량의 제작년도를 입력해주세요: ";
	cin >> since;
	car.set_producer(producer);
	car.set_model(model);
	car.set_price(price);
	car.set_since(since);
	car.render();
	return 0;
}