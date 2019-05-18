#include "WriteFile.h"

namespace protosharp
{

std::string TypeVar(const std::string &type)
{
	if (type == "int32" || type == "sint32" || type == "sfixed32") return "int";
	if (type == "uint32" || type == "fixed32") return "uint";
	if (type == "int64" || type == "sint64" || type == "sfixed64") return "long";
	if (type == "uint64" || type == "fixed64") return "ulong";
	return type;
}

void WriteFile(const google::protobuf::FileDescriptor &protoFile,
               google::protobuf::io::Printer &printer)
{
	printer.Print("using System;\n");
	printer.Print("using System.Collections.Generic;\n");
	printer.Print("using System.Linq;\n\n");
	
	printer.Print(("namespace " + protoFile.package() + "\n{\n").c_str());
	printer.Indent();
	printer.Print(("public class " + protoFile.message_type(0)->name() + "\n{\n").c_str());
	printer.Indent();
	for (int i = 0; i < protoFile.message_type(0)->field_count(); i++)
		printer.Print((TypeVar(protoFile.message_type(0)->field(i)->type_name()) + " " + protoFile.message_type(0)->field(i)->name() + ";\n").c_str());
	printer.Outdent();
	printer.Print("}\n");
	printer.Outdent();
	printer.Print("}");
}
}
