#include<map>
#include<algorithm>
#include<fstream>
#include<string>
#include<vector>
#include<iostream>
#include<cctype>
using namespace std;

struct Statistics{
	int count;
	string word;
};

bool isPunct(const string s){
	char punct[8] = {',', '.', '!', ';', '?', '-', ':', '"'};
	for(int i = 0; i < 8; i++){
		if(s[s.size() - 1] == punct[i]){
			return true;
		}
	}
	return false;
}

string prepare(const string &s){
	string result = s;
	transform(s.begin(), s.end(), result.begin(), ::tolower);
	if (isPunct(result)){
		result.pop_back();
	}
	return result;
}
bool comp(Statistics& lhs, Statistics& rhs){
	if(lhs.count > rhs.count){
		return true;
	}
	return false;
}

int main(){
	ifstream file("file.txt");
	map<string, int> dict;
	if(file.is_open()){
		string word;
		while(!file.eof()){
			file >> word;
			word = prepare(word);
			dict[word]++;
		}
	}
	vector<Statistics> s;
	Statistics t;
	for(auto& item: dict){
		t.word = item.first;
		t.count = item.second;
		s.push_back(t);
	}
	sort(s.begin(), s.end(), comp);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
 		cout << "'" << s[i].word << "'" << ":" << s[i].count;  
	}
	return 0;
}
