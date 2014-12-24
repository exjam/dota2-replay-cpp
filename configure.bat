REM Make some empty files to stop QBS crying
mkdir src\proto
copy /y NUL src\proto\ai_activity.pb.cc >NUL
copy /y NUL src\proto\demo.pb.cc >NUL
copy /y NUL src\proto\dota_commonmessages.pb.cc >NUL
copy /y NUL src\proto\dota_modifiers.pb.cc >NUL
copy /y NUL src\proto\dota_usermessages.pb.cc >NUL
copy /y NUL src\proto\netmessages.pb.cc >NUL
copy /y NUL src\proto\network_connection.pb.cc >NUL
copy /y NUL src\proto\networkbasetypes.pb.cc >NUL
copy /y NUL src\proto\usermessages.pb.cc >NUL

REM Download latest dota protobuf message formats
powershell -Command "(New-Object Net.WebClient).DownloadFile('https://raw.githubusercontent.com/SteamRE/SteamKit/master/Resources/Protobufs/dota/ai_activity.proto', 'src\proto\ai_activity.proto')"
powershell -Command "(New-Object Net.WebClient).DownloadFile('https://raw.githubusercontent.com/SteamRE/SteamKit/master/Resources/Protobufs/dota/demo.proto', 'src\proto\demo.proto')"
powershell -Command "(New-Object Net.WebClient).DownloadFile('https://raw.githubusercontent.com/SteamRE/SteamKit/master/Resources/Protobufs/dota/dota_commonmessages.proto', 'src\proto\dota_commonmessages.proto')"
powershell -Command "(New-Object Net.WebClient).DownloadFile('https://raw.githubusercontent.com/SteamRE/SteamKit/master/Resources/Protobufs/dota/dota_modifiers.proto', 'src\proto\dota_modifiers.proto')"
powershell -Command "(New-Object Net.WebClient).DownloadFile('https://raw.githubusercontent.com/SteamRE/SteamKit/master/Resources/Protobufs/dota/dota_usermessages.proto', 'src\proto\dota_usermessages.proto')"
powershell -Command "(New-Object Net.WebClient).DownloadFile('https://raw.githubusercontent.com/SteamRE/SteamKit/master/Resources/Protobufs/dota/netmessages.proto', 'src\proto\netmessages.proto')"
powershell -Command "(New-Object Net.WebClient).DownloadFile('https://raw.githubusercontent.com/SteamRE/SteamKit/master/Resources/Protobufs/dota/networkbasetypes.proto', 'src\proto\networkbasetypes.proto')"
powershell -Command "(New-Object Net.WebClient).DownloadFile('https://raw.githubusercontent.com/SteamRE/SteamKit/master/Resources/Protobufs/dota/usermessages.proto', 'src\proto\usermessages.proto')"
powershell -Command "(New-Object Net.WebClient).DownloadFile('https://raw.githubusercontent.com/SteamRE/SteamKit/master/Resources/Protobufs/dota/network_connection.proto', 'src\proto\network_connection.proto')"

REM Copy protobuf descriptor
mkdir src\proto\google
mkdir src\proto\google\protobuf
copy /y lib\protobuf\src\google\protobuf\descriptor.proto src\proto\google\protobuf

REM Execute protobuf compiler
cd src\proto
qbs run -p protoc -f ../.. -d ../../build --install-root ../../build -- --cpp_out=. ai_activity.proto demo.proto dota_commonmessages.proto dota_modifiers.proto dota_usermessages.proto netmessages.proto network_connection.proto networkbasetypes.proto usermessages.proto
cd ..\..
