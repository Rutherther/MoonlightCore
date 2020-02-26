#pragma once
#include "../MoonlightCore/Network.h"

namespace MoonlightCore
{
	namespace Managed
	{
		public ref class ManagedMoonlight 
		{
		private:
			MoonlightCore::Network* _network;
		public:
			ManagedMoonlight();
			void SendPacket(System::String^ packet);
			void ReceivePacket(System::String^ packet);
			void Walk(short x, short y);

			static const char* StringToCharArray(System::String^ string)
			{
				const char* str = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(string)).ToPointer();
				return str;
			}
		};
	}
}

