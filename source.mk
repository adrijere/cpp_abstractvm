C_SRC 	+=		class/Core.cpp \
				class/Hatchery.cpp \
				class/Error.cpp \
				class/Parsing.cpp

SRC		+=		source/main.cpp \
				$(C_SRC)

T_SRC 	+=		test/UnitTests.cpp \
				test/Core.test.cpp \
				test/Hatchery.test.cpp \
				test/Operand.test.cpp \
				test/Parsing.test.cpp \
				$(C_SRC)
