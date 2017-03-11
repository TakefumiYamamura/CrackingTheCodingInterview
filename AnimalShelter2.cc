#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

enum AnimalType
{
	DOG = 0,
	CAT = 1,
};

class Animal
{
public:
	string name;
	int order;
	AnimalType type;
	Animal();
	Animal(string n, AnimalType t){
		name = n;
		type = t;
	}
	virtual ~Animal(){};
	virtual void cry() = 0;
};

class Dog : public Animal
{
public:
	Dog();
	virtual ~Dog(){};
	Dog(string n, AnimalType t):Animal(n, t){};
	virtual void cry() override{
		cout << "bow" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat();
	virtual ~Cat(){};
	Cat(string n, AnimalType t):Animal(n, t){};
	virtual void cry() override{
		cout << "nya-nya" << endl;
	}
};

class AnimalShelter{
private:
	queue<Animal*> dogqueue;
	queue<Animal*> catqueue;
	int order;

public:
	AnimalShelter(){
		order = 0;

	}
	void enqueue(Animal* anm){
		anm->order = order;
		order++;
		if(anm->type == DOG){
			dogqueue.push(anm);
		}else if(anm->type == CAT){
			catqueue.push(anm);
		}
	}

	Animal* dequeueAny(){
		assert(!(dogqueue.empty() && catqueue.empty()));
		if(dogqueue.empty()){
			Animal* tmp = catqueue.front();
			catqueue.pop();
			return tmp;
		}
		if(catqueue.empty()){
			Animal* tmp = dogqueue.front();
			dogqueue.pop();
			return tmp;
		}
		Animal* tmpD = dogqueue.front();
		Animal* tmpC = catqueue.front();
		if(tmpD->order < tmpC->order){
			dogqueue.pop();
			return tmpD;
		}else{
			catqueue.pop();
			return tmpC;
		}
	}

	Animal* dequeueDog(){
		assert(!dogqueue.empty());
		Animal* tmp = dogqueue.front();
		dogqueue.pop();
		return tmp;
	}

	Animal* dequeueCat(){
		assert(!catqueue.empty());
		Animal* tmp = catqueue.front();
		catqueue.pop();
		return tmp;
	}
};


int main(){
	AnimalShelter as = AnimalShelter();
	// as.dequeueAny();
	as.enqueue(new Dog("dog1", DOG));
	as.enqueue(new Cat("cat1", CAT));
	as.enqueue(new Dog("dog2", DOG));
	as.enqueue(new Cat("cat2", CAT));
	for (int i = 0; i < 3; ++i)
	{
		Animal* tmp = as.dequeueAny();
		cout << tmp->name << endl;
		tmp->cry();
	}
	as.enqueue(new Dog("dog3", DOG));
	as.enqueue(new Cat("cat3", CAT));
	as.enqueue(new Cat("cat4", CAT));
	as.enqueue(new Cat("cat5", CAT));
	for (int i = 0; i < 2; ++i)
	{
		Animal* tmp = as.dequeueCat();
		cout << tmp->name << endl;	
	}

}

