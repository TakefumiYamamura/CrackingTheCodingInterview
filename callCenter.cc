#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

enum EmployeeType
{
	RESPONDANT = 0,
	DIRECTOR = 1,
	MANAGER = 2,
};

class Employee
{
protected:
	string name;
	int age;
	EmployeeType type;
public:
	Employee();
	Employee(string _name, int _age){
		name = _name;
		age = _age;
	}
	virtual ~Employee();
};

class Respondant : public Employee
{
public:
	Respondant();
	Respondant(string _name, int _age) : Employee(_name, _age){
		type = RESPONDANT;
	};
	virtual ~Respondant();
};

class Director : public Employee
{
public:
	Director();
	Director(string _name, int _age) : Employee(_name, _age){
		type = DIRECTOR;
	};
	virtual ~Director();
};

class Manager : public Employee
{
public:
	Manager();
	Manager(string _name, int _age) : Employee(_name, _age){
		type = MANAGER;
	};
	virtual ~Manager();
};

class Call
{
private:
	string phone_num;
	string date;
	EmployeeType call;
public:
	Call(EmployeeType _rank){
		rank = _rank;
	}
	virtual ~Call(){

	}

};

class CallHandler
{
private:
	queue<Respondant> respondant_queue;
	queue<Director> direcotr_queue;
	queue<Manager>  manager_queue;

public:
	CallHandler();
	virtual ~CallHandler();

	///割り当てることが出来たらtrueを返すkaesu
	bool dispatchCall(Call call){
		if(call.rank <= RESPONDANT && !respondant_queue.empty()){
			respondant_queue.pop();
			return true;
		}else if(call.rank <= DIRECTOR && !direcotr_queue.empty()){
			direcotr_queue.pop();
			return true;
		}else if(call.rank <= MANAGER && !manager_queue.empty()){
			return true;
		}
	}
	
};