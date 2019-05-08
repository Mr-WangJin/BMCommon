#pragma once

namespace BMCOMMON
{
	class Int64Processor : public GSPQueryIDValueImpl
	{
	public:
		~Int64Processor();

	private:
		Int64Processor();

	public:
		static Int64Processor *instance();

		void queryIDValue(GSPRecord & record, GVariant & idValue);

		void excute(GSPModel model);

	private:
		void setQueryIDValueFunc(GSPModel model);
	};
}

