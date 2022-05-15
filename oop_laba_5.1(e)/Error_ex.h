#include <iostream>
#include <string>
#include <exception>;

using namespace std;

#pragma once
class Error_ex : public exception
{
	string message;
public:
	Error_ex(string msg) :message(msg) {}

	string What() { return message; }
};

