#ifdef _WIN32
#include "aqvm/base/file/windows/file.h"

#include <io.h>
#include <stdio.h>
#include <Windows.h>

#include "aqvm/base/file/file.h"

HANDLE AqvmBaseFileWindows_ConvertFileToHandle(struct AqvmBaseFile_File* file) {
  HANDLE handle = (HANDLE)_get_osfhandle(_fileno(file->file));
  if (handle == INVALID_HANDLE_VALUE) {
    // TODO
  }
  return handle;
}
#endif