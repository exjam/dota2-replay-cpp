@echo off

REM Read proto file list
call set root_dir="%cd%"
call set proto_dir=src\dota\proto
call set file=%%proto_dir%%\list.txt
call set file_list=
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
   call echo - %%proto_dir%%\%%file%%.proto
   call powershell -Command "(New-Object Net.WebClient).DownloadFile('https://raw.githubusercontent.com/SteamRE/SteamKit/master/Resources/Protobufs/dota/%%file%%.proto', '%%proto_dir%%\%%file%%.proto')"
)

REM Copy protobuf descriptor
if not exist %%proto_dir%%\google call mkdir %%proto_dir%%\google
if not exist %%proto_dir%%\google\protobuf call mkdir %%proto_dir%%\google\protobuf
call copy /y lib\protobuf\src\google\protobuf\descriptor.proto %%proto_dir%%\google\protobuf

REM Execute protobuf compiler
call cd %%proto_dir%%
call qbs run -p protoc -f %%root_dir%% -d %%root_dir%%\build --install-root %%root_dir%%/build -- --cpp_out=. %%file_list%%
call cd %%root_dir%%
