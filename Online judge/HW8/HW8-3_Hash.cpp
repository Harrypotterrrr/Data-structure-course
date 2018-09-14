#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#define SUCCESS 1
#define UNSUCCESS 0
#define OK 1
#define ERROR 0
#define Hashtable_SIZE 1000
#define SIGN 0
#define prime 11
using namespace std;
typedef int Status;
template<typename T>
class HashTable
{
public:
	T * elem;
	int count;
	int length;

	Status InitialHashtable()
	{
		cin >> count >> length;
		elem = new T[length + 1];
		memset(elem, 0, sizeof(T)*(length + 1));
		return OK;
	}
	int Hash(T key)
	{
		int len = key.length();
		int addr = 0;
		for (int i = 0, j = 1; i < len; i++, j *= 37) {
			addr += key[i] * j;
		}
		return addr % length;
	}
	void InsertHash(T key)
	{
		int addr = Hash(key);
		while (elem[addr] != T(SIGN + '0')) {
			addr = (addr + 1) % length;
		}
		elem[addr] = key;
	}
	Status SearchHash(T key)
	{
		int addr = Hash(key);
		while (elem[addr] != key) {
			addr = (addr + 1) % length;
			if (elem[addr] == T(SIGN+'0') || addr = Hash(key)) {
				cout << "-1\n";
				return UNSUCCESS;
			}
		}
		cout << addr << " ";
		return SUCCESS;
	}
	Status CountSearchHash(T key)
	{
		int addr = Hash(key);
		int num = 1;
		while (elem[addr] != key) {
			addr = (addr + 1) % length;
			num++;
			if (elem[addr] == T(SIGN + '0') || addr = Hash(key)) {
				cout << "-1\n";
				return UNSUCCESS;
			}
		}
		cout << num << " ";
		return SUCCESS;
	}
};
int main()
{
	HashTable<string> ht;
	vector<string> V;
	int N, P;
	string key;
	ht.InitialHashtable();
	for (int i = 0; i < ht.count; i++) {
		cin >> key;
		V.push_back(key);
		ht.InsertHash(key);
	}
	for (int i = 0; i < ht.count; i++)
		ht.SearchHash(V[i]);
	for (int i = 0; i < ht.count; i++)
		ht.CountSearchHash(V[i]);
	return 0;
}