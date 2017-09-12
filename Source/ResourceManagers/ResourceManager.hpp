#ifndef RESOURCEMANAGER_HPP_INCLUDED
#define RESOURCEMANAGER_HPP_INCLUDED

#include <unordered_map>

template<typename Resource>
class ResourceManager {
    private:
        const std::string m_folder;
        const std::string m_extention;

        std::unordered_map<std::string, Resource> m_resources;

    private:
        std::string getRelativePath(const std::string& name) {
            return m_folder + name + m_extention;
        }

    public:
        ResourceManager(const std::string& folderPath, const std::string& extention)
        :   m_folder    ("Resources/" + folderPath + "/")
        ,   m_extention ("." + extention)
        { }

        Resource& get(const std::string& name) {
            return m_resources.at(name);
        }

        void addResource(const std::string& name) {
            Resource res;

            res.loadFromFile(getRelativePath(name));
            m_resources.insert(std::make_pair(name, res));
        }
};

#endif // RESOURCEMANAGER_HPP_INCLUDED
