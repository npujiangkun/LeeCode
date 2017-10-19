#include "iostream"
using namespace std;
#include <vector>
#include <map>

struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head)
{
	map<RandomListNode*,RandomListNode*> NodeMap;
	RandomListNode *pCur=head;

	while (pCur!=NULL)
	{
		if (NodeMap.find(pCur)==NodeMap.end())
		{
			RandomListNode *pNew=new RandomListNode(pCur->label);
			NodeMap[pCur]=pNew;
		}

		RandomListNode *pNext=pCur->next;
		RandomListNode *pRandom=pCur->random;
		
		if (pNext!=NULL && NodeMap.find(pNext)==NodeMap.end())
		{
			RandomListNode *pNewNext=new RandomListNode(pNext->label);
			NodeMap[pCur]->next=pNewNext;
			NodeMap[pNext]=pNewNext;
			pCur=pNext;//¸üÐÂpCur
		}
		else if (pNext==NULL)
			NodeMap[pCur]->next=NULL;
		else
		{
			NodeMap[pCur]->next=NodeMap[pNext];
		}

		if (pRandom!=NULL && NodeMap.find(pRandom)==NodeMap.end())
		{
			RandomListNode *pNewRandom=new RandomListNode(pRandom->label);
			NodeMap[pCur]->random=pNewRandom;
			NodeMap[pRandom]=pNewRandom;
		}
		else if (pRandom==NULL)
			NodeMap[pCur]->random=NULL;
		else
			NodeMap[pCur]->random=NodeMap[pRandom];
	}
	return NodeMap[head];
}

int main()
{
	return 0;
}