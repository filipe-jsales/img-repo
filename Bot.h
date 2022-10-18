#ifndef BOT_H
#define BOT_H

#include <iostream>
using std::cout;
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Bot
{
    friend ostream &operator<<( ostream &, const Bot & );

public:
    Bot( );
    Bot( const string &, const string &,  const vector< string > & );
    Bot( const Bot & );
    ~Bot( );

    void printAvailableBots( ) const;

private:

    string botname;

    string idBot;

    vector< string > availableBots;

};

#endif // BOT_H
