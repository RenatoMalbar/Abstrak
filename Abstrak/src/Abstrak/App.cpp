#include "App.h"

#include "Abstrak/Events/AppEvent.h"
#include "Abstrak/Log.h"

namespace Abtk {

	App::App()
	{
	}

	App::~App()
	{
	}

	void App::Run() {

		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			ABTK_CLIENT_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			ABTK_CLIENT_TRACE(e);
		}

		while (true);
	}

}