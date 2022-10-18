#include "Overwatch2.h"
#include <iostream>
using std::cout;

int Overwatch2::copiesSold = 0;

const Data Overwatch2::RELEASEDATE = Data( 13, 10, 2022 );

Overwatch2::Overwatch2( )
:unicCode(0), IDBATTLENET( 12345 ), dataAtual( )
{
	copiesSold++;	
}

Overwatch2::Overwatch2( int IDBattlenet, const Data &dataOut )
:IDBATTLENET(IDBattlenet), dataAtual(dataOut)
{
	copiesSold++;	
}

//copy constructor
Overwatch2::Overwatch2( const Overwatch2 &sp )
:unicCode(sp.unicCode), IDBATTLENET(sp.IDBATTLENET), dataAtual(sp.dataAtual)
{
	history = sp.history;
	copiesSold++;
	
	//Update contact list
	players.resize( sp.players.size( ) );
	for( int i = 0; i < players.size( ); i++ )
		players[ i ] = new Player( *sp.players[ i ] );

}

Overwatch2::~Overwatch2( )
{

	for( int i = 0; i < players.size( ); i++ )
		delete players[ i ];

}

void Overwatch2::mostrarInfo( )
{
	cout << "A data de lancamento deste modelo eh: ";
	RELEASEDATE.print( );
	cout << '\n';
	cout << "O numero de Overwatch2 vendidos eh: " << copiesSold << '\n'; 
		 
}

void Overwatch2::sendMVPToPlayer(const string &newPage)
{
	history.push_back( newPage );
}

void Overwatch2::removeLastMVP()
{
	cout << "Deleting MVP for " <<history.back() <<  "...\n";
	history.pop_back(  );
}

void Overwatch2::removeMVPByname( string name)
{
	bool found = false;
	// Iterate over all elements in Vector
	for (auto & elem : history)
	{
		if (elem == name)
		{
			found = true;
			break;
		}
	}
	if(found)
	{
		std::cout << "Player Found: " << name << "\n";
		cout << "Deleting MVP for player" <<history.back() <<  "...\n";
		history.pop_back(  );
	}
	else
    	std::cout << "Element Not Found" << "\n";
}

void Overwatch2::listMVPHistory( ) const
{
	cout << "Lista de MVP dados: \n";
	for( unsigned int i = 0; i < history.size( ); i++ )
		cout << history[ i ] << '\n';
}

void Overwatch2::mostrarData( ) const
{
	cout << "A data atual eh: "; dataAtual.print( );	
	cout << '\n';
}

void Overwatch2::printPlayersList( ) const
{
	cout << "Lista de jogadores de Overwatch 2:\n\n";
	for( int i = 0; i < players.size( ); i++ )
		cout << *players[ i ] << '\n';
}

void Overwatch2::includePlayer( const Player &newcontact )
{
	players.push_back( new Player( newcontact ) );	
}

void Overwatch2::includePlayer( const string &name, const string &phoneNumber, const vector< string > &socialMediaConection )
{
	players.push_back( new Player( name, phoneNumber, socialMediaConection ) );	
}

void Overwatch2::banLastPLayer( )
{
	delete players[ players.size() - 1 ];
	players.pop_back( );
}

ostream &operator<<( ostream &out, const Overwatch2 &ow2 )
{
    out << "Data de lancamento do jogo: ";
	ow2.RELEASEDATE.print( );
	out << '\n';
	out << "A quantidade de copias de Overwatch2s vendidas eh: " << ow2.copiesSold << '\n'; 

	out << "Minha lista de amigos eh:\n\n";
	for( int i = 0; i < ow2.players.size( ); i++ )
		out << *ow2.players[ i ] << '\n';

    return out;
}