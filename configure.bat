@echo off

REM Read proto file list
set file=src\proto\list.txt
set file_list=
set /A i=0

for /F "usebackq delims=" %%a in ("%file%") do (
  set /A i+=1
  call set file_list=%%file_list%% %%a.proto
  call set proto_files[%%i%%]=%%a
  call set num_proto_files=%%i%%
)

REM Download proto files
call echo Downloading latest dota protobuf files

for /L %%i in (1, 1, %num_proto_files%) do (
  call set file=%%proto_files[%%i]%%
  call echo - src\proto\%%file%%.proto
  call powershell -Command "(New-Object Net.WebClient).DownloadFile('https://raw.githubusercontent.com/SteamRE/SteamKit/master/Resources/Protobufs/dota/%%file%%.proto', 'src\proto\%%file%%.proto')"
  REM Make fake c files so QBS does not complain when building protoc
  call copy /y NUL src\proto\%%file%%.pb.cc >NUL
  call copy /y NUL src\proto\%%file%%.pb.h >NUL
)

REM Copy protobuf descriptor
if not exist src\proto\google call mkdir src\proto\google
if not exist src\proto\google\protobuf call mkdir src\proto\google\protobuf
call copy /y lib\protobuf\src\google\protobuf\descriptor.proto src\proto\google\protobuf

REM Execute protobuf compiler
cd src\proto
call qbs run -p protoc -f ../.. -d ../../build --install-root ../../build -- --cpp_out=. %%file_list%%
cd ..\..
