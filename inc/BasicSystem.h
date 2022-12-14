#pragma once
#include "BasicGraph.h"
#include "States.h"
#include "PriorityGraph.h"
#include "WHCAStar.h"
#include "LRAStar.h"


class BasicSystem
{
public:
    // params for MAPF algotithms
	MAPFSolver& solver;
	bool hold_endpoints;
	bool useDummyPaths;
    int time_limit;
    int travel_time_window;
	//string potential_function;
	//double potential_threshold;
	//double suboptimal_bound;
    int screen;
	bool log;
    int num_of_drives;
    int seed;
    int simulation_window;
    int planning_window;
    int simulation_time;

    // params for drive model
    bool consider_rotation;
    int k_robust;

    BasicSystem(const BasicGraph& G, MAPFSolver& solver);
    ~BasicSystem();

	// TODO
    /*bool load_config(std::string fname);
    bool generate_random_MAPF_instance();
    bool run();
	void print_MAPF_instance() const;
	void save_MAPF_instance(std::string fname) const;
	bool read_MAPF_instance(std::string fname);*/

    // I/O
    std::string outfile;
    void save_results();
	double saving_time = 0; // time for saving results to files, in seconds
    int num_of_tasks; // number of finished tasks

	list<int> new_agents; // used for replanning a subgroup of agents

    // used for MAPF instance
    vector<State> starts;
    vector< vector<pair<int, int> > > goal_locations;
	// unordered_set<int> held_endpoints;
    int timestep;

    // record movements of drives
    std::vector<Path> paths;
    std::vector<std::list<std::pair<int, int> > > finished_tasks; // location + finish time

    bool congested() const;
	bool check_collisions(const vector<Path>& input_paths) const;

    // update
    void update_start_locations();
    void update_travel_times(unordered_map<int, double>& travel_times);
    void update_paths(const std::vector<Path*>& MAPF_paths, int max_timestep);
    void update_paths(const std::vector<Path>& MAPF_paths, int max_timestep);
    void update_initial_paths(vector<Path>& initial_paths) const;
    void update_initial_constraints(list< tuple<int, int, int> >& initial_constraints) const;
    
	list<tuple<int, int, int>> move(); // return finished tasks
	void solve();
	void initialize_solvers();
	bool load_records();
	bool load_locations();


protected:
    bool LRA_called = false;

private:
	const BasicGraph& G;
};

