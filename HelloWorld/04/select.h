#pragma once
#include "../baseCls.h"

namespace totcp{

	typedef int T;
	class select : public baseCls{

	public:
		select();
		virtual ~select();
		void sort( T *t,int n);
		void showMain();
	};

}