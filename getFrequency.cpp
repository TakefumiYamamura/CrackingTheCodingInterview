class Solution
{
private:
	vector<string> books;
	unordrered_map<string, int> um;
public:
	void preprocess(){
		for (int i = 0; i < books.size(); ++i)
		{
			um[books[i]]++;
		}
	}
	int getFrequency(string str){
		return um[str];
	}
	
};
