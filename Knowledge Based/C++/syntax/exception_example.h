#pragma once
#include <iostream>
#include <exception>

using namespace std;

class MyException: public exception
{
	const char* what() const throw() {
		return "My exception happened";
	}
} myException;

int function() {
	try {
		throw myException;
		throw 20;
	} catch (int e) {
		cout << "An exception occurred. Exception Nr. " << e << '\n';
	}  catch (exception& e) {
		cout << e.what();
	}

	return 0;
}
