/**
 * Copyright (c) 2020 Miku AuahDark
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef _CAESTREAMINGDECODER_H_
#define _CAESTREAMINGDECODER_H_

#include "SADefaultAllocator.hpp"
#include "CAEDataStream.hpp"

class CAEStreamingDecoder: public SADefaultAllocator
{
public:
	// 0x4f2810
	CAEStreamingDecoder(CAEDataStream *dataStream);
	// 0x4f2860
	void operator delete(void* mem);

	virtual bool Initialise() = 0;
	virtual unsigned long FillBuffer(void *dest, size_t size) = 0;
	virtual long GetStreamLengthMs() = 0;
	virtual long GetStreamPlayTimeMs() = 0;
	virtual void SetCursor(unsigned long pos) = 0;
	virtual int GetSampleRate() = 0;
	// 0x4f2830
	virtual ~CAEStreamingDecoder();
	virtual int GetStreamID() = 0;

public:
	CAEDataStream *dataStream;
};

#endif
