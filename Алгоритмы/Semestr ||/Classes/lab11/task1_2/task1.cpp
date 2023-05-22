#include <iostream>
#include <vector>
using namespace std;

typedef vector <double> vec;

vec make_vector(int n)
{
	vec v;
	for (int i = 0; i < n; i++)
	{
		double a = (double)(rand() % 100) / (double)100 + (double)(rand() % 100);
		v.push_back(a);
	}
	return v;
}
void print_vector(vec v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
}
double max(vec v)
{
	double m = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		if (m < v[i])
		{
			m = v[i];
		}
	}
	return m;
}
void add_max(vec& v, double el)
{
	v.insert(v.begin(), el);
}
int min(vec v)
{
	double m = v[0];
	int n = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (m > v[i])
		{
			m = v[i];
			n = i;
		}
	}
	return n;
}
void del_min(vec& v, int pos)
{
	v.erase(v.begin()+pos);
}
double srednee(vec v)
{
	double s = 0;
	int n = v.size();
	for (int i = 0; i < v.size(); i++)
	{
		s += v[i];
	}
	return (s / n);
}
void summ_srednee(vec& v, double el)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i] += el;
	}
}

int main1()
{
	srand(time(NULL));
	try
	{
		vector <double> v;
		vector<double>::iterator vi = v.begin();
		int n;
		cout << "N?" << endl;
		cin >> n;
		v = make_vector(n);
		print_vector(v);
		double el = max(v);
		add_max(v, el);
		print_vector(v);
		int pos_min = min(v);
		del_min(v, pos_min);
		print_vector(v);
		el = srednee(v);
		summ_srednee(v, el);
		print_vector(v);
	}
	catch(double)
	{
		cout << "Error!" << endl;
	}
	return 0;
}
