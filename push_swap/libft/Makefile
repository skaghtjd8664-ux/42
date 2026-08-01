# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dosong <dosong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/05 15:20:51 by dosong            #+#    #+#              #
#    Updated: 2026/07/20 14:32:15 by dosong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 1. 프로그램 이름 설정
NAME = libft.a

# 2. 컴파일러 및 옵션
CC = cc
CFLAGS = -Wall -Wextra -Werror

# 3. 소스 파일 목록 (본인이 만든 파일들을 모두 적으세요)
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
       ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
       ft_strnstr.c ft_atoi.c ft_atol.c ft_calloc.c ft_strdup.c \
       ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	   ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c \
	   ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	   ft_lstmap.c
	   


# 4. 오브젝트 파일 (.c를 .o로 변환한 목록)
OBJS = $(SRCS:.c=.o)

# 5. 아카이브 명령 (라이브러리 제작 도구)
AR = ar
ARFLAGS = rcs

# 6. 기본 규칙 (make 실행 시 처음 수행)
all: $(NAME)

# 7. 라이브러리 파일 생성 규칙
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# 8. .c 파일을 .o 파일로 만드는 규칙
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 9. 명령어 모음 (Phony Targets)
clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

# 10. 파일 이름과 타겟 이름이 겹치는 것 방지
.PHONY: all clean fclean re
