#ifndef DRAFT_H
#define DRAFT_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include "nodedata.h"
#include "team.h"
#include <unistd.h>
#include <ncurses.h>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

class Draft{
	private:
		struct LinkNode{
			LinkNode *next;
			NodeData *pick;
		};
		LinkNode *head;
		int numTeams;
		unsigned int compTime;
		unsigned int userTime;

	public:
		Draft();
		~Draft();

		//getters setters
		void setNum(int);
		int getNum();

		//board functions
		void pickTime(); 
		void startDraft(Team *arr, vector<NodeData*>&, int, WINDOW **board);
		void makeBoard(Team *arr, vector<NodeData*>&, int);
		void newRound();
		void autoP(Team, vector<NodeData*>&, WINDOW **board, int pick);
		void toBoard(Team team, NodeData *player, WINDOW **board, int pick);

		void pick(Team &, vector<NodeData*>&, WINDOW **board, int pick);
		void nextTen(vector<NodeData*>&, WINDOW **board);

		//List functions
		void insertEnd(NodeData*);
		void displayList();
		bool editNode(NodeData*);

		//curses functions
		void destroy_win(WINDOW *);
		WINDOW *createWin(int, int, int, int);
		char *toCharArr(NodeData *a);
		char *toChar2(NodeData *a);


};

#endif