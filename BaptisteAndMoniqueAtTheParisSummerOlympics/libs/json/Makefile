##
## EPITECH PROJECT, 2024
## Json
## File description:
## This is the Makefile for the  project
## (more specifically the JSON library)
## It job is to compile, clean and tests the project
##

# All the source files
CXX_SOURCES		= 	src/JsonObject.cpp			\
					src/JsonArray.cpp			\
					src/JsonBoolean.cpp			\
					src/JsonInt.cpp				\
					src/JsonString.cpp			\
					src/JsonFloat.cpp			\

CXX_TESTS		=   tests/json_parser.cpp	\
					tests/json_save.cpp		\

# Compiler and linker settings
NAME 			= 	libjson.so
CXX				= 	g++
CXXFLAGS		= 	-W -Wall -Wextra -std=c++20 -I./include -fPIC
LDFLAGS			= 	-shared
CXX_OBJS		= 	$(CXX_SOURCES:.cpp=.o)
CXX_TESTS_OBJS	= 	$(CXX_TESTS:.cpp=.o)

LOG				=	./build.log

.PHONY: all clean fclean re tests_run clean_test _tests_run

# Colors and formatting
GREEN =		\033[1;32m
YELLOW =	\033[1;33m
RED =		\033[1;31m
BLUE =		\033[1;36m
GOLD =		\033[1;33m
MAGENTA =	\033[1;35m
RESET =		\033[0m

RUNNING = [$(YELLOW)~$(RESET)]
SUCCESS = [$(GREEN)✔$(RESET)]
FAILURE = [$(RED)✘$(RESET)]
SKIPPED = [$(MAGENTA)@$(RESET)]

ifeq ($(ENABLE_COVERAGE), 1)
	CXXFLAGS += --coverage
else
	CXXFLAGS += -O2
endif

all:
# Check if $(NAME) is up to date
	@HAS_NEWER_SOURCE=0; \
	for file in $(CXX_SOURCES); do \
		if [ "$$file" -nt "$(NAME)" ]; then \
			HAS_NEWER_SOURCE=1; \
			break; \
		fi; \
	done; \
	if [ ! -f $(NAME) ] || [ $$HAS_NEWER_SOURCE -eq 1 ]; then \
		make $(NAME) --no-print-directory; \
	else \
		printf "$(SKIPPED)$(MAGENTA)  🚀  \
$(NAME) already up to date$(RESET)\n"; \
	fi

$(NAME):	$(CXX_OBJS)
# Link the object files
		@printf "$(RUNNING) $(BLUE) 🔗   Linking$(RESET)"
		@$(CXX) -o $(NAME) $(CXX_OBJS) $(CXXFLAGS) $(LDFLAGS) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || (printf "\r$(FAILURE)\n" && cat $(LOG) \
		&& exit 1)
# Check if the binary was created
		@if [ -f $(NAME) ]; then \
			printf \
			"$(SUCCESS)$(GREEN)  🎉   $(NAME) built successfully$(RESET)\n";\
		else \
			printf "$(FAILURE)$(RED)  🚨   $(NAME) build failed$(RESET)\n"; \
			cat $(LOG); \
			exit 1; \
		fi

$(CXX_OBJS):	%.o: %.cpp
# Compile the source file
		@printf "$(RUNNING) $(BLUE) 🔨   $$(basename $<)$(RESET)"
		@$(CXX) -o $@ -c $< $(CXXFLAGS) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || (printf "\r$(FAILURE)\n" && cat $(LOG) \
		&& exit 1)

clean:
# Delete all the object files
		@for file in $(CXX_OBJS); do \
			printf "$(RUNNING) $(YELLOW) 🧹️   Deleting $$file$(RESET)"; \
			if [ -f $$file ]; then \
				rm -f $$file >> $(LOG) 2>&1 \
				&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"; \
			else \
				printf "\r$(SKIPPED)\n"; \
			fi; \
		done
# Delete all the tests' object files
		@for file in $(CXX_TESTS_OBJS); do \
			printf "$(RUNNING) $(YELLOW) 🧹️   Deleting $$file$(RESET)"; \
			if [ -f $$file ]; then \
				rm -f $$file >> $(LOG) 2>&1 \
				&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"; \
			else \
				printf "\r$(SKIPPED)\n"; \
			fi; \
		done

fclean: clean clean_test
# Delete the binary
		@printf "$(RUNNING) $(RED) 🗑️    Deleting $(NAME)$(RESET)"
		@if [ -f $(NAME) ]; then \
			rm -f $(NAME) >> $(LOG) 2>&1 \
			&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"; \
		else \
			printf "\r$(SKIPPED)\n"; \
		fi
# Delete the log file
		@printf "$(RUNNING) $(RED) 🗑️    Deleting $(LOG)$(RESET)"
		@rm -f $(LOG) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"

re:			fclean all

$(CXX_TESTS_OBJS):	%.o: %.cpp
		@printf "$(RUNNING) $(BLUE) 🧪   $$(basename $<)$(RESET)"
		@$(CXX) -o $@ -c $< $(CXXFLAGS) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"

tests_run:
	@ENABLE_COVERAGE='1' make _tests_run --no-print-directory

_tests_run: fclean $(CXX_OBJS) $(CXX_TESTS_OBJS)
	@printf "$(RUNNING) $(BLUE) 🔗   Linking for $(shell uname -m)\
 architecture$(RESET)";
	@$(CXX) -o tests.out $(filter-out src/main.o, $(CXX_OBJS)) \
	$(CXX_TESTS_OBJS) $(CXXFLAGS) \
	$(shell [ `uname -m` != "arm64" ]	\
	&& echo "-lcriterion" \
	|| echo "-lcriterion") >> $(LOG) 2>&1 \
	&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n";
	@printf "$(RUNNING)$(MAGENTA)  ⚗️    Running tests$(RESET)" \
	&& ./tests.out --xml=criterion.xml --ignore-warnings >> tests.log 2>&1 \
	&& printf "\r$(SUCCESS)\n" \
	|| (printf "\r$(FAILURE)\n" && cat tests.log && exit 1);
	@cat tests.log;
	@printf "$(RUNNING)$(YELLOW)  📊   Generating coverage$(RESET)" \
	&& gcovr --exclude tests/ >> coverage.log 2>&1 \
	&& printf "\r$(SUCCESS)\n" \
	|| printf "\r$(FAILURE)\n";
	@cat coverage.log;

clean_test:
	@printf "$(RUNNING) $(RED) 🗑️    Deleting tests.out$(RESET)"
	@if [ -f tests.out ]; then \
		rm -f tests.out >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"; \
	else \
		printf "\r$(SKIPPED)\n"; \
	fi
	@printf "$(RUNNING) $(RED) 🗑️    Deleting coverage$(RESET)"
	@if [ -f coverage* ]; then \
		rm -f coverage* >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"; \
	else \
		printf "\r$(SKIPPED)\n"; \
	fi
	@printf "$(RUNNING) $(RED) 🗑️    Deleting *.gcda$(RESET)"
	@if [ -n "$$(find ./ -name "*.gcda")" ]; then \
		find ./ -name "*.gcda" -delete >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"; \
	else \
		printf "\r$(SKIPPED)\n"; \
	fi
	@printf "$(RUNNING) $(RED) 🗑️    Deleting *.gcno$(RESET)"
	@if [ -n "$$(find ./ -name "*.gcno")" ]; then \
		find ./ -name "*.gcno" -delete >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"; \
	else \
		printf "\r$(SKIPPED)\n"; \
	fi
	@printf "$(RUNNING) $(RED) 🗑️    Deleting criterion.xml$(RESET)"
	@if [ -f criterion.xml ]; then \
		rm -f criterion.xml >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"; \
	else \
		printf "\r$(SKIPPED)\n"; \
	fi
	@printf "$(RUNNING) $(RED) 🗑️    Deleting tests.log$(RESET)"
	@if [ -f tests.log ]; then \
		rm -f tests.log >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"; \
	else \
		printf "\r$(SKIPPED)\n"; \
	fi
	@printf "$(RUNNING) $(RED) 🗑️    Deleting coverage.log$(RESET)"
	@if [ -f coverage.log ]; then \
		rm -f coverage.log >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"; \
	else \
		printf "\r$(SKIPPED)\n"; \
	fi
	@printf "$(RUNNING) $(RED) 🗑️    Deleting .cache/$(RESET)"
	@if [ -d .cache/ ]; then \
		rm -rf .cache >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"; \
	else \
		printf "\r$(SKIPPED)\n"; \
	fi
	@printf "$(RUNNING) $(RED) 🗑️    Deleting .local/$(RESET)"
	@if [ -d .local/ ]; then \
		rm -rf .local >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"; \
	else \
		printf "\r$(SKIPPED)\n"; \
	fi
