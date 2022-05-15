#pragma once
#include <iostream>
#include <string>

using namespace std;

class MyError
{
private:
	string what;
public:
	MyError(string w) :what(w) {}

	string What() { return what; }
};

