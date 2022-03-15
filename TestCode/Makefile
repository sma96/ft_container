# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/18 02:34:15 by sehan             #+#    #+#              #
#    Updated: 2022/02/09 17:24:44 by sehan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g3
RM = rm -rf

VECTOR_FILES = print \
			   main \
			   construct \
			   resize \
			   reserve \
			   at \
			   front \
			   back \
			   assign \
			   push_back \
			   pop_back \
			   insert \
			   erase \
			   swap \
			   clear \
			   oper \
			   iterOper \
			   reverseIter

STACK_FILES = main \
			  print \
			  construct \
			  oper

PAIR_FILES = main \
			 print \
			 construct \
			 oper

MAP_FILES = main \
		   print \
		   construct \
		   empty \
		   insert \
		   erase \
		   swap \
		   clear \
		   find \
		   count \
		   bound \
		   equal_range \
		   map_operator \
		   iter_oper

SET_FILES = main \
		   print \
		   construct \
		   empty \
		   insert \
		   erase \
		   swap \
		   clear \
		   find \
		   count \
		   bound \
		   equal_range \
		   set_operator \
		   iter_oper

VECTOR_SRCS_DIR = ./vector/
VECTOR_SRCS = $(addprefix $(VECTOR_SRCS_DIR), $(addsuffix .cpp, $(VECTOR_FILES)))

VECTOR_OBJS_DIR = ./vector/
VECTOR_OBJS = $(addprefix $(VECTOR_OBJS_DIR), $(addsuffix .o, $(VECTOR_FILES)))

STACK_SRCS_DIR = ./stack/
STACK_SRCS = $(addprefix $(STACK_SRCS_DIR), $(addsuffix .cpp, $(STACK_FILES)))

STACK_OBJS_DIR = ./stack/
STACK_OBJS = $(addprefix $(STACK_OBJS_DIR), $(addsuffix .o, $(STACK_FILES)))

PAIR_SRCS_DIR = ./pair/
PAIR_SRCS = $(addprefix $(PAIR_SRCS_DIR), $(addsuffix .cpp, $(PAIR_FILES)))

PAIR_OBJS_DIR = ./pair/
PAIR_OBJS = $(addprefix $(PAIR_OBJS_DIR), $(addsuffix .o, $(PAIR_FILES)))

MAP_SRCS_DIR = ./map/
MAP_SRCS = $(addprefix $(MAP_SRCS_DIR), $(addsuffix .cpp, $(MAP_FILES)))

MAP_OBJS_DIR = ./map/
MAP_OBJS = $(addprefix $(MAP_OBJS_DIR), $(addsuffix .o, $(MAP_FILES)))

SET_SRCS_DIR = ./set/
SET_SRCS = $(addprefix $(SET_SRCS_DIR), $(addsuffix .cpp, $(SET_FILES)))

SET_OBJS_DIR = ./set/
SET_OBJS = $(addprefix $(SET_OBJS_DIR), $(addsuffix .o, $(SET_FILES)))

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): vector stack pair map set

vector: fclean $(VECTOR_OBJS)
	$(CC) $(CFLAGS) $(VECTOR_SRCS) -o $(NAME) && ./test

stack: fclean $(STACK_OBJS)
	$(CC) $(CFLAGS) $(STACK_SRCS) -o $(NAME) && ./test

pair: fclean $(PAIR_OBJS)
	$(CC) $(CFLAGS) $(PAIR_SRCS) -o $(NAME) && ./test

map: fclean $(MAP_OBJS)
	$(CC) $(CFLAGS) $(MAP_SRCS) -o $(NAME) && ./test

set: fclean $(SET_OBJS)
	$(CC) $(CFLAGS) $(SET_SRCS) -o $(NAME) && ./test

clean:
	$(RM) $(VECTOR_OBJS) $(STACK_OBJS) $(PAIR_OBJS) $(MAP_OBJS) $(SET_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME).dSYM

re: clean all

.PHONY: all clean fclean re
