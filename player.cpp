#include "player.h"

Player::Player(){
	posit = squad = first = last = "";
	rank = 0;
}

int Player::getRank(){
	return rank;
}

NodeData* Player::makeFromStream(istream& in){
	in >> rank;
	in.get();
	in.get();
	getline(in, squad, ' ');
	getline(in, posit, ' ');
	getline(in, first, ' ');
	getline(in, last, '\n');
	NodeData* john = new NodeData(rank, first, last, squad, posit);
    return john;
}

void Player::toPlayer(NodeData* change){
	posit = change->getPosition();
	squad = change->getSquad();
	first = change->getFirst();
	last = change->getLast();
	rank = change->getRank();
}

string Player::playerInfo(){
	return first + " " + last + "      " + squad;
}