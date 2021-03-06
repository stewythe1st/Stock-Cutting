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
*	Types, etc
**********************************************************/
enum {
	FITNESS_LENGTH,
	FITNESS_WIDTH,
	FITNESS_EDGES,
	PENALTY_WEIGHT,
	CROSSOVER_POINTS,
	MUTATION_RATE
};

enum {
	HIGHEST,
	LOWEST
};


/**********************************************************
*	Pool Class
**********************************************************/
class pool {

private:
	std::vector<state*> m_states;
	std::vector<float>	m_fpProbability;
	int					m_lastBestFitness;
	float				m_lastAvgFitness;
	int					m_lastTopDominated;
	int					m_numGensUnchanged;
	int					m_paretoMin;

	// Private Functions
	int kTournament(int k, bool type, bool replacement);

public:

	// Constructors, Destructors, Etc.
	pool() {};
	~pool() { destroy(); };
	void destroy();

	// Member Functions
	void create(int size, state* initial);
	void randomizeAll(config* cfg);
	void setFpProbability();
	void calcPareto();
	void comparePareto(std::vector<state*>& bestPareto);
	state* chooseParentFP();
	state* chooseParentKTourn(int k);
	state* chooseParentRandom();
	void reduceByTruncation(size_t size);
	void reduceByKTourn(size_t size, int k);	
	void reduceByFP(size_t size);
	void reduceByRandom(size_t size);
	bool termTestAvgFitness(int targetGensUnchanged, float unchangedVariance);
	bool termTestBestFitness(int targetGensUnchanged);
	bool termTestTopDominated(int targetGensUnchanged);
	void empty();

	// Accessors, Mutators
	inline void add(state* x) { m_states.push_back(x); };
	inline state* get(size_t i) const { return m_states[i]; };
	inline int getSize() const { return m_states.size(); };
	inline std::vector<state*> getStates() const { return m_states; };
	state* getBest(int parameter, int highest);
	float getAverage(int parameter);

};


#endif
