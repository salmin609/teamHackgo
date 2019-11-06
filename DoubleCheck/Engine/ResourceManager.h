#pragma once


template<typename Derived, typename  T>
class ResourceManager
{
public:
	ResourceManager(const std::string& l_pathFile)
	{
		LoadPaths(l_pathFile);
	}

	virtual ~ResourceManager() { PurgeResources(); }

private:
	std::unordered_map < std::string,
		std::pair<T*, unsigned int>> m_resources;
	std::unorderd_map<stdd
};