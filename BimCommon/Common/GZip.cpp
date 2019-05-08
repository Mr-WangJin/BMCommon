#include "stdafx.h"
#include "GZip.h"
#include "zlib/zlib.h"

using namespace BMCOMMON;

int GZip::httpgzUncompress(Byte *zdata, uLong nzdata, Byte *data, uLong *ndata)
{
	int err = 0;
	z_stream d_stream = { 0 }; /* decompression stream */
	static char dummy_head[2] =
	{
		0x8 + 0x7 * 0x10,
		(((0x8 + 0x7 * 0x10) * 0x100 + 30) / 31 * 31) & 0xFF,
	};
	d_stream.zalloc = (alloc_func)0;
	d_stream.zfree = (free_func)0;
	d_stream.opaque = (voidpf)0;
	d_stream.next_in = zdata;
	d_stream.avail_in = 0;
	d_stream.next_out = data;
	if (inflateInit2(&d_stream, 47) != Z_OK) return -1;
	while (d_stream.total_out < *ndata && d_stream.total_in < nzdata) {
		d_stream.avail_in = d_stream.avail_out = 1; /* force small buffers */
		if ((err = inflate(&d_stream, Z_NO_FLUSH)) == Z_STREAM_END) break;
		if (err != Z_OK)
		{
			if (err == Z_DATA_ERROR)
			{
				d_stream.next_in = (Bytef*)dummy_head;
				d_stream.avail_in = sizeof(dummy_head);
				if ((err = inflate(&d_stream, Z_NO_FLUSH)) != Z_OK)
				{
					return -1;
				}
			}
			else return -1;
		}
	}
	if (inflateEnd(&d_stream) != Z_OK) return -1;
	*ndata = d_stream.total_out;
	return 0;
}

bool GZip::gzipUncompress(const QByteArray &data, QByteArray &out)
{
	if (data.size() <= 8)
	{
		return false;
	}

	ulong orign_crc = *((ulong*)(data.data() + data.length() - 8));
	ulong len = *((ulong*)(data.data() + data.length() - 4));

	out.resize(len);
	int ret = httpgzUncompress((Bytef *)data.data(), data.length(), (Bytef *)out.data(), &len); //(Bytef *)(data.data()+10), data.length()-10-8);
	if (ret != Z_OK)
	{
		qWarning("gzipUncompress error: %d", ret);
		return false;
	}
	uLong crc = crc32(0L, Z_NULL, 0);
	crc = crc32(crc, (Bytef *)(out.data()), out.length());

	if (crc == orign_crc)
	{
		return true;
	}
	else {
		qWarning("gzipUncompress crc check sum fail");
		out.clear();
		return false;
	}
}

QByteArray GZip::Uncompress(const QByteArray &data)
{
	QByteArray out;
	gzipUncompress(data, out);
	return out;
}

int GZip::httpgzCompress(Bytef *data, uLong ndata, Bytef *zdata, uLong *nzdata)
{
	z_stream c_stream;
	int err = 0;

	if (data && ndata > 0)
	{
		c_stream.zalloc = (alloc_func)0;
		c_stream.zfree = (free_func)0;
		c_stream.opaque = (voidpf)0;
		if (deflateInit2(&c_stream, Z_DEFAULT_COMPRESSION, Z_DEFLATED,
			MAX_WBITS + 16, 8, Z_DEFAULT_STRATEGY) != Z_OK) return -1;
		c_stream.next_in = data;
		c_stream.avail_in = ndata;
		c_stream.next_out = zdata;
		c_stream.avail_out = *nzdata;
		while (c_stream.avail_in != 0 && c_stream.total_out < *nzdata)
		{
			if (deflate(&c_stream, Z_NO_FLUSH) != Z_OK) return -1;
		}
		if (c_stream.avail_in != 0) return c_stream.avail_in;
		for (;;) {
			if ((err = deflate(&c_stream, Z_FINISH)) == Z_STREAM_END) break;
			if (err != Z_OK) return -1;
		}
		if (deflateEnd(&c_stream) != Z_OK) return -1;
		*nzdata = c_stream.total_out;
		return 0;
	}
	return -1;
}

QByteArray GZip::Compress(const QByteArray &in)
{
	QByteArray dest(compressBound(in.size()) + 7, 0);
	uLongf destLen = dest.size();
	int r1 = httpgzCompress((Bytef*)in.data(), in.size(), (Bytef*)dest.data(), &destLen);
	dest.resize(destLen);
	return dest;
}