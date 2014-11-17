CMAKE_MINIMUM_REQUIRED (VERSION 2.8)
PROJECT (Robot)

SET (CMAKE_BUILD_TYPE Release)

SET (CMAKE_VERBOSE_MAKEFILE ON)

INCLUDE_DIRECTORIES( Framework/ include/ .)

LINK_DIRECTORIES( Framework/build)

SET (SRC 	src/main.cpp
			src/ArbolRobot.cpp
			src/CttesRobot.cpp
			src/EvalRobot.cpp
			src/FactoryRobot.cpp
			src/GArbolRobot.cpp
			src/GirarDer.cpp
			src/GirarIzq.cpp
			src/IndRobot.cpp
			src/Mapa.cpp
			src/Mover.cpp
			src/ObstaculoAdelante.cpp
			src/PastoAdelante.cpp
			src/Robot.cpp
			src/Serie.cpp )

SET (CMAKE_CXX_FLAGS "-fmessage-length=0")

SET (EXECUTABLE_OUTPUT_PATH ./build)

ADD_EXECUTABLE (Robot ${SRC})

TARGET_LINK_LIBRARIES (Robot GeneticFramework)

INSTALL (FILES build/Robot DESTINATION build/)

SET (VERSION 1.0.0)
