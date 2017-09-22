/******************************************************************************
*	pool.h
*
*	Declarations for the pool class for the Stock Cutting Problem.
*
*	Stuart Miller
*	Missouri S&T CS 5401
*	Fall 2017
******************************************************************************/
#ifndef POOL_H
#define POOL_H


/**********************************************************
*	Headers
**********************************************************/
#include "state.h"
#include <vector>


/**********************************************************
*	Compiler Constants
**********************************************************/


/**********************************************************
*	Types, Etc.
**********************************************************/


/**********************************************************
*	Pool Class
**********************************************************/
class pool {

private:
	std::vector<state*> m_states;
	std::vector<float>	m_fpProbability;

	int kTournament(int k, int type);

public:

	// Constructors, Destructors, Etc.
	pool() {};
	~pool() {};

	// Member Functions
	void create(int size, state* initial);
	void randomizeAll();
	void setFpProbability();
	state* chooseParentFP();
	state* chooseParentKTourn(int k);
	void reduceByTruncation(int size);
	void reduceByKTourn(int size, int k);	
	bool termTestNumEvals(int targetEvals);
	bool termTestAvgFitness(int targetGensUnchanged, float unchangedVariance);
	bool termTestBestFitness(int targetGensUnchanged);

	// Accessors, Mutators
	inline void add(state* x) { m_states.push_back(x); };
	inline state* get(size_t i) const { return m_states[i]; };
	inline void empty() { m_states.clear(); };
	inline int getSize() const { return m_states.size(); };
	state* getFittestState();

};


#endif