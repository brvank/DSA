// Encapsulation, Inheritance, Abstraction and Plymorphism in C++ 

#include<iostream>

using namespace std;

class car{
	
	// 'car' class having it's data(speed) and methods in a single unit i.e., 'car' class itself ---> Encapsulation
	
	protected:
		//speed is protected, so can be accessed by the child class
		int speed;
		
	public:
		//Constructor		
		car(){
			this->speed = 0;
			cout<<"\nYour car is ready.\n"<<endl;
		}
		
		void getBrand(){
			cout<<"Brand: None"<<endl;
		}
		
		void getModel(){
			cout<<"Model: None"<<endl;
		}
		
		void increaseSpeed(){
			this->speed += 10;
			cout<<"Now the speed is "<<this->speed<<endl;
		}
		
		void getSpeed(){
			cout<<"Speed is "<<this->speed<<endl;
		}
		
		//hiding the function of break from the user and just providing a function for applying break ---> Abstraction
		void applyBreak(){
			if(this->speed<10){
				speed = 0;
				cout<<"Your car is stopped now!\n";
				return;
			}
			this->speed -= 10;
			cout<<"Now the speed is "<<this->speed<<endl;
		}
		
};

//making child class of 'car' class ---> Inheritance
class scorpio: public car{
	
	// 'scorpio' class having it's data(brand & model) and methods in a single unit i.e., 'scorpio' class itself ---> Encapsulation
	
	private:
		//Hiding the access of main data from the user ---> Abstraction
		string brand;
		string model;
		
	public:
		//Constructor
		scorpio(){
			this->brand = "scorpio";
			this->model = "None";
		}
		
		//Constructor
		scorpio(string model){
			this->brand = "scorpio";
			this->model = model;
		}
		
		void getBrand(){
			cout<<"Brand: "<<this->brand<<endl;
		}
		
		void getModel(){
			cout<<"Model: "<<this->model<<endl;
		}
		
		//increase speed(), get speed() and applyBreak() functions are overrided ---> Polymorphism
		void increaseSpeed(){
			this->speed += 13;
			cout<<"Now the speed is "<<this->speed<<endl;
		}
		
		void getSpeed(){
			cout<<"Speed is "<<this->speed<<endl;
		}
		
		//hiding the function of break from the user and just providing a function for applying break ---> Abstraction
		void applyBreak(){
			if(this->speed<13){
				speed = 0;
				cout<<"Your car is stopped now!\n";
				return;
			}
			this->speed -= 13;
			cout<<"Now the speed is "<<this->speed<<endl;
		}
		
};

//making child class of 'car' class ---> Inheritance
class nano: public car{
	
	// 'nano' class having it's data(brand & model) and methods in a single unit i.e., 'nano' class itself ---> Encapsulation
	
	private:
		//Hiding the access of main data from the user ---> Abstraction
		string brand;
		string model;
		
	public:
		//Constructor
		nano(){
			this->brand = "nano";
			this->model = "None";
		}
		
		//Constructor
		nano(string model){
			this->brand = "nano";
			this->model = model;
		}
		
		void getBrand(){
			cout<<"Brand: "<<this->brand<<endl;
		}
		
		void getModel(){
			cout<<"Model: "<<this->model<<endl;
		}
		
		//increase speed(), get speed() and applyBreak() functions are overrided ---> Polymorphism
		void increaseSpeed(){
			this->speed += 9;
			cout<<"Now the speed is "<<this->speed<<endl;
		}
		
		void getSpeed(){
			cout<<"Speed is "<<this->speed<<endl;
		}
		
		//hiding the function of break from the user and just providing a function for applying break ---> Abstraction
		void applyBreak(){
			if(this->speed<9){
				speed = 0;
				cout<<"Your car is stopped now!\n";
				return;
			}
			this->speed -= 9;
			cout<<"Now the speed is "<<this->speed<<endl;
		}
		
};

int main(){
	car mycar;
	mycar.getBrand();
	mycar.getModel();
	mycar.getSpeed();
	mycar.increaseSpeed();
	mycar.increaseSpeed();
	mycar.applyBreak();
	mycar.getSpeed();
	
	cout<<"\n*********************************************************************";
	
	nano mynano("123-45c-a56");
	mynano.getBrand();
	mynano.getModel();
	mynano.getSpeed();
	mycar.increaseSpeed();
	mycar.increaseSpeed();
	mynano.applyBreak();
	mynano.getSpeed();
	
	cout<<"\n*********************************************************************";
	
	scorpio myscorp("123-456");
	myscorp.getBrand();
	myscorp.getModel();
	myscorp.getSpeed();
	myscorp.applyBreak();
	myscorp.getSpeed();
	
	cout<<"\n*********************************************************************";
	
	return 0;
}
