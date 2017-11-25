//Jos� Luis Ruiz Benito. FP. 1� DGIIM

//Estupendo programa que nos pone una fecha num�rica en formato extendido.

#include <iostream>
using namespace std;


/**
	@brief Eval�a si un a�o es bisiesto.
	@param year: a�o que se eval�a.
	@return true si el a�o el bisiesto, false en otro caso.
*/
bool Bisiesto(int year)
{
	bool bisiesto = (year%4==0 && year%100!=0) || year%400==0;
	
	return bisiesto;
}


/**
	@brief  Calcula el d�a juliano astron�mico de una fecha.
	@param day: d�a
	@param month: mes
	@param year: a�o
	@return D�a juliano astron�mico de la fecha.
*/
int Juliano(int day, int month, int year)
{
	int juliano = ( 1461 * ( year + 4800 + ( month - 14 ) / 12 ) ) / 4 + ( 367 * ( month - 2 - 12 * ( ( month - 14 ) / 12 ) ) ) / 12 -	( 3 * ( ( year + 4900 + ( month - 14 ) / 12 ) / 100 ) ) / 4 + day - 32075;
	
	return juliano;
}


/**
	@brief Devuelve un car�cter que codifica el d�a de la semana.
	@param day: d�a (d�a del mes)
	@param month: mes
	@param year: a�o
	@return Car�cter que identifica el d�a de la semana ('L', 'M', 'X', 
	'J', 'V', 'S', 'D').
	
	El car�cter codifica el d�a de la semana, de acuerdo con la siguiente equivalencia:
		'L': Lunes, 'M': Martes, 'X': Mi�rcoles, 'J': Jueves, 'V': Viernes, 'S': S�bado, 'D': Domingo.
		
*/
char DiaSemana(int day, int month, int year)
{
	char dia;
	
	int codigo = Juliano(day, month, year) % 7;
	
	switch(codigo)
	{
		case 0:
			dia='L';
			break;
		
		case 1:
			dia='M';
			break;
			
		case 2:
			dia='X';
			break;
			
		case 3:
			dia='J';
			break;
			
		case 4:
			dia='V';
			break;
			
		case 5:
			dia='S';
			break;
			
		case 6:
			dia='D';
			break;
	}
	
	return dia;
}


/**
	@brief Eval�a si una fecha es v�lida.
	@param day: d�a
	@param month: mes
	@param year: a�o
	@return true si la fecha es v�lida, false en otro caso.
*/
bool FechaValida(int day, int month, int year)
{
	bool fecha_valida=true;
	bool d_ok, m_ok, a_ok; //verdaderas si el d�a, el mes y el a�o son correctos
	
	a_ok= year>0;
	m_ok= month>0 && month<=12;

	d_ok=true;
	
	if (day<1 || day > 31)
	{
		d_ok=false;
	}
	else
	{
		if(month==2 || month==4 || month== 6 || month==9 || month==11)
		{
			if(day>30)
			{
				d_ok=false;
			}
			else
			{
				if(month==2 && day>29)
				{
					d_ok=false;
				}
				else
				{
					if (day==29 && !Bisiesto(year))
					{
						d_ok=false;
					}
				}
			}
		}
		
	}
		
	fecha_valida = d_ok && m_ok && a_ok;

	return fecha_valida;
}

/**
	@brief Imprime fecha en formato extendido
	@param day: d�a
	@param month: mes
	@param year: a�o
	@return fecha en formato "<D�a_de_la_semana>, <d�a> de 
	<nombre_del_mes> de <a�o>"

	Ejemplo: Jueves, 19 de marzo de 1812.
*/
void Escribir(int day, int month, int year)
{
	switch( DiaSemana(day, month, year) )
	{
		case 'L':
			cout << "Lunes, ";
			break;
			
		case 'M':
			cout << "Martes, ";
			break;
			
		case 'X':
			cout << "Mi�rcoles, ";
			break;
			
		case 'J':
			cout << "Jueves, ";
			break;
			
		case 'V':
			cout << "Viernes, ";
			break;
			
		case 'S':
			cout << "S�bado, ";
			break;
			
		case 'D':
			cout << "Domingo, ";
			break;
	}
	
	cout << day << " de ";
	
	switch(month)
	{
		case 1:
			cout << "Enero";
			break;
			
		case 2:
			cout << "Febrero";
			break;
			
		case 3:
			cout << "Marzo";
			break;
			
		case 4:
			cout << "Abril";
			break;
			
		case 5:
			cout << "Mayo";
			break;
			
		case 6:
			cout << "Junio";
			break;
			
		case 7:
			cout << "Julio";
			break;
			
		case 8:
			cout << "Agosto";
			break;
			
		case 9:
			cout << "Septiembre";
			break;
			
		case 10:
			cout << "Octubre";
			break;
			
		case 11:
			cout << "Noviembre";
			break;
			
		case 12:
			cout << "Diciembre";
			break;
	}
	
	cout << " de " << year << "." << endl;
}

/**
	@brief Lee y asigna valores a day, month, year
	@param day: d�a
	@param month: mes
	@param year: a�o
*/
void Leer(int &day, int &month, int &year)
{
	cout << "Introduzca una fecha (d�a mes a�o): ";
	cin >> day >> month >> year;
	
	while( FechaValida(day, month, year)==false )
	{
		cout << "Fecha no v�lida. Introuducir de nuevo: ";
		cin >> day >> month >> year;
	}
}

int main()
{
	int day, month, year;
	
	Leer(day, month, year);
	
	Escribir(day, month, year);
}

