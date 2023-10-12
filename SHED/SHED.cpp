#include <iostream>
using namespace std;

class Set
{
private:
	int* set;
	int size;
public:
	Set(int _size)
	{
		size = _size;
		set = new int[size];
		for (int i = 0; i < size; i++)
		{
			if (rand() % 2 == 1)
			{
				set[i] = rand() % 100;
			}
			else
			{
				i--;
			}
		}
		uniqCheck();
	}

	explicit Set(const Set& _obj)
	{
		size = _obj.size;
		set = new int[size];

		for (int i = 0; i < size; i++)
		{
			set[i] = _obj.set[i];
		}
	}

	Set() : Set(10) {}

	void uniqCheck()
	{
		int* arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = set[i];
			for (int j = 0; j < i; j++)
			{
				if (set[i] == arr[j])
				{
					for (int z = 0; z < size; z++)
					{
						if (rand() % 2 == 1)
						{
							set[z] = rand() % 100;
						}
						else
						{
							z--;
						}
					}
				}
			}
		}
	}


	void elemCheck(int x)
	{
		for (int i = 0; i < size; i++)
		{
			if (set[i] == x)
			{
				cout << "Элемент принадлежит множеству" << endl;
				return;
			}
		}
		cout << "Элемент не принадлежит множеству" << endl;
	}
	friend ostream& operator<< (ostream& out, Set& _set);
	friend istream& operator>> (istream& in, Set& _set);
	/*~Set()
	{
		if (set != nullptr)
		{
			delete[]set;
		}
	}*/
};

ostream& operator<< (ostream& out, Set& _set)
{
	out << "Множество: {";
	for (int i = 0; i < _set.size; i++)
	{
		out << _set.set[i] << ", ";
	}
	out << "}\n";
	return out;
}

istream& operator>> (istream& in, Set& _set)
{
	for (int i = 0; i < _set.size; i++)
	{
		in >> _set.set[i];
	}
	return in;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "RUS");
	Set s1{};

	cout << s1;
	cin >> s1;
	cout << s1;

}
