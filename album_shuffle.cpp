#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

struct Song
{
	string artist;
	int album_num;
	int track_num;
	string name;
	bool operator < (const Song& s) const {
		return album_num == s.album_num ? track_num < s.track_num : album_num < s.album_num;
	}
};


vector<Song> albumShuffle(vector<Song> songs) {
	unordered_map<int, set<Song> > um;
	vector<int> album_nums;
	for (int i = 0; i < songs.size(); ++i) {
		if(um.find(songs[i].album_num) == um.end()) {
			album_nums.push_back(songs[i].album_num);
		}
		um[songs[i].album_num].insert(songs[i]);
	}

	//shuffle
	srand((unsigned)time(NULL));
	for (int i = album_nums.size() - 1; i >= 0; --i) {
		swap(album_nums[i], album_nums[rand() % (i + 1)]);
	}

	vector<Song> ans_songs;

	for (int i = 0; i < album_nums.size(); ++i) {
		for (auto itr = um[album_nums[i]].begin(); itr != um[album_nums[i]].end(); ++itr) {
			ans_songs.push_back(*itr);
		}		
	}
	return ans_songs;
}


int main(){
	Song s1 = {"A", 1, 1, "X"};
	Song s2 = {"A", 1, 2, "Y"};
	Song s3 = {"A", 2, 1, "Z"};
	Song s4 = {"A", 3, 1, "W"};
	vector<Song> arg{s1, s2, s3, s4};
	cout << "before shuffle" << endl;
	for (int i = 0; i < arg.size(); ++i)
	{
		cout << arg[i].artist << " " << arg[i].album_num << " " << arg[i].track_num << " " << arg[i].name << endl;
	}
	cout << "after shuffle" << endl;
	vector<Song> shuffled_songs = albumShuffle(arg);
	for (int i = 0; i < shuffled_songs.size(); ++i)
	{
		cout << shuffled_songs[i].artist << " " << shuffled_songs[i].album_num << " " << shuffled_songs[i].track_num << " " << shuffled_songs[i].name << endl;
	}

}

