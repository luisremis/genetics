CMAKE_MINIMUM_REQUIRED (VERSION 2.8)
PROJECT (Robot)

SET (CMAKE_BUILD_TYPE Release)

SET (CMAKE_VERBOSE_MAKEFILE ON)

INCLUDE_DIRECTORIES( ../../Framework/Framework/ .)

LINK_DIRECTORIES( ../../Framework/Framework/build)

SET (SRC 	main.cpp
			ArbolRobot.cpp
			CttesRobot.cpp
			EvalRobot.cpp
			FactoryRobot.cpp
			GArbolRobot.cpp
			GirarDer.cpp
			GirarIzq.cpp
			IndRobot.cpp
			Mapa.cpp
			Mover.cpp
			ObstaculoAdelante.cpp
			PastoAdelante.cpp
			Robot.cpp
			Serie.cpp )

SET (CMAKE_CXX_FLAGS "-fmessage-length=0")

SET (EXECUTABLE_OUTPUT_PATH ./build)

ADD_EXECUTABLE (Robot ${SRC})

TARGET_LINK_LIBRARIES (Robot GeneticFramework)

INSTALL (FILES build/Robot DESTINATION build/)

SET (VERSION 1.0.0)
