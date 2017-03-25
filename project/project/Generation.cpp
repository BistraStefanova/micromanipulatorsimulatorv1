#include "stdafx.h"
#include "Generation.h"


void Generation::GenerateRandom()
{
	for (int i = 0; i < size; i++)
	{
		Creature c;
		c.CreateRandom();
		if (c.nodes.size() == 0)
		{
			i--;
			continue;
		}
		//c.Mutate();
		creatures.push_back(c);
	}
}

void Generation::MeasureFitness()
{
	for (Creature& c : creatures)
	{
		world.AddCreature(c);
	}
	world.StartSimulation();
}

Generation::Generation(int size) : size(size)
{
	
}


Generation::~Generation()
{
}
