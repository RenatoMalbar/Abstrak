#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Abtk {

	class ABSTRAK_API App
	{
	public:
		App();
		virtual ~App();

		void Run();
	};

	// To be defined in client
	App* CreateApp();

}