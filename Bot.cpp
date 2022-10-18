#include "Overwatch2.h"

Bot::Bot( )
:idBot(""), botname("")
{
        
}

Bot::Bot( const string &botname, const string& idBot,  const vector< string > &availableBots )
{
    this->botname = botname;
    this->idBot = idBot;
    
    this->availableBots.resize( availableBots.size() );
    for( int i = 0; i < this->availableBots.size( ); i++ )
         this->availableBots[ i ] = availableBots[ i ];

    //printAvailableBots( );
}

Bot::Bot( const Bot &botOut )
{
    this->botname = botOut.botname;
    this->idBot = botOut.idBot;

    this->availableBots.resize( botOut.availableBots.size() );
    for( int i = 0; i < this->availableBots.size( ); i++ )
        this->availableBots[ i ] = botOut.availableBots[ i ];
}

Bot::~Bot( )
{

}

 void Bot::printAvailableBots( ) const
 {
     cout << "List of bots:\n";
     for( int i = 0; i < this->availableBots.size( ); i++ )
        cout << this->availableBots[ i ] << '\n';
 }

ostream &operator<<( ostream &out, const Bot &p )
{
    out << "Bot botname: ";
    out << p.botname << "\n";
    
    out << "Bot id: ";
    out << p.idBot << "\n";

    p.printAvailableBots( );

    return out;
}
