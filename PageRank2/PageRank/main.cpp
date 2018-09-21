
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <string>
#include <cstring>
#include "Nodo.h"
#include "Listas.h"	

using namespace std;




void INSALALISTA(Node *&BODYS,  string NEWONE) {

	Node *NODEJCRE = new Node(NEWONE);
	if (BODYS == 0) {BODYS = NODEJCRE; return;}
	Node *tmp = BODYS; Node *before = tmp;
	while (tmp->SIGUIENTEALNODO != 0) {before = tmp; tmp = tmp->SIGUIENTEALNODO;}
	NODEJCRE->ANTERIORALNODO = before;
	tmp->SIGUIENTEALNODO = NODEJCRE;
}

Node* LISTAADYACENCIA[20]; 

void SEARCHINSALALISTA(const string &INFORMACIONESPECIAL, char * PALABRACLAVE, string DATOSDDENTRODELISTA, int CONTEO) {

	ifstream FILES; dirent *ENTRADADATOS; string EL; char href[30];
	char *VAPLCLASE = new char[strlen(PALABRACLAVE)];
	strcpy_s(VAPLCLASE, strlen(PALABRACLAVE) + 1, PALABRACLAVE);
	if (INFORMACIONESPECIAL.find(VAPLCLASE) != string::npos) {cout << DATOSDDENTRODELISTA;cout << "\n";}
	if (DIR *direccionamiento = opendir("C:\\Users\\FLORENTINO GARCIA\\Desktop\\PageRank")) {
		while (dirent *ENTRADADATOS = readdir(direccionamiento)) {	EL = ENTRADADATOS->d_name;
			if (EL != "." && EL != "..") { if (INFORMACIONESPECIAL.find(VAPLCLASE) != string::npos) { if (INFORMACIONESPECIAL.find(EL) != string::npos) {
						cout << DATOSDDENTRODELISTA << "Points to " << EL << "\n";
						INSALALISTA(LISTAADYACENCIA[CONTEO], EL); }}FILES.close();}}closedir(direccionamiento);}
}
void READING(char *PALABRACLAVE) {
	ifstream FILES;dirent *ENTRADAYDALIDA;string DATOS; int CONTEO = 0;
	char * Nominaciones = new char[strlen(PALABRACLAVE)]; 
	strcpy_s(Nominaciones, strlen(PALABRACLAVE) + 1, PALABRACLAVE);
	if (DIR*direccionamiento = opendir("C:\\Users\\FLORENTINO GARCIA\\Desktop\\PageRank"))	{while (ENTRADAYDALIDA = readdir(direccionamiento)) {DATOS = ENTRADAYDALIDA->d_name;if (DATOS != "." && DATOS != "..") {
				FILES.open("C:\\Users\\FLORENTINO GARCIA\\Desktop\\PageRank//" + DATOS, ios::in);

				if (!FILES) {cerr << "No se pudo encontrar el archivo que se necesita :I "; return;}
				LISTAADYACENCIA[CONTEO] = new Node(DATOS);
				while (!FILES.eof()) {string GETGA, contenido; while (getline(FILES, GETGA)) {contenido += GETGA + "\n";}
					SEARCHINSALALISTA(contenido, Nominaciones, DATOS, CONTEO); CONTEO++;
					FILES.close();}}}closedir(direccionamiento);} cout << endl; }

void IMPRIMIRLISTACONSOLEMODE() {

	cout << " ***** PRINTING LIST ****** \n\n";
	for (int i = 0; i < 20; i++) {
		Node *tmp = LISTAADYACENCIA[i];
	if (tmp != 0) { while (tmp != 0) {
				cout << tmp->Nominacion << "-> ";
				tmp = tmp->SIGUIENTEALNODO;
			}
			cout << endl << "  |" << endl << (char)2304 << endl;}}}


void WRITINGTESTO() {
	double pr = 0;
	ofstream archivoOut("GOOGLES.html", ios::out);
	if (!archivoOut) {
		cout << "No se pudo abrir el archivo";
		return;
	}
	for (int i = 0; i < 20; i++) {
		Node *tmp = LISTAADYACENCIA[i];
		if (tmp != 0) {
			while (tmp != 0) {
				archivoOut << "<li>" << "Pagina: " << tmp->Nominacion << "      PR: "<< pr <<"</li>";
				tmp = tmp->SIGUIENTEALNODO;
			}
		}
	}

	archivoOut.close();
}











int main() {
	Listas linked;
	
	for (int i = 0; i < 20; i++) //Inicializar todos en 0
	
	
		LISTAADYACENCIA[i] = 0; 
	char  nombre[30] ;
	cout << "Ingrese la keyword: " << endl;
	cin >> nombre;
	READING(nombre);
	IMPRIMIRLISTACONSOLEMODE();
	system("pause");


}










































/*#include "Pages.h"
#include <iostream>
using namespace std;

int main()
{
	Pages n;
	stringvec v;

	n.read_directory("C:\\Users\\FLORENTINO GARCIA\\Desktop\\Universidad\\UNITEC\\Programación III\\Parcial I.I\\ProyectoII\\PageRank", v);
	copy(v.begin(), v.end(),ostream_iterator<string>(cout,"\n"));

	/*int option;
	cout << "**************** P A G E R A N K     M E N U ****************" << endl;
	cout << "1.Busqueda de paginas" << endl;
	cout << "2. Salir" << endl;
	cout << "Ingrese una opcion de acuerdo a su numeración; ";
	
	cin >> option;
	do
	{
		
		switch (option)
		{
		case 1:

			
			n.read_directory("C:\\Users\\FLORENTINO GARCIA\\Desktop\\Universidad\\UNITEC\\Programación III\\Parcial I.I\\ProyectoII\\PageRank",v);
			break;
		case 2:
			break;

	
		}






	} while (option != 2);



	*/
/*
	system("pause");
}
*/