#include "Paths.h"
#include "WriteFile.h"
#include <google/protobuf/compiler/code_generator.h>
#include <google/protobuf/compiler/plugin.h>
#include <google/protobuf/io/zero_copy_stream.h>

namespace protosharp
{

class Generator
    : public google::protobuf::compiler::CodeGenerator
{
public:
    virtual bool Generate(const google::protobuf::FileDescriptor *protoFile,
                          const std::string &parameter,
                          google::protobuf::compiler::GeneratorContext *context,
                          std::string *error) const override
    {
        std::string fileName = ReplaceExt(protoFile->name(),"cs");
        std::unique_ptr<google::protobuf::io::ZeroCopyOutputStream>
            outStream(context->Open(fileName));
        //We will not use variables
        google::protobuf::io::Printer printer(outStream.get(),0x00);
        WriteFile(*protoFile,printer);
        return true;
    }
};
}
using namespace protosharp;

int main(int argc, char* argv[])
{
    Generator generator;
    return google::protobuf::compiler::PluginMain(argc, argv, &generator);
}