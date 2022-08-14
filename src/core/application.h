#pragma once
#include "core.h"

namespace Nata 
{
	class NATA_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual int Run();
	};
}