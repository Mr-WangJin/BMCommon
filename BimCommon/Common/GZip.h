#pragma once
#include "zlib/zconf.h"
#include <QByteArray>

namespace BMCOMMON
{
	class GZip
	{
	public:
		static QByteArray Uncompress(const QByteArray &data);
		static QByteArray Compress(const QByteArray &in);
	private:
		static int httpgzUncompress(Byte *zdata, uLong nzdata, Byte *data, uLong *ndata);
		static bool gzipUncompress(const QByteArray &data, QByteArray &out);
		static int httpgzCompress(Bytef *data, uLong ndata, Bytef *zdata, uLong *nzdata);
	};
}

