/******************************************************************************
 * class filegenerate - module to genearete a new file using a scanner class  *
 *                      as the input file. AN outptter is used to output the  *
 *                      new file.                                             *
 *                                                                            *
 *****************************************************************************/
#ifndef D_FILEGENERATE_H
#define D_FILEGENERATE_H

#include "../Common/constants.h"
#include <string>

class filegenerate
{
public:
    filegenerate(const std::string &create_filename);
    virtual ~filegenerate();
    //filegenerate(const filegenerate& value);              //  Use automatically generated copy constructor
    //filegenerate operator = (const filegenerate& value);  //  Use automatically generated assignment operator

    void write_text(const char* text);
    std::string create_filename;       // the file to create

private:
    int file_output;                   // file output descriptor
    char buffer[BUFFER_SIZE];          // buffer here to add output
    size_t write_size_buffer;          // size write for buffer
};

#endif /* D_FILEGENERATE_H */
