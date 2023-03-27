#include <iostream>
#include <string>
using namespace std;

void prefix(string substr, int substrSize, int* pref);

void KMPSearch(string substr, string str)
{
	int strSize = str.size();
	int substrSize = substr.size();

	int* pref =new int[substrSize];

	prefix(substr, substrSize, pref);

	int i = 0; // index for str[]
	int j = 0; // index for substr[]

	while ((strSize - i) >= (substrSize - j)) 
	{
		if (substr[j] == str[i]) 
		{
			j++;
			i++;
		}

		if (j == substrSize) 
		{
			cout << "Ïîäñòðîêà íàøëàñü ïî èíäåêñó:" << i - j << endl;
			j = pref[j - 1];
		}

		else if (i < strSize && substr[j] != str[i]) 
		{
			if (j != 0)
			{
				j = pref[j - 1];
			}
			else
			{
				i = i + 1;
			}
		}
	}
}

void prefix(string substr, int substrSize, int* pref)
{
	int len = 0;

	pref[0] = 0;

	int i = 1;
	while (i < substrSize) 
	{
		if (substr[i] == substr[len]) 
		{
			len++;
			pref[i] = len;
			i++;
		}
		else
		{
			if (len != 0) 
			{
				len = pref[len - 1];
			}
			else
			{
				pref[i] = 0;
				i++;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	string str;
	string substr;
	cout << "Ââåäèòå ñòðîêó: ";
	cin >> str; 
	cout << "Ââåäèòå ïîäñòðîêó,êîòîðóþ õîòèòå íàéòè: ";
	cin >> substr;
	KMPSearch(substr, str);
	return 0;
}