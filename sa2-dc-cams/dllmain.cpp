#include "pch.h"

#define DLLEXPORT __declspec(dllexport)
std::string modpath;

/**
 * Enums storing Copies of the game.
 * 
 * To be referenced used the config.
 */
enum class CamDataVersion
{
	Final			= 0, // 2001 Jun 23
	TheTrial		= 1, // 2000 Nov 15
	Preview			= 2, // 2001 Mar 18
	TrialVersion	= 3, // 2001 May 03
	Debug			= 4, // 2001 May 07
	Review			= 5, // 2001 May 21
	Battle			= 6, // Disabled / No Replacement
};
#define GetVersion(i) static_cast<CamDataVersion>(i)

std::unordered_map<std::string, CamDataVersion> stage = {
	{ "stg03", CamDataVersion::Final },
	{ "stg04", CamDataVersion::Final },
	{ "stg05", CamDataVersion::Final },
	{ "stg06", CamDataVersion::Final },
	{ "stg07", CamDataVersion::Final },
	{ "stg08", CamDataVersion::Final },
	{ "stg09", CamDataVersion::Final },
	{ "stg10", CamDataVersion::Final },
	{ "stg11", CamDataVersion::Final },
	{ "stg12", CamDataVersion::Final },
	{ "stg13", CamDataVersion::Final },
	{ "stg14", CamDataVersion::Final },
	{ "stg15", CamDataVersion::Final },
	{ "stg16", CamDataVersion::Final },
	{ "stg17", CamDataVersion::Final },
	{ "stg18", CamDataVersion::Final },
	{ "stg19", CamDataVersion::Final },
	{ "stg21", CamDataVersion::Final },
	{ "stg22", CamDataVersion::Final },
	{ "stg23", CamDataVersion::Final },
	{ "stg24", CamDataVersion::Final },
	{ "stg25", CamDataVersion::Final },
	{ "stg26", CamDataVersion::Final },
	{ "stg27", CamDataVersion::Final },
	{ "stg28", CamDataVersion::Final },
	{ "stg30", CamDataVersion::Final },
	{ "stg31", CamDataVersion::Final },
	{ "stg32", CamDataVersion::Final },
	{ "stg33", CamDataVersion::Final },
	{ "stg34", CamDataVersion::Final },
	{ "stg35", CamDataVersion::Final },
	{ "stg36", CamDataVersion::Final },
	{ "stg37", CamDataVersion::Final },
	{ "stg38", CamDataVersion::Final },
	{ "stg39", CamDataVersion::Final },
	{ "stg40", CamDataVersion::Final },
	{ "stg41", CamDataVersion::Final },
	{ "stg43", CamDataVersion::Final },
	{ "stg44", CamDataVersion::Final },
	{ "stg45", CamDataVersion::Final },
	{ "stg63", CamDataVersion::Final },
	{ "stg65", CamDataVersion::Final },
};

void ProcessConfig(std::shared_ptr<IniFile> config)
{
	for (auto const& info : stage)
	{
		stage[info.first] = GetVersion(config->getInt("Levels", info.first, 0));
	}
}

void ReplacePaths(const HelperFunctions& helpers)
{
	for (auto const& info : stage)
	{
		if (info.second != CamDataVersion::Battle)
		{
			std::string dstpath = "resource\\gd_PC\\";
			std::string file = info.first + "cam.prs";
			std::string srcpath = dstpath + file;
			switch (info.second)
			{
			case CamDataVersion::Final:
			default:
				dstpath += "Final\\";
				break;
			case CamDataVersion::TheTrial:
				dstpath += "TheTrial\\";
				break;
			case CamDataVersion::Preview:
				dstpath += "Preview\\";
				break;
			case CamDataVersion::TrialVersion:
				dstpath += "TrialVersion\\";
				break;
			case CamDataVersion::Debug:
				dstpath += "Debug\\";
				break;
			case CamDataVersion::Review:
				dstpath += "Review\\";
				break;
			}
			dstpath += file;
			std::string print = ("Replacing " + file + " with " + dstpath);
			PrintDebug(print.c_str());
			helpers.ReplaceFile(srcpath.c_str(), dstpath.c_str());
		}
	}
}

extern "C"
{
	DLLEXPORT void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		modpath = path;
		std::shared_ptr<IniFile> config = std::make_shared<IniFile>((std::string(path) + "\\config.ini"));
		ProcessConfig(config);

		ReplacePaths(helperFunctions);
	}

	DLLEXPORT ModInfo SA2ModInfo = { ModLoaderVer };
}