#pragma once


class ServiceLocator
{
private:
	ServiceLocator();

	~ServiceLocator();

	void CreateServices();

	void ClearAllServices();

public:
	static ServiceLocator* GetInstance();

	void Initialize();

	void Update();

	void Render();

};
