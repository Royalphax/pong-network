@ECHO ON

DEL ..\include\clientpacket.pb.cc
DEL ..\include\clientpacket.pb.h
protoc --cpp_out=..\include clientpacket.proto
CD ..\include
RENAME "clientpacket.pb.cc" "..\include\ClientPacket.cpp"
RENAME "clientpacket.pb.h" "..\include\ClientPacket.h"
CD ..\protobuf

DEL ..\include\serverpacket.pb.cc
DEL ..\include\serverpacket.pb.h
protoc --cpp_out=..\include serverpacket.proto
RENAME "..\include\serverpacket.pb.cc" "..\include\ServerPacket.cpp"
RENAME "..\include\serverpacket.pb.h" "..\include\ServerPacket.h"

PAUSE
