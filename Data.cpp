/* 
 * File:   Data.cpp
 * Author: Cssj
 * 
 * Created on 9 de Junho de 2012, 14:47
 */

#include "Data.h"

#include <iostream>
using std::cout;

Data::Data(int day, int month, int year) 
{
    int janeiro =  Data::Util::JANEIRO;

    int dezembro =  Data::Util::DEZEMBRO;

    if ( month > janeiro && month <= dezembro ) // validate month
        this->mes = month;
    
    if ( year < 0 )
        this->ano = 1900;
    else
        this->ano = year;
   
    dia = VerificaDia(day);

}

void Data::print() const
{
   cout << dia << '/' << mes << '/' << ano;
   
}

int Data::VerificaDia(int inputDay) const
{
    if (inputDay < 0)
        throw std::invalid_argument( "received negative value" );

    static const int diasPorMes[ 13 ] = 
       { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if ( inputDay > 0 && inputDay <= diasPorMes[ mes ] )
        return inputDay;

    throw std::invalid_argument( "Date not accepted, try using a valid date" );
    // cout << "Dia invalido (" << inputDay << ") configurado para 1.\n";
    return 1; 


}





