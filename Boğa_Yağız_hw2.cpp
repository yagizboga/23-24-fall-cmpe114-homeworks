#include<iostream>
#include<string>
using namespace std;


class computer{
	public:
		virtual void writeCode() = 0;
		virtual void playGame() = 0;
		virtual string get_name() = 0;
};

class laptop:public computer{
	public:
		string model;
		laptop(string m):model(m){
		}
		void writeCode(){
			cout<<"you can code in "<<model<<" laptop using c++"<<endl;
		}
		void playGame(){
			cout<<"You can play Minecraft on "<<model<<" laptop"<<endl;
		}
		string get_name(){
			return model;
		}
};

class desktop:public computer{
	public:
		string type;
		desktop(string t):type(t){
		}
		void writeCode(){
			cout<<"you can code in "<<type;
		}
		void playGame(){
		}
		string get_name(){
			return type;
		}
};

void recommendComputer(string prefer,int budget){
	if(prefer == "l" || prefer == "L"){
		if(budget >=1000 && budget<1500){
			computer *obj1 = new laptop("Dell XPS");
			cout <<"We recommend the "<<obj1->get_name()<<" for you:"<<endl;
			obj1->writeCode();
			obj1->playGame();
			delete obj1;
			
		}
		else if(budget >=1500){
			computer *obj1 = new laptop("MacBook Pro");
			cout <<"We recommend the "<<obj1->get_name()<<" for you:"<<endl;
			obj1->writeCode();
			obj1->playGame();
			delete obj1;
		}
		else{
			cout<<"Sorry, we couldn't find a suitable recommendation for your budget."<<endl;
		}
	}
	else if(prefer == "D" || prefer == "d"){
		if(budget >=2000 && budget<2500){
			computer *obj1 = new laptop("Gaming Desktop");
			cout <<"We recommend the "<<obj1->get_name()<<" for you:"<<endl;
			obj1->writeCode();
			obj1->playGame();
			delete obj1;
			
		}
		else if(budget >=2500){
			computer *obj1 = new laptop("Workstation Desktop");
			cout <<"We recommend the "<<obj1->get_name()<<" for you:"<<endl;
			obj1->writeCode();
			obj1->playGame();
			delete obj1;
		}
		else{
			cout<<"Sorry, we couldn't find a suitable recommendation for your budget."<<endl;
		}
		
	}
	
}

int main(){
	string choise = "Y";
	string prefer;
	int budget;
	
	cout << "Welcome to the Computer Recommendation System!"<<endl;
	while(choise == "Y" || choise == "y"){
		cout << "Do you prefer Laptop or a Desktop? (L/D):";
		cin >> prefer;
		if(prefer == "l"||prefer =="L"||prefer=="D"||prefer=="d"){
			cout << "What is you budget? (Enter a numeric value):";
		cin >> budget;
		recommendComputer(prefer,budget);
		}
		else{
			cout << "Invalid preference! Please choose either Laptop or Desktop."<<endl;
		}
	cout<<"Do you want another recommendation? (Y/N):";
		cin>>choise;
	
	}
	if(choise == "N"||choise =="n"){
		cout<<"Thank you for using the Computer Recommendation System! Goodbye!";
	}
}
