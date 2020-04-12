#ifndef _CAEDATASTREAM_H_
#define _CAEDATASTREAM_H_

#include <ObjIdl.h>

#include "SADefaultAllocator.hpp"

class CAEDataStream: public IStream, public SADefaultAllocator
{
public:
    // 0x4dc620
    CAEDataStream(int trackID, char *filename, DWORD startPosition, DWORD length, int encrypted);
    // 0x4dc490
    ~CAEDataStream();

	// 0x4dc410
	HRESULT __stdcall QueryInterface(REFIID riid, void** objout) override;
	// 0x4dc460
	ULONG __stdcall AddRef() override;
	// 0x4dc5b0
	ULONG __stdcall Release() override;
	// 0x4dc320
	HRESULT __stdcall Read(void* dest, ULONG size, ULONG* readed) override;
	// 0x4dc4d0
	HRESULT __stdcall Write(const void* src, ULONG size, ULONG* written) override;
	// 0x4dc340
    HRESULT __stdcall Seek(LARGE_INTEGER offset, DWORD whence, ULARGE_INTEGER *newOffset) override;
    // 0x4dc4e0
    HRESULT __stdcall SetSize(ULARGE_INTEGER newsize) override;
    // 0x4dc4f0
    HRESULT __stdcall CopyTo(IStream *target, ULARGE_INTEGER size, ULARGE_INTEGER *readed, ULARGE_INTEGER *written) override;
    // 0x4dc500
    HRESULT __stdcall Commit(DWORD flags) override;
    // 0x4dc510
    HRESULT __stdcall Revert() override;
    // 0x4dc520
    HRESULT __stdcall LockRegion(ULARGE_INTEGER offset, ULARGE_INTEGER size, DWORD type) override;
    // 0x4dc530
    HRESULT __stdcall UnlockRegion(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType) override;
    // 0x4dc3a0
    HRESULT __stdcall Stat(STATSTG *statout, DWORD flags) override;
    // 0x4dc540
    HRESULT __stdcall Clone(IStream **target) override;

	// 0x4dc1c0
	int FillBuffer(void* dest, ULONG size);
    // 0x4dc230
    LONG GetCurrentPosition();
    // 0x4dc2b0
    bool Initialise();

    // Ensure all types are in this exact order!
public:
    HANDLE fileHandle;
    char *filename;
    bool isOpen;
    LONG currentPosition;
    LONG startPosition;
    DWORD length;
    DWORD trackID;
    bool isEncrypted;
    LONG refCount;
};

#endif
