//Crimson Code Hackathon 2019
//Team: Positive Attitude
//Coded by Gabe Adamson
//Description: The function organizes the linked list in the correct order for our story

#include <iostream>
#include <queue>
#include "Node.h"

Node *organizeNodes(Node *nodes[]);


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
			if (current->getC1() == nodes[index]->getId())
			{
				current->setC1Ptr(nodes[index]);
				break;
			}
			else if (current->getC2() == nodes[index]->getId())
			{
				current->setC2Ptr(nodes[index]);
				break;
			}
			else if (current->getC3() == nodes[index]->getId())
			{
				current->setC3Ptr(nodes[index]);
				break;
			}
			else if (current->getC4() == nodes[index]->getId())
			{
				current->setC4Ptr(nodes[index]);
				break;
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