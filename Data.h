/* 
 * File:   Data.h
 * Author: Cssj
 *
 * Created on 9 de Junho de 2012, 14:47
 */

#ifndef DATA_H
#define	DATA_H

class Data 
{
public:
    
    Data( int = 1, int = 1, int = 1900 );
    
    void print() const;
    
    struct Util{
        const static int JANEIRO =1;
        const static int FEVEREIRO =2;
        const static int MARCO =3;
        const static int ABRIL =4;
        const static int MAIO =5;
        const static int JUNHO =6;
        const static int JULHO =7;
        const static int AGOSTO =8;
        const static int SETEMBRO =9;
        const static int OUTUBRO =10;
        const static int NOVEMBRO =11;
        const static int DEZEMBRO =12;

        int data;
        Util& operator=(Util& a)
        {
            return a;
        }
        Util& operator=(int a)
        {
            data = a;
            return *this;
        }
        Util& operator==(Util& a)
        {
            return a;
        }
        Util& operator==(int a)
        {
            data = a;
            return *this;
        }
        Util& operator!=(Util& a)
        {
            return a;
        }
        Util& operator!=(int a)
        {
            data = a;
            return *this;
        }
        void operator!()
        {
            cout << "Void operator !()" << "\n";
        }
private:
    };
    
    int mes;
    int dia;
    int ano;
    
    int VerificaDia( int ) const;


};
// enum class Meses;
#endif	/* DATA_H */

