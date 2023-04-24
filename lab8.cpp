#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <utility>
std::ifstream fin("input.txt");
class Compare
{
	public:
		bool operator() (std::pair<std::string,int> p1, std::pair<std::string, int> p2) 
		{
			if (p1.second < p2.second)
				return true;
			if (p1.second > p2.second)
				return false;
			if (p1.first < p2.first)
				return false;
			return true;
		}
};
int main()
{
	std::map<std::string, int> Words;
	std::string s;
	std::getline(fin, s);
	size_t aux = 0;
	while (!s.empty())
	{
		size_t space = s.find(' ');
		size_t comma = s.find(',');
		size_t point = s.find('.');
		size_t qmark = s.find('?');
		size_t emark = s.find('!');
		size_t pos = s.size();
		if (space != std::string::npos) pos = space; 
		if (pos > comma && comma != std::string::npos) pos = comma; 
		if (pos > point && point != std::string::npos) pos = point;
		if (pos > qmark && qmark != std::string::npos) pos = qmark;
		if (pos > emark && emark != std::string::npos) pos = emark;
		if (pos != 0)
		{
			std::string s2 = s.substr(0, pos);
			for (size_t i = 0; i < s2.size(); i++)
				if (s2.at(i) >= 'A' && s2.at(i) <= 'Z')
					s2.at(i) = s2.at(i) + 'a' - 'A';
			Words[s2]++;
		}
		s = s.substr(pos + 1);
	}
	std::priority_queue<std::pair<std::string,int>, std::vector<std::pair<std::string, int>>, Compare> q;
	std::map<std::string, int>::iterator it;
	for (it = Words.begin(); it != Words.end(); it++)
		q.push(std::pair<std::string, int>(it->first, it->second));
	while (!q.empty())
	{
		std::cout << q.top().first << " => " << q.top().second << std::endl;
		q.pop();
	}
	return 0;
}