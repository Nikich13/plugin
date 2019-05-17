#ifndef PROTOSHARP_WRITE_FILE_H_
#define PROTOSHARP_WRITE_FILE_H_

#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/printer.h>

namespace protosharp
{

void WriteFile(const google::protobuf::FileDescriptor &protoFile,
               google::protobuf::io::Printer &printer);

}
#endif