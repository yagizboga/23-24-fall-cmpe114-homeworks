#include<iostream>
#include<string>

using namespace std;

class pig{
	
	string name;
	int strength;
	public:
		pig(string n, int s)
		{
			name = n;
			strength = s;
			cout << name << " the pig is created with strength " << strength << endl;
		}
		pig(string n)
		{
			name = n;
			strength = 100;
			cout << name << " the pig is created with strength " << strength << endl;
			
		}
		
		void work()
		{
			cout << name << " is at work!"<< endl;
			strength+=10;
		}
		void print()
		{
			cout << name << " the pig has the strength " << strength << endl;
		}
		int getstrength()
		{
			return strength;
		}
		~pig()
		{
			cout << name << " is destroyed." << endl;
		}
	
};

class horse{
	string name;
	int strength;
	public:
		horse(string n, int s)
		{
			name = n;
			strength =s;
			cout << name << " the horse is created with strength " << strength << endl;
		}
		horse(string n)
		{
			name = n;
			strength = 100;
			cout << name << " the horse is created with strength " << strength << endl;
			
		}
		void work()
		{
			cout << name << " will work harder!" << endl;
			strength -=10;
		}
		void print()
		{
			cout << name << " the horse has the strength " << strength << endl;
		}
		~horse()
		{
			cout << name << " is destroyed." << endl;
		}
	
};

int main(){
	
	pig p1("Snowball");
	pig p2("Napoleon",120);
	horse h1("Clover",90);
	horse h2("Boxer");
	
	
	char inp;
	
	while(p1.getstrength() + p2.getstrength() < 300){
		
	cout << "Enter an input : "; 
	cin >> inp;
	
	if(inp == 'w')
	{
		h1.work();
		h1.print();
		h2.work();
		h2.print();
		p1.work();
		p1.print();
		p2.work();
		p2.print();
		if(p1.getstrength() + p2.getstrength() >= 300)
	{
		cout << "The pigs won."<< endl;
	}
		
	}
	else if(inp == 'q')
	{
		return 0;
	}
	else
	{
		cout << "Invalid input." << endl;
	}
	
	}
	
}

