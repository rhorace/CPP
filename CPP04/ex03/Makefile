# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/25 11:41:48 by rhorace           #+#    #+#              #
#    Updated: 2026/06/25 11:41:51 by rhorace          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                    CONFIG                                    #
# **************************************************************************** #

NAME		= Interface

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

INCLUDES	= -Iincludes

SRC_DIR		= sources

SRCS		=	$(SRC_DIR)/main.cpp \
				$(SRC_DIR)/AMateria.cpp \
				$(SRC_DIR)/Character.cpp \
				$(SRC_DIR)/Cure.cpp \
				$(SRC_DIR)/Ice.cpp \
				$(SRC_DIR)/ICharacter.cpp \
				$(SRC_DIR)/IMateriaSource.cpp \
				$(SRC_DIR)/MateriaSource.cpp

OBJS		= $(SRCS:.cpp=.o)

# **************************************************************************** #
#                                     RULES                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
