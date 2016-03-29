#ifndef MAPSEARCHNODE_H
#define MAPSEARCHNODE_H

#include "stlastar.h"
#include "Board.h"

class MapSearchNode
{
public:
	int x;	 // the (x,y) positions of the node
	int y;

	MapSearchNode() { x = y = 0;}
	MapSearchNode( int px, int py ) { x=px; y=py; }

	float GoalDistanceEstimate( MapSearchNode &nodeGoal );
	bool IsGoal( MapSearchNode &nodeGoal );
	bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
	float GetCost( MapSearchNode &successor );
	bool IsSameState( MapSearchNode &rhs );

	void PrintNodeInfo(Board b);
};
#endif // MAPSEARCHNODE_H
