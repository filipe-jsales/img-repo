#ifndef OVERWATCH2_H
#define OVERWATCH2_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Player.h"
#include "Bot.h"

#include "Data.h"

class Overwatch2
{
	friend ostream &operator<<( ostream &, const Overwatch2 & );
	
public:
	Overwatch2( );
	Overwatch2( const Overwatch2 &);
	Overwatch2( int, const Data & = Data( 25, 9, 2014) );
	~Overwatch2( );
	
	//A static member function cannot be declared with the keywords virtual, const, volatile, or const volatile.
	static void mostrarInfo( );
	
	void sendMVPToPlayer( const string & );
	
	void listMVPHistory( ) const;
	
	void mostrarData( ) const;

	void printPlayersList( ) const;

	void includePlayer( const Player & );
	void includePlayer( const string &, const string &, const vector< string > & );

	void banLastPLayer( );

	void removeLastMVP( );

	void removeMVPByname( string name);
	
private:

	int unicCode;

	const int IDBATTLENET;
	
	static int copiesSold;
	
	const static Data RELEASEDATE;
	
	vector< string > history;
	
	Data dataAtual;	

	vector< Player * > players;

};

#endif // Overwatch2_H
