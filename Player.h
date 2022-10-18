#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using std::cout;
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Player
{
    friend ostream &operator<<( ostream &, const Player & );

public:
    Player( );
    Player( const string &, const string &,  const vector< string > & );
    Player( const Player & );
    ~Player( );

    float getTimeSpent( ) const;
    void setTimeSpent( float );
    void printSocialConnection( ) const;
    // void setStatus( const string &) const;
private:

    string name;

    string verifiedEmail;

    vector< string > socialMediaConection;
    
    float timeSpent;
};

#endif // PLAYER_H
