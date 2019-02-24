/*
	Crimson Code Hackathon 2019
	Team: Positive Attitude
	Coded by Eric Curtland

	Nodes for text based adventture game that wiil serve to connect each event

*/

#pragma once
#include "combat.h"


using std::string;


class Node{
public:
	Node(Node * choice1 = nullptr, Node * choice2 = nullptr,	Node * choice3 = nullptr,
		Node * choice4 = nullptr,Node * reverse = nullptr
	,Text * text= nullptr, Decision * decision= nullptr, Combat * combat= nullptr);
	void runEvent();
	Node * next();

	void setC1Ptr(Node * node);
	void setC2Ptr(Node * node);
	void setC3Ptr(Node * node);
	void setC4Ptr(Node * node);
	void setRPtr(Node * node);
	Node * getC1Ptr();
	Node * getC2Ptr();
	Node * getC3Ptr();
	Node * getC4Ptr();
	Node * getRPtr();

	
	void linkObject(Text &text);
	void linkObject(Decision &text);
	void linkObject(Combat &text);

	void setC1(int id);
	void setC2(int id);
	void setC3(int id);
	void setC4(int id);
	void setR(int id);
	void setId(int id);
	int getC1();
	int getC2();
	int getC3();
	int getC4();
	int getR();
	int getId();

private:
	Text * text;
	Decision * decision;
	Combat * combat;
	int c1;
	int c2;
	int c3;
	int c4;
	int r;
	int id;
	int choice;
	Node * choice1;
	Node * choice2;
	Node * choice3;
	Node * choice4;
	Node * reverse;
};
Node * runNode(Node &node);

Node * createNodes(std::ifstream &stream,playerCharacter *player);

Node *organizeNodes(Node *nodes[]);

char * myStrTok(char * str, char * delim);