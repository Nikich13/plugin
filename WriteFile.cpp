#include "WriteFile.h"

namespace protosharp
{
void WriteFile(const google::protobuf::FileDescriptor &protoFile,
               google::protobuf::io::Printer &printer)
{
    printer.Print("using System;\n");
    printer.Print("using System.Collections.Generic;\n");
    printer.Print("using System.Linq;\n\n");
	
	printer.Print(("namespace " + protoFile.package() + "\n").c_str());
	printer.Print("{\n");
	printer.Indent();
	printer.Print(("class " + protoFile.message_type(0)->name() + "\n").c_str());
	printer.Print("{\n");
	//printer.Print(protoFile.message_type(0)->field(0)->type_name() + protoFile.message_type(0)->field(0)->name());
	printer.Print("}\n");
	printer.Outdent();
	printer.Print("}\n");
}
}
