#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt//ostr.h"

namespace Abtk {

	class ABSTRAK_API Log
	{

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;


	};

};

// Core log macros
#define ABTK_CORE_TRACE(...)       ::Abtk::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ABTK_CORE_INFO(...)        ::Abtk::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ABTK_CORE_WARN(...)        ::Abtk::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ABTK_CORE_ERROR(...)       ::Abtk::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ABTK_CORE_FATAL(...)       ::Abtk::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define ABTK_CLIENT_TRACE(...)     ::Abtk::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ABTK_CLIENT_INFO(...)      ::Abtk::Log::GetClientLogger()->info(__VA_ARGS__)
#define ABTK_CLIENT_WARN(...)      ::Abtk::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ABTK_CLIENT_ERROR(...)     ::Abtk::Log::GetClientLogger()->error(__VA_ARGS__)
#define ABTK_CLIENT_FATAL(...)     ::Abtk::Log::GetClientLogger()->critical(__VA_ARGS__)
