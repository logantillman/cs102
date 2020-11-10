#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Home
{
	string name;
	string address;
};

class MailingList
{
public:
	void AddHome(const string &name, const string &address);
	void AddHome(const Home &home);
	void PrintList() const;
private:
	vector<Home> homes;	
};

int main()
{
	Home h;
	MailingList l;
	cout << "Enter names and addresses: ";
	while (getline(cin, h.name) && getline (cin, h.address))
	{
		l.AddHome(h);	
	}

	l.PrintList();

return 0;
}

void MailingList::AddHome(const string &name, const string &address)
{
	Home h;
	h.name = name;
	h.address = address;
	homes.push_back(h);
}

void MailingList::AddHome(const Home &h)
{
	homes.push_back(h);
}

void MailingList::PrintList() const
{
	for (const Home &h : homes)
	{
		cout << h.name << '\n' << h.address << "\n\n";
	}
}
