#include "Abstrak.h"

class Sandbox : public Abtk::App 
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Abtk::App* Abtk::CreateApp()
{
	return new Sandbox();
};

