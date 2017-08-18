using namespace System::Collections;
using namespace System;

//# define  SCNCNT 38
public ref class scene 
	{
		public:
		System::String^ text;
		String^ music;
		array<int>^ keys;
		String^ keys_name;
		public:
		scene (System::String^ t,	String^ m, array<int>^ k, String^ n)
		{
			text=t;
			music=m;
			keys=k;
			keys_name=n;
		}
	};