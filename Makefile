##
## EPITECH PROJECT, 2022
## CPP_rtype_2019
## File description:
## Created by tomcousin,
##

RM				=	rm -rf

LOG				=	KO

ifeq			($(LOG), KO)
RM_OUTPUT		=	&> /dev/null
endif

CLIENT_NAME		=	r-type_client

SERVER_NAME		=	r-type_server

TESTS_NAME		=	unit_tests

BUILD_FOLDER	=	build/

TESTS_FOLDER	=	tests/

DOC_FOLDER		=	doc/

BIN_FOLDER		=	$(addprefix $(BUILD_FOLDER), bin/)

all:			$(CLIENT_NAME) $(SERVER_NAME)

tests_run:		$(TESTS_NAME)

$(CLIENT_NAME):	conan cmake
				@echo Make $(CLIENT_NAME)
				@make -C $(BUILD_FOLDER) $(CLIENT_NAME) $(RM_OUTPUT)
				@ln -s $(addprefix $(BIN_FOLDER), $(CLIENT_NAME)) .

$(SERVER_NAME):	conan cmake
				@echo Make $(SERVER_NAME)
				@make -C $(BUILD_FOLDER) $(SERVER_NAME) $(RM_OUTPUT)
				@ln -s $(addprefix $(BIN_FOLDER), $(SERVER_NAME)) .

$(TESTS_NAME):	conan cmake
				@echo Make $(TESTS_NAME)
				@make -C $(BUILD_FOLDER) $(TESTS_NAME) $(RM_OUTPUT)
				@ln -s $(addprefix $(BIN_FOLDER), $(TESTS_NAME)) .
				./$(TESTS_NAME)

conan:
				@mkdir -p $(BUILD_FOLDER)
				@echo "Start Conan Install"
				@conan install . -if $(BUILD_FOLDER) --build=missing $(RM_OUTPUT)

cmake:
				@mkdir -p $(BUILD_FOLDER)
				@echo "Start Cmake"
				@cmake -B $(BUILD_FOLDER) -G "Unix Makefiles" . $(RM_OUTPUT)
				@cmake -B $(BUILD_FOLDER) -build $(BUILD_FOLDER) $(RM_OUTPUT)

doc:
				@echo "Create Documentation"
				@doxygen doc/configuration $(RM_OUTPUT)
clean:
				@echo Remove $(BUILD_FOLDER) folder
				@$(RM) $(BUILD_FOLDER)

fclean:	clean
				@echo Remove $(CLIENT_NAME), $(SERVER_NAME), $(TESTS_NAME) and $(addprefix $(DOC_FOLDER), html)
				@$(RM) $(addprefix $(DOC_FOLDER), html)
				@$(RM) $(CLIENT_NAME)
				@$(RM) $(SERVER_NAME)
				@$(RM) $(TESTS_NAME)

re:				fclean all

.PHONY:			$(CLIENT_NAME) $(SERVER_NAME) $(TESTS_NAME)) doc conan cmake clean fclean all re
