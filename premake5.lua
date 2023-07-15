workspace "Abstrak"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Abstrak"
	location "Abstrak"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ABK_PLATFORM_WINDOWS",
			"ABK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ABTK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ABTK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ABTK_DIST"
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
		"Abstrak/vendor/spdlog/include",
		"Abstrak/src"
	}

	links
	{
		"Abstrak"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ABK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ABTK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ABTK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ABTK_DIST"
		optimize "On"