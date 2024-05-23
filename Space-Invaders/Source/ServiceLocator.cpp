#include "../Header/ServiceLocator.h"


ServiceLocator::ServiceLocator()
{
	//constructor
}


ServiceLocator::~ServiceLocator()
{
	//Destructor
}

void ServiceLocator::CreateServices()
{
	//Create instances of all services
}

void ServiceLocator::ClearAllServices()
{
	//Deletes and deallocates memory for all services.
}



ServiceLocator* ServiceLocator::GetInstance()
{
	// Provides a method to access the unique ServiceLocator instance (object).
	// This could be like a singleton object in C#
	return nullptr;
}

void ServiceLocator::Initialize()
{
	//	Initializes the ServiceLocator.
}

void ServiceLocator::Update()
{
	//Update the service locator
}

void ServiceLocator::Render()
{
	//	Renders using the services.
}


