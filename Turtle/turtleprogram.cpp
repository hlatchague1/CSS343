/**
 * Implementation file for TurtleProgram
 *
 * @author Hadassah Latchague
 * @date 10/06/2019
 */

#include <cassert>
#include <iostream>
#include "turtleprogram.h"

TurtleProgram::TurtleProgram() {
	ArrayOfCommands = new string[0];
}

TurtleProgram::TurtleProgram(const string& Command) {
	ArrayOfCommands = new string[1]{ Command };
	Length = 1;
}

TurtleProgram::TurtleProgram(const string& Command, const string& Times) {
	ArrayOfCommands = new string[2]{ Command, Times };
	Length = 2;
}

//copy constructor
TurtleProgram::TurtleProgram(const TurtleProgram& Tp) {
	Length = Tp.Length;
	ArrayOfCommands = new string[Length];
	for (int I = 0; I < Length; ++I) {
		setIndex(I, Tp.ArrayOfCommands[I]);
	}
}

// accessors
int TurtleProgram::getLength() const {
	return Length;
}

string TurtleProgram::getIndex(const int& I) const {
	return ArrayOfCommands[I];
}

// mutators
void TurtleProgram::setIndex(const int& I, const string& Str) {
	ArrayOfCommands[I] = Str;
}

// equality
bool TurtleProgram::operator!=(const TurtleProgram& Rhs) const {
	for (int I = 0; I < Rhs.getLength(); ++I) {
		if (Rhs.ArrayOfCommands[I] != ArrayOfCommands[I])
			return true;
	}
	return false;
}

bool TurtleProgram::operator==(const TurtleProgram& Rhs) const {
	if (Rhs.ArrayOfCommands->empty() && ArrayOfCommands->empty()) {
		return true;
	}
	for (int I = 0; I < Rhs.getLength(); ++I) {
		if (Rhs.ArrayOfCommands[I] == ArrayOfCommands[I])
			return true;
	}
	return false;
}

// + and +=
TurtleProgram TurtleProgram::operator+(const TurtleProgram& Tp) const {
	TurtleProgram Bigger = *this;
	Bigger += Tp;
	return Bigger;
}

TurtleProgram& TurtleProgram::operator+=(const TurtleProgram& Tp) {
	int TempSize = Length + Tp.getLength();
	auto* Temp = new string[TempSize];
	for (int I = 0; I < Length; ++I) {
		Temp[I] = ArrayOfCommands[I];
	}
	for (int I = Length; I < TempSize; ++I) {
		Temp[I] = Tp.ArrayOfCommands[I - Length];
	}
	delete[] ArrayOfCommands;
	ArrayOfCommands = Temp;
	Length = TempSize;
	return *this;
}

// * and *=
TurtleProgram TurtleProgram::operator*(const int& Times) const {
	assert(Times > 0 && "Cannot multiply TurtleProgram object by a negative number!");
	TurtleProgram Bigger = *this;
	Bigger *= Times;
	return Bigger;
}

TurtleProgram& TurtleProgram::operator*=(const int& Times) {
	assert(Times > 0 && "Cannot multiply TurtleProgram object by a negative number!");
	int OriginalLength = Length;
	Length *= Times;
	auto* Temp = new string[Length];
	int OriginalIndex = 0;
	for (int I = 0; I < Length; ++I) {
		if (OriginalIndex >= OriginalLength) {
			OriginalIndex = 0;
		}
		Temp[I] = ArrayOfCommands[OriginalIndex++];
	}
	delete[] ArrayOfCommands;
	ArrayOfCommands = Temp;
	return *this;
}

TurtleProgram& TurtleProgram::operator=(const TurtleProgram& Rhs) { // copy assignment
	if (&Rhs == this) {
		return *this;
	}
	string* Temp = ArrayOfCommands;
	Length = Rhs.Length;
	ArrayOfCommands = new string[Length];
	for (int I = 0; I < Rhs.Length; ++I) {
		setIndex(I, Rhs.ArrayOfCommands[I]);
	}
	delete[] Temp;
	return *this;
}

TurtleProgram::~TurtleProgram() {
	delete[] ArrayOfCommands;
}

// --------------------------------------------------------------------------
// operator<<
// Overloaded output operator for class Array
ostream& operator<<(ostream& Out, const TurtleProgram& Tp) {
	if (Tp.Length == 0)
		return Out << "[]" << endl;
	Out << "[" << Tp.ArrayOfCommands[0];
	for (int I = 1; I < Tp.getLength(); ++I) {
		Out << " " << Tp.ArrayOfCommands[I];
	}
	return Out << "]";
}
