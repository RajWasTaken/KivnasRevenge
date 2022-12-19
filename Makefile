# Last updated: 2022-09-11 Nicole Wilson <n.wilson@uleth.ca>
# The targets in this file are used in .gitlab-ci.yml and 
# the files created are found in the .gitignore
# Changing any names below can change the target names which 
# will require that you update .gitlab_ci.yml and .gitignore
PROJECT = project
GTEST = test_${PROJECT}


# Compilation command and flags
CXX=g++
CXXVERSION= -std=c++11
CXXFLAGS= ${CXXVERSION} -g -fprofile-arcs -ftest-coverage
LINKFLAGS= -lgtest

# Directories
SRC_DIR = src
PROJECT_SRC_DIR = src/project
GTEST_DIR = test
SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

# Tool variables
GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage

STATIC_ANALYSIS = cppcheck

# The variable STYLE_CHECK is dependant on whether make is called from Ubuntu,
# the lab machines and office machines (this includes student0, student1,
# student2, and faculty0), or from gitlab which uses Centos.
# OS is a variable set and exported when .bashrc is run (found in etc/bashrc}
ifeq (${OS},ubuntu)
	STYLE_CHECK = cpplint
else
	STYLE_CHECK = cpplint.py
endif

DOXY_DIR = docs/code

# Default goal, used by Atom for local compilation
.DEFAULT_GOAL := compileProject

# default rule for compiling .cc to .o
%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

# clean up all files that should NOT be submitted
.PHONY: clean
clean:
	rm -rf *~ ${SRC}/*.o ${GTEST_DIR}/output/*.dat \
	*.gcov *.gcda *.gcno \
	${PROJECT} ${COVERAGE_RESULTS} \
	${GTEST} ${MEMCHECK_RESULTS} ${COVERAGE_DIR}  \
	${PROJECT}.exe ${GTEST}.exe

# compilation using the files in include, src, and test, but not src/project
${GTEST}: ${GTEST_DIR} ${SRC_DIR}
	${CXX} ${CXXFLAGS} -o ./${GTEST} ${INCLUDE} \
	${GTEST_DIR}/*.cpp ${SRC_DIR}/*.cpp ${LINKFLAGS}

# compilation using the files in include, src, and src/project, but not test
compileProject: ${SRC_DIR} ${PROJECT_SRC_DIR}
	${CXX} ${CXXVERSION} -o ${PROJECT} ${INCLUDE} \
	${SRC_DIR}/*.cpp ${PROJECT_SRC_DIR}/*.cpp

# To perform all tests
all: ${GTEST} memcheck coverage docs static style

memcheck: ${GTEST}
	valgrind --tool=memcheck --leak-check=yes --error-exitcode=1 ./${GTEST}

coverage: ${GTEST}
	./${GTEST}
	# Determine code coverage
	${LCOV} --capture --gcov-tool ${GCOV} --directory . --output-file ${COVERAGE_RESULTS} --rc lcov_branch_coverage=1
	# Only show code coverage for the source code files (not library files)
	${LCOV} --extract ${COVERAGE_RESULTS} */*/${SRC_DIR}/* -o ${COVERAGE_RESULTS}
	#Generate the HTML reports
	genhtml ${COVERAGE_RESULTS} --output-directory ${COVERAGE_DIR}
	#Remove all of the generated files from gcov
	rm -f *.gcda *.gcno

static: ${SRC_DIR} ${GTEST_DIR}
	${STATIC_ANALYSIS} --verbose --enable=all ${SRC_DIR} ${GTEST_DIR} ${SRC_INCLUDE} --suppress=missingInclude --error-exitcode=1

style: ${SRC_DIR} ${GTEST_DIR} ${SRC_INCLUDE} ${PROJECT_SRC_DIR}
	${STYLE_CHECK} ${SRC_DIR}/* ${GTEST_DIR}/* ${SRC_INCLUDE}/* ${PROJECT_SRC_DIR}/*

.PHONY: docs
docs: ${SRC_INCLUDE}
	doxygen ${DOXY_DIR}/doxyfile
