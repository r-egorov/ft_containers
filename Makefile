NAME			=	containers

SRCSDIR			=	srcs/
OBJSDIR			=	objs/

CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98

INCLUDES		=	includes/
HEADERS_DIR		=	stack/ utils/ vector/ myclass/ timer/ RBTree/
HEADERS_DIR		:=	$(addprefix $(INCLUDES), $(HEADERS_DIR))
INCLUDES_FLAGS	=	$(addprefix -I, $(HEADERS_DIR))

SRCS			=	main.cpp MyClass.cpp Timer.cpp
OBJS			=	$(patsubst %.cpp,%.o,$(SRCS))

OBJS			:=	$(addprefix $(OBJSDIR), $(OBJS))
SRCS			:=	$(addprefix $(SRCSDIR), $(SRCS))
DEPS			=	$(OBJS:%.o=%.d)

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) -o $(NAME) $? $(INCLUDES_FLAGS)

-include $(DEPS)
$(OBJSDIR)%.o:		$(SRCSDIR)%.cpp Makefile
					@ mkdir -p $(OBJSDIR)
					$(CC) $(CFLAGS) -MMD -c $< -o $@ $(INCLUDES_FLAGS)
info:
					echo $(DEPS)
					echo $(SRCS)
					echo $(OBJS)

clean:
					rm -rf $(OBJSDIR)

fclean:				clean
					rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re test
