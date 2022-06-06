@ECHO ON

DEL ..\include\*.pb.*

protoc --cpp_out=..\include clientpacket.proto
protoc --cpp_out=..\include serverpacket.proto

PAUSE
