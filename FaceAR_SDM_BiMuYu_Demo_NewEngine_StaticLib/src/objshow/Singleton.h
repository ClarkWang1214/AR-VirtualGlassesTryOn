#pragma once

namespace tezcat
{
    template<class CLASS>
    class Singleton
    {
    public:
        static CLASS *getInstance()
        {
            return m_Instance;
        }

        static CLASS *init()
        {
            if (m_Instance == nullptr)
            {
                m_Instance = new CLASS();
            }
            return m_Instance;
        }

        static void deleteInstance()
        {
            if (m_Instance != nullptr)
            {
                delete m_Instance;
            }
        }

        Singleton() {}
        virtual ~Singleton() {}

    private:
        Singleton(const Singleton &other) = delete;
        Singleton &operator = (const Singleton &other) = delete;

        static CLASS *m_Instance;
    };

    template<class CLASS> CLASS *Singleton<CLASS>::m_Instance = nullptr;
}
