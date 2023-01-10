#pragma once
#include <ctime>
#include "SharedEnv.h"

class MAPFPlanner
{
public:

  SharedEnvironment* env;

	//MAPFPlanner(SharedEnvironment* env): env(env){};
  MAPFPlanner(){env = new SharedEnvironment();};
	~MAPFPlanner();


  void initialize(int preprocess_time_limit);

  // return next states for all agents
  std::vector<State> plan(int time_limit);

  std::list<pair<int,int>>single_agent_plan(int start,int start_direct, int end);

  int getManhattanDistance(int loc1, int loc2);
  std::list<pair<int,int>> getNeighbors(int location, int direction);

};