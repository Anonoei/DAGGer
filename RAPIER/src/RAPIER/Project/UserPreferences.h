#pragma once

#include "RAPIER/Core/Log.h"
#include "RAPIER/Project/Project.h"

#include <map>

namespace RAPIER
{
	struct RecentProject
	{
		std::string Name;
		std::string FilePath;
		time_t LastOpened;
	};

	struct UserPreferences : public RefCounted
	{
		bool ShowWelcomeScreen = true;
		std::string StartupProject;
		std::map<time_t, RecentProject, std::greater<time_t>> RecentProjects;

		//	Not serialized
		std::string FilePath;
	};

	class UserPreferencesSerializer
	{
	public:
		UserPreferencesSerializer(const Ref<UserPreferences>& preferences);
		~UserPreferencesSerializer();

		void Serialize(const std::filesystem::path& filepath);
		void Deserialize(const std::filesystem::path& filepath);
	private:
		Ref<UserPreferences> m_Preferences;
	};

}	//	END namespace RAPIER
