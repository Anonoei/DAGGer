/////////////////////////////////////////////////////////////////
//	Author: Anonoei (https://github.com/anonoei)
//  License : GPLv3
//  Language: C++
//  This file serves as the entry point for all applications
////////////////////////////
#pragma once
#include "DAGGer/Core/Base.h"
#include "DAGGer/Core/Application.h"

#ifdef Dr_PLATFORM_WINDOWS

extern DAGGer::Application* DAGGer::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	DAGGer::InitalizeCore();

	Dr_PROFILE_BEGIN_SESSION("Startup", "DAGGerProfile-Startup.json");
	auto app = DAGGer::CreateApplication({ argc, argv });
	Dr_PROFILE_END_SESSION();

	Dr_PROFILE_BEGIN_SESSION("Runtime", "DAGGerProfile-Runtime.json");
	app->Run();
	Dr_PROFILE_END_SESSION();

	Dr_PROFILE_BEGIN_SESSION("Shutdown", "DAGGerProfile-Shutdown.json");
	delete app;
	DAGGer::ShutdownCore();
	Dr_PROFILE_END_SESSION();
}

#endif
