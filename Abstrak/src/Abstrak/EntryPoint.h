#pragma once

#ifdef  ABK_PLATFORM_WINDOWS

extern Abtk::App* Abtk::CreateApp();

int main(int argc, char** argv)
{
	auto app = Abtk::CreateApp();
	app->Run();
	delete app;
}

#endif //  HZ_PLATFORM_WINDOWS
