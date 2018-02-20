/*
Haz un programa que lea de la entrada est�ndar el n�mero de elementos que tendr� un array de enteros, y dos enteros para el rango (m�nimo, m�ximo) de posibles valores que
tomar�n los elementos del array. El programa rellenar� el array con n�meros aleatorios enteros en el rango proporcionado, y posteriormente lo mostrar� en la salida est�ndar.
Autor: Manuel Gachs Ballegeer
*/

#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

/**
	@brief: Rellena un array con valores pseudoaleatorios.
	@param a_enteros: Array a rellenar. ES MODIFICADO
	@param n_elementos: N� de elementos a rellenar.
	@param min: M�nimo de los posibles valores del array.
	@param max: M�ximo de los posibles valores del array.
*/
void generarArray(int a_enteros[], int n_elementos, int max, int min);

/**
	@brief: Muestra en la salida est�ndar los componentes de un array y su numero de elementos.
	@param a_enteros: Array a mostrar.
	@param n_elementos: N� de elementos del array.
*/
void imprimirArray(const int a_enteros[], int n_elementos);

void generarArray(int a_enteros[], int n_elementos, int max, int min) {
	
	srand((int) time(0));
	
	for (int i=0; i<n_elementos-1;i++) {
		
		int aux = rand() % max + min;
		a_enteros[i] = aux;
	}
}

void imprimirArray(const int a_enteros[], int n_elementos) {
	
	cout << "\nNumero de elementos: " << n_elementos << endl;
	
	for (int i=0; i<n_elementos-1; i++)
		cout << a_enteros[i] << " ";
}

int main(int argc, char* argv[]) {
	
	int min, max, n_elementos;
	
	cout << "Introduce el numero de elementos: ";
	cin >> n_elementos;
	
	static_cast<const int> (n_elementos);
	int a_enteros[n_elementos];
	
	do{
		
		cout << "Introduce el minimo y el maximo de posibles valores: ";
		cin >> min >> max;
	}while(max<min);
	
	generarArray(a_enteros,n_elementos,max,min);
	imprimirArray(a_enteros,n_elementos);
	
}
