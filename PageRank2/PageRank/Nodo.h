#pragma once
#ifndef NODO_H
#define NODO_H
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

struct Node {

	string Nominacion;
	Node *SIGUIENTEALNODO;
	Node *ANTERIORALNODO;

	Node(string str) :

		Nominacion(str) {
		SIGUIENTEALNODO = 0;
		ANTERIORALNODO = 0;
	}
	

};

#endif NODO_H