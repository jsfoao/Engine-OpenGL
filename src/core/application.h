#pragma once
#include "core.h"

namespace Nata 
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual int Run();
	};
}