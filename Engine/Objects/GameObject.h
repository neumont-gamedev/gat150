#pragma once
#include "ObjectFactory.h"
#include "Math/Transform.h"
#include "Engine.h"

namespace nc
{
	class Component;

	class GameObject : public Object
	{
	public:
		virtual void Create(void* data = nullptr) override;
		virtual void Destroy() override;

		void Read(const rapidjson::Value& value) override;
		void ReadComponents(const rapidjson::Value& value);

		void Update() override;
		void Draw();

		template<typename T>
		T* GetComponent();

		void AddComponent(Component* component);
		void RemoveComponent(Component* component);
		void RemoveAllComponents();

		OBJECT_FACTORY_REGISTER_DECLARATION(GameObject)

	public:
		std::string m_name;
		Transform m_transform;
		Engine* m_engine;
		std::string m_name;

	protected:
		std::vector<Component*> m_components;
	};

	template<typename T>
	T* GameObject::GetComponent()
	{
		T* result{ nullptr };

		for (auto component : m_components)
		{
			result = dynamic_cast<T*>(component);
			if (result) break;
		}

		return result;
	}
}
