#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

class Animal
{
public:
	string name;
	int order;
	Animal();
	Animal(string n){
		name = n;
	}
	virtual ~Animal(){};
	virtual void cry() = 0;
};

class Dog : public Animal
{
public:
	Dog();
	virtual ~Dog(){};
	Dog(string n):Animal(n){};
	virtual void cry() override{
		cout << "bow" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat();
	virtual ~Cat(){};
	Cat(string n):Animal(n){};
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
		if(dynamic_cast<Dog*>(anm) != NULL){
			dogqueue.push(anm);
		}else if(dynamic_cast<Cat*>(anm) !=NULL){
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
	as.enqueue(new Dog("dog1"));
	as.enqueue(new Cat("cat1"));
	as.enqueue(new Dog("dog2"));
	as.enqueue(new Cat("cat2"));
	for (int i = 0; i < 3; ++i)
	{
		Animal* tmp = as.dequeueAny();
		cout << tmp->name << endl;
		tmp->cry();
	}
	as.enqueue(new Dog("dog3"));
	as.enqueue(new Cat("cat3"));
	as.enqueue(new Cat("cat4"));
	as.enqueue(new Cat("cat5"));
	for (int i = 0; i < 2; ++i)
	{
		Animal* tmp = as.dequeueCat();
		cout << tmp->name << endl;	
	}

}

