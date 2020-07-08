/*
**  filegenerate.cpp
**
**  class definitions for a textual content lexical analyzer
**
**  filegenerate - new constructor to prepare the i/o system called file to read
** ~filegenerate - destructor to release filename
**  advance - used a unbuffered I/O to buffer the input into the filegenerate
*/

#include "filegenerate.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifdef _WINDOWS
#include <windows.h>
#include <share.h>
#include <fcntl.h>
//#include <sys.h>
#include <io.h>
#include <stdio.h>
//#include <io.h>
#else /* _WINDOWS */
#include <unistd.h>
#endif /* _WINDOWS */

#include <cctype>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <string>

filegenerate::filegenerate(const std::string &arg_create_filename):
    create_filename(arg_create_filename), file_output(0), write_size_buffer(0)
{
    std::cout << "CREATE filename " << create_filename << '\n';
	char errbuffer[30];
    write_size_buffer = 0;                   // set 0 written text to output file
    memset(buffer, '\0', BUFFER_SIZE);       // set buffer empty to strcat
	auto err_file_output = _sopen_s(&file_output, arg_create_filename.c_str(), _O_CREAT | _O_TRUNC | _O_WRONLY, _SH_DENYNO, _S_IREAD | _S_IWRITE);
    if (err_file_output > 0) {
		strerror_s(errbuffer, err_file_output);
        throw std::runtime_error(errbuffer);
    }
}

filegenerate::~filegenerate()
{
    // Write the buffer lastly to output file
    if (file_output >= 0) {
        _write(file_output, buffer, (unsigned int) write_size_buffer);
        _close(file_output);
    }
}

/*---------------------------------------------------------------------------*
**  "generate" reads the scanner input and writes into file_output
**
*/
void filegenerate::write_text(const char *text)
{
    size_t size, written, total_size;        // size characters of text
    size = strlen(text);
	total_size = size;
	written = 0;
    if (file_output >= 0) {
		while (size > 0) {

			if ((size + write_size_buffer) >= BUFFER_SIZE) {

				// Fill the buffer to max size and then write to system
				memcpy(buffer + write_size_buffer, text + written, BUFFER_SIZE - write_size_buffer); 
				//Write the full buffer to file
				_write(file_output, buffer, (unsigned int)BUFFER_SIZE);

				// Reset buffer
				write_size_buffer = 0;
				size -= (BUFFER_SIZE - write_size_buffer);
				written = total_size - size;
			}
			else {
				// size of text is not enough to write, fill the buffer till next time
				memcpy(buffer + write_size_buffer, text + written, size);
				write_size_buffer = size;
				size = 0;
			}
		}
    }

}

