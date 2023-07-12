#pragma once

#ifdef  ABK_PLATFORM_WINDOWS

extern Abtk::App* Abtk::CreateApp();

int main(int argc, char** argv)
{	

	Abtk::Log::Init();
	ABTK_CORE_FATAL("Log Initialized");
	ABTK_CLIENT_TRACE("Log Initialized");

	auto app = Abtk::CreateApp();
	app->Run();
	delete app;
}

#endif //  HZ_PLATFORM_WINDOWS
