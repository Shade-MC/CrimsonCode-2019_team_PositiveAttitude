#pragma once
#include "node.h"

Node::Node(Node * choice1, Node * choice2, Node * choice3,
	Node * choice4, Node * reverse,Text * text,
	Decision * decision, Combat * combat) {

	this->choice1 = choice1;
	this->choice2 = choice2;
	this->choice3 = choice3;
	this->choice4 = choice4;
	this->reverse = reverse;
	
	this->text = text;
	this->decision = decision;
	this->combat = combat;
	
	this->choice = -1;

}
void Node::runEvent() {
	

	if (text != nullptr) {
		if (this->getC1Ptr() != nullptr && this->getC1Ptr()->decision != nullptr) {
			text->mPrintText();
		}
		else {
			text->mPrintTextP();
		}
		this->choice = 1;
	}
	else if (decision != nullptr) {
		this->choice = decision->makeDecision();
	}
	else if (combat != nullptr) {
		this->choice = combat->motalKombat();
	}
}
Node * Node::next() {
	Node * out = nullptr;
	switch (choice) {
	case 1:
		out = choice1;
		break;
	case 2:
		out = choice2;
		break;
	case 3:
		out = choice3;
		break;
	case 4:
		out = choice4;
		break;
	}
	return out;
}
//setters for pointers to other nodes
void Node::setC1Ptr(Node * node) {
	choice1 = node;
}
void Node::setC2Ptr(Node * node) {
	choice2 = node;
}
void Node::setC3Ptr(Node * node) {
	choice3 = node;
}
void Node::setC4Ptr(Node * node) {
	choice4 = node;
}
void Node::setRPtr(Node * node) {
	reverse = node;
}
//getters for pointers to other nodes
Node *  Node::getC1Ptr() {
	return choice1;
}
Node *  Node::getC2Ptr() {
	return choice2;
}
Node *  Node::getC3Ptr() {
	return choice3;
}
Node *  Node::getC4Ptr() {
	return choice4;
}
Node *  Node::getRPtr() {
	return reverse;
}
//setters for int id's
void Node::setC1(int id) {
	this->c1 = id;
}
void Node::setC2(int id){
	this->c2 = id;
}
void Node::setC3(int id) {
	this->c3 = id;
}
void Node::setC4(int id) {
	this->c4 = id;
}
void Node::setR(int id) {
	this->r = id;
}
void Node::setId(int id) {
	this->id = id;
}
//getters for int id's
int Node::getC1() {
	return c1;
}
int Node::getC2() {
	return c2;
}
int Node::getC3() {
	return c3;
}
int Node::getC4() {
	return c4;
}
int Node::getR() {
	return r;
}
int Node::getId() {
	return id;
}

Node * runNode(Node &node) {
	node.runEvent();
	return node.next();

}
Node * createNodes(std::ifstream &stream,playerCharacter * player) {
	Node * nodes[100] = { nullptr };
	Node * headNode = nullptr;
	char temp[1000] = "";
	char temp1[100] = "";
	char temp2[100] = "";
	char temp3[100] = "";
	char temp4[100] = "";
	char lines[100][1000] = { "" };
	string components[8];

	stream.getline(lines[0], 1000);
	int i = 0, j = 0;

	while (!stream.eof()) {

		nodes[i] = new Node();
		stream.getline(lines[i], 1000);

		j = 0;
		//break each line into component parts
		components[j] =  strtok(lines[i], ",");
		for (j = 1; j < 8; ++j) {
			components[j] = strtok(NULL, ",\n\0");

		}
	//	components[7] = strtok(NULL, ",\n\0");
		//sets number for future node pointing
		nodes[i]->setId(std::stoi(components[0]));
		nodes[i]->setC1(std::stoi(components[3]));
		nodes[i]->setC2(std::stoi(components[4]));
		nodes[i]->setC3(std::stoi(components[5]));
		nodes[i]->setC4(std::stoi(components[6]));
		nodes[i]->setR(std::stoi(components[7]));

		if (std::stoi(components[1]) == 1) {
			Text * text = new Text(components[2]);
			nodes[i]->linkObject(*text);
		}
		else if (std::stoi(components[1]) == 2) {
			strcpy(temp, components[2].c_str());

			strcpy(temp1 , myStrTok(temp, ";"));
			strcpy(temp2, myStrTok(NULL, ";"));
			strcpy(temp3, myStrTok(NULL, ";"));
			strcpy(temp4, myStrTok(NULL, ";"));
			Decision * text = new Decision(temp1,temp2,temp3,temp4);
			nodes[i]->linkObject(*text);
		}
		else {
			Combat * text = new Combat(std::stoi(components[2]), player);
			nodes[i]->linkObject(*text);
		}

		++i;
	}
	headNode = organizeNodes(nodes);
	return headNode;
}

void Node::linkObject(Text &text) {
	this->text = &text;
}

void Node::linkObject(Decision &text) {
	this->decision = &text;
}

void Node::linkObject(Combat &text) {
	this->combat = &text;
}

//Crimson Code Hackathon 2019
//Team: Positive Attitude
//Coded by Gabe Adamson
//Description: The function organizes the linked list in the correct order for our story
Node *organizeNodes(Node *nodes[])
{
	Node *root = nodes[0]; //set root node
	Node *current = 0; //initialize a pointer to point at current node
	for (int index = 0; nodes[index] != nullptr; index++)
	{
		std::queue<Node *> workQueue; //initialize queue
		workQueue.push(root); //push root to front of queue
		current = 0; //set current to 0
		while (!workQueue.empty())
		{
			current = workQueue.front(); //set current to front of queue
			if (current->getC1() == nodes[index]->getId() && current->getC1Ptr() != nodes[index])
			{
				current->setC1Ptr(nodes[index]);
			}
			else if (current->getC2() == nodes[index]->getId() && current->getC2Ptr() != nodes[index])
			{
				current->setC2Ptr(nodes[index]);
			}
			else if (current->getC3() == nodes[index]->getId() && current->getC3Ptr() != nodes[index])
			{
				current->setC3Ptr(nodes[index]);
			}
			else if (current->getC4() == nodes[index]->getId() && current->getC4Ptr() != nodes[index])
			{
				current->setC4Ptr(nodes[index]);
			}
			else
			{
				if (current->getC1Ptr() != nullptr)
				{
					workQueue.push(current->getC1Ptr());
				}
				if (current->getC2Ptr() != nullptr)
				{
					workQueue.push(current->getC2Ptr());
				}
				if (current->getC3Ptr() != nullptr)
				{
					workQueue.push(current->getC3Ptr());
				}
				if (current->getC4Ptr() != nullptr)
				{
					workQueue.push(current->getC4Ptr());
				}
				workQueue.pop();
			}

		}

	}
	return root;
}

char * myStrTok(char * str, char * delim) {
	int found = 0;
	static char *pToken = NULL;
	if (str == NULL) {
		str = pToken + 1;
	}
	
		//std::cout << str << std::endl;
		found = 0;
		int strLen = strlen(str);
		int delimLen = strlen(delim);

		for (int i = 0; i < strLen && !found; ++i) {

			for (int j = 0; j < delimLen && !found; ++j) {

				if (*(str + i) == *(delim + j)) {
					found = 1;
					*(str + i) = '\0';
					pToken = str + i;
					//	return str;
				}
			}
		}
		if (found) {
			return str;
		}
		else {
			return nullptr;
		}
	
}