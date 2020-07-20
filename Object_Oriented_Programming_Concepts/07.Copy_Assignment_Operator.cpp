#include<iostream>
using namespace std;



class Car{
private:
	float price;


public:
	int model_no;
	char *name;

	//Init LIst
	Car(){
		name = NULL;
	}
	Car(float p,int m,char *n){
		model_no = m;
		name = new char[strlen(n)+1];
		strcpy(name,n);
	}

	Car(Car &X){
		cout<<"Inside copy constructor";
		price = X.price;
		model_no = X.model_no;
		//deep copy
		name = new char[strlen(X.name)+1];
		strcpy(name,X.name);
	}

	void operator=(Car &X){
		price = X.price;
		model_no = X.model_no;
		//deep copy
		name = new char[strlen(X.name)+1];
		strcpy(name,X.name);

	}

	void setprice(float p){
		price = p;
	}

	void print(){
		cout<<"Name "<<name<<endl;
		cout<<"Model No "<<model_no<<endl;
		cout<<"Price "<<price<<endl;
	}
};

int main(){

	//static car
	Car c(100,200,"BMW"); //parameterised constructor

	Car d;//constructor
	d = c; //copy assignment operator as many times
	d.name[0] = 'A';
	d.setprice(400);

	c.print();

	d.print();

	return 0;
}
