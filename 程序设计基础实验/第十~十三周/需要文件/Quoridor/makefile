Quoridor : QuoridorUI QuoridorClient

QuoridorUI : obj/QuoridorUIMain.o obj/Replayer.o obj/LogLoader.o obj/ConsoleView.o obj/QuoridorUtils.o
	g++ -std=c++11 -o bin/QuoridorUI obj/QuoridorUIMain.o obj/Replayer.o obj/LogLoader.o obj/ConsoleView.o obj/QuoridorUtils.o -static
# linux add -lpthread to the end -static-libgcc -static-libstdc++ 

QuoridorClient : obj/ClientMain.o obj/Configuration.o obj/BaselinePlayer.o obj/NetworkClient.o obj/QuoridorUtils.o
	g++ -std=c++11 -o bin/QuoridorClient obj/ClientMain.o obj/Configuration.o obj/BaselinePlayer.o obj/NetworkClient.o obj/QuoridorUtils.o -lWs2_32 -lrpcrt4 -static
# linux add -lpthread to the end and del -lWs2_32 -static-libgcc -static-libstdc++

obj/QuoridorUIMain.o : QuoridorUI/QuoridorUI.cpp
	g++ -O3 -std=c++11 -o obj/QuoridorUIMain.o -c QuoridorUI/QuoridorUI.cpp
obj/Replayer.o : QuoridorUI/Replayer.cpp QuoridorUI/Replayer.h
	g++ -O3 -std=c++11 -o obj/Replayer.o -c QuoridorUI/Replayer.cpp
obj/LogLoader.o : QuoridorUI/LogLoader.cpp QuoridorUI/LogLoader.h
	g++ -O3 -std=c++11 -o obj/LogLoader.o -c QuoridorUI/LogLoader.cpp
obj/ConsoleView.o : QuoridorUI/ConsoleView.cpp QuoridorUI/ConsoleView.h
	g++ -O3 -std=c++11 -o obj/ConsoleView.o -c QuoridorUI/ConsoleView.cpp
obj/ClientMain.o : QuoridorClient/Client.cpp
	g++ -O3 -std=c++11 -I QuoridorClient/ -o obj/ClientMain.o -c QuoridorClient/Client.cpp
obj/Configuration.o : QuoridorClient/Configuration.cpp QuoridorClient/Configuration.h 
	g++ -O3 -std=c++11 -I QuoridorClient/ -o obj/Configuration.o -c QuoridorClient/Configuration.cpp
obj/BaselinePlayer.o : QuoridorClient/BaselinePlayer.cpp QuoridorClient/BaselinePlayer.h 
	g++ -O3 -std=c++11 -o obj/BaselinePlayer.o -c QuoridorClient/BaselinePlayer.cpp
obj/NetworkClient.o : QuoridorClient/NetworkClient.cpp QuoridorClient/NetworkClient.h 
	g++ -O3 -std=c++11 -I QuoridorClient/ -o obj/NetworkClient.o -c QuoridorClient/NetworkClient.cpp
obj/QuoridorUtils.o : QuoridorUtils/QuoridorUtils.cpp QuoridorUtils/QuoridorUtils.h 
	g++ -O3 -std=c++11 -o obj/QuoridorUtils.o -c QuoridorUtils/QuoridorUtils.cpp
.PHONY : clean
clean :
# -rm bin/QuoridorUI bin/QuoridorClient obj/QuoridorUIMain.o obj/Replayer.o obj/LogLoader.o obj/ConsoleView.o obj/ClientMain.o obj/Configuration.o obj/MyPlayer.o obj/NetworkClient.o