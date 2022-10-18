#include "Overwatch2.h"



Player::Player( )
:verifiedEmail(""), name("")
{
        
}

Player::Player( const string &name, const string& verifiedEmail,  const vector< string > &socialMediaConection )
{
    this->name = name;
    this->verifiedEmail = verifiedEmail;
    
    this->socialMediaConection.resize( socialMediaConection.size() );
    for( int i = 0; i < this->socialMediaConection.size( ); i++ )
         this->socialMediaConection[ i ] = socialMediaConection[ i ];

}

Player::Player( const Player &playerOut )
{
    this->name = playerOut.name;
    this->verifiedEmail = playerOut.verifiedEmail;

    this->socialMediaConection.resize( playerOut.socialMediaConection.size() );
    for( int i = 0; i < this->socialMediaConection.size( ); i++ )
        this->socialMediaConection[ i ] = playerOut.socialMediaConection[ i ];
}

Player::~Player( )
{

}

void Player::printSocialConnection( ) const
{
    cout << "Socials connected to blizzard:\n";
    for( int i = 0; i < this->socialMediaConection.size( ); i++ )
    cout << this->socialMediaConection[ i ] << '\n';
}

void Player::setTimeSpent(float timeSpent)
{
    this->timeSpent = timeSpent;
}

float Player::getTimeSpent( ) const
{
    return this->timeSpent;
}

ostream &operator<<( ostream &out, const Player &p )
{
    out << "Player Name: ";
    out << p.name << "\n";
    
    out << "Email connected: ";
    out << p.verifiedEmail << "\n";

    p.printSocialConnection( );

    return out;
}



