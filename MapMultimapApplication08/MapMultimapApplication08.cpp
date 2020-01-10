//    multimap
#include <map>
#include <iostream>
#include <functional>

using namespace std;

template<class T> void print(T start, T end) {
	while (start != end) {
		std::cout << start->first << ":" << start->second << " "; start++;
	}
}

template<class T, class U> void fillMap(multimap<T, T>& m, U start, U end)
{
	for (; start != end; ++start)
	{
		m.insert(pair<T, T>(*start, *start));
	}
}


int main()
{
	int t[] = { 16, 10, 8, 40, 6, 15, 3, 9, 7, 2 };
	multimap<int, int> m1;
	fillMap(m1, t, t + 10);

	print(m1.begin(), m1.end()); cout << endl;
	cout << "The first version of insert: inserting a duplicate key 10 \n";
	multimap<int, int>::iterator it1 = m1.insert(pair<int, int>(10, 10));
	print(m1.begin(), m1.end()); cout << endl << endl;
	cout << "Inserting non duplicate - neither key nor value:\n";
	it1 = m1.insert(pair<int, int>(13, 13));
	print(m1.begin(), m1.end()); cout << endl << endl;

	cout << "The second version of insert:\n";
	it1 = m1.insert(m1.find(10), pair<int, int>(11, 11));
	multimap<int, int>::iterator it2 = m1.insert(m1.find(11), pair<int, int>(11, 11));
	if (it1 == it2) {
		cout << "Insert was not successful\n";
	} else {
		cout << "Insert was successful\n";
	}
	print(m1.begin(), m1.end()); cout << endl << endl;

	cout << "The third version of insert:\n";
	int t2[] = { 4,10,15,21,0 };
	multimap<int, int> m2;
	fillMap(m2, t2, t2 + 5);
	m1.insert(m2.begin(), m2.end());
	print(m1.begin(), m1.end()); cout << endl;

	return 0;
}