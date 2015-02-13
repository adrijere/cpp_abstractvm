C_SRC 	+=		class/Core.cpp \
				class/Hatchery.cpp \
				class/Error.cpp \
				class/Int8.cpp \
				class/Int16.cpp \
				class/Int32.cpp \
				class/Float.cpp \
				class/Double.cpp

SRC		+=		source/main.cpp \
				$(C_SRC)

T_SRC 	+=		test/Core.test.cpp \
				test/Hatchery.test.cpp \
				test/Int8.test.cpp \
				test/Int16.test.cpp \
				test/Int32.test.cpp \
				test/Float.test.cpp \
				test/Double.test.cpp \
				test/UnitTests.cpp \
				$(C_SRC)