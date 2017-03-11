#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Entry
{
private:
	Entry* parent;
	string name;
public:
	Entry(Directory* parent, string name){
		this->parent = parent;
		this->name = name;
	}

	virtual ~Entry();

	void name(){
		cout << this->name << endl;
	}

	// directory とfile で異なる挙動
	void delete(){
	}

	//
	void create(){

	}

	string fetchURL(){
		string ans = "";
		if(parent != NULL) ans += parent->fetchURL();
		ans += name;
		return ans;
	}

};

class Directory : public Entry
{
private:
	vector<Entry>
public:
	Directory();

};


class File : public Entry
{
public:
	File();

};

int main(){

}

