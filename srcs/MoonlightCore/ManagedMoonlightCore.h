#pragma once
#include "Network.h"
#include "Character.h"

namespace MoonlightCore
{
	public delegate bool NetworkCallback(System::String^ packet);

	public ref class ManagedMoonlightCore 
	{
	private:
		MoonlightCore::Network* _network;
		MoonlightCore::Character* _character;
	public:
		ManagedMoonlightCore();
		void SendPacket(System::String^ packet);
		void ReceivePacket(System::String^ packet);
		void Walk(short x, short y);
		void SetRecvCallback(NetworkCallback^ callback);
		void SetSendCallback(NetworkCallback^ callback);

		static const char* StringToCharArray(System::String^ string)
		{
			const char* str = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(string)).ToPointer();
			return str;
		}
	};
}

