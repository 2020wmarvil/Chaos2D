#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Chaos2D {
	class CHAOS2D_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// core log macros
#define CH2_CORE_TRACE(...)   ::Chaos2D::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CH2_CORE_INFO(...)    ::Chaos2D::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CH2_CORE_WARN(...)    ::Chaos2D::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CH2_CORE_ERROR(...)   ::Chaos2D::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CH2_CORE_FATAL(...)   ::Chaos2D::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// client log macros
#define CH2_TRACE(...)        ::Chaos2D::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CH2_INFO(...)         ::Chaos2D::Log::GetClientLogger()->info(__VA_ARGS__)
#define CH2_WARN(...)         ::Chaos2D::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CH2_ERROR(...)        ::Chaos2D::Log::GetClientLogger()->error(__VA_ARGS__)
#define CH2_FATAL(...)        ::Chaos2D::Log::GetClientLogger()->fatal(__VA_ARGS__)
