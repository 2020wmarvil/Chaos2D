workspace "Chaos2D"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%cfg.system}-%{cfg.architecture}"

project "Chaos2D"
	location "Chaos2D"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ch2pch.h"
	pchsource "Chaos2D/src/ch2pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"CH2_PLATFORM_WINDOWS",
			"CH2_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CH2_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CH2_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CH2_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"Chaos2D/vendor/spdlog/include",
		"Chaos2D/src"
	}

	links 
	{
		"Chaos2D"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"CH2_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "CH2_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CH2_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CH2_DIST"
		optimize "On"
