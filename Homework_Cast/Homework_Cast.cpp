
#include <iostream>

class Person
{
protected:
	char* name = nullptr;
	int age = 0;
public:
	Person()
	{
		name = nullptr;
		age = 0;
	}
	Person(const char* _name, int _age)
	{
		name = new char[strlen(_name) + 1];
		name[strlen(_name)] = '\0';
		for (int i = 0; i < strlen(_name); i++)
		{
			name[i] = _name[i];
		}
		age = _age;
	}

	char* getName() const
	{
		return name;
	}
	int getAge() const
	{
		return age;
	}

	virtual ~Person()
	{
		if (name != nullptr)
		{
			delete[] name;
		}
	}
};
class Employee : public Person
{
private:
	int salary = 0;
public:
	Employee() : Person()
	{
		salary = 0;
	}
	Employee(const char* _name, int age, int _salary) : Person(_name, age)
	{
		salary = _salary;
	}

	int getSalary() const
	{
		return salary;
	}

	void setSalary(int _sal)
	{
		salary = _sal;
	}

	~Employee() override {}
};

void display(Person* &obj)
{
	Employee* check = dynamic_cast<Employee*>(obj);
	if (check != nullptr)
	{
		std::cout << "Name: " << check->getName() << "\nAge: " << check->getAge() << "\nSalary: " << check->getSalary() << '\n';
	}
	else
	{
		std::cout << "Name: " << obj->getName() << "\nAge: " << obj->getAge() << '\n';
	}
}

class Animal
{
protected:
public:
	virtual void makesound()
	{
		std::cout << "nothing happens\n";
	}
};
class Dog : public Animal
{
private:
public:
	void makesound() override
	{
		std::cout << "Woof!\n";
	}
};

int main()
{
	int choise = 0;
	std::cin >> choise;
	if (choise == 0)
	{
		Employee Test1("John", 30, 1000);
		Person* test1 = dynamic_cast<Person*>(&Test1);
		display(test1);
	}
	else if (choise == 1)
	{
		Animal* Test2 = new Dog;
		Dog* dog = reinterpret_cast<Dog*>(Test2);
		dog->makesound();
	}
	else
	{
		return 0;
	}
}