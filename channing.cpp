// hashing channing.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>

#include<bits.h>
#include<conio.h>
#include<list>
using namespace std;

class Hash
{
	int Bucket; //no. of buckets

	// Pointer to an array containing buckets
	list <int> *table;
public:
	Hash(int v);// contructor

	//inserts a key into hash table
	void insert_key(int x);

	//deletes a key from hash table
	void delete_key(int key);

	//hash function to map values to keys
	int hash_function(int x)
	{
		return (x % Bucket);
	}

	void display_hash();

};

Hash::Hash(int b)
{
	this->Bucket = b;
	table = new list<int>[Bucket];
}

void Hash::insert_key(int key)
{
	int index = hash_function(key);
	table[index].push_back(key);
}

void Hash::delete_key(int key)
{
	int index = hash_function(key);
	//find the key in (index)th list
	list<int>::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++)
	{
		if (*i == key)
		{
			break;
		}
	}

	//if key is found in hash table. remove it
	if (i != table[index].end())
	{
		table[index].erase(i);
	}
}

//function to display hash table
void Hash::display_hash()
{
	for (int i = 0; i < Bucket; i++)
	{
		cout << i;
		for (auto x : table[i])
		{
			cout<< "-->" << x<<endl;
			
		}
	}
}

//Driver program
int main()
{
	// array that contains keys to be mapped
	int a[] = { 1,3,12,4,25,63,13,23,83 };
	int n = sizeof(a) / sizeof(a[0]);

	//insert the keys into the hash table
	Hash h(10); //10 is the count of buckets in hash table

	for (int i= 0; i < n; i++)
	{
		h.insert_key(a[i]);
	}

	//delete 12 from hash table
	h.delete_key(12);

	//display the hash table
	h.display_hash();

	return 0;
}

//
