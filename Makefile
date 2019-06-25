NAME = abbesbes.filler
GUI_NAME = filler_display


LIBFT_DIR = ./libft/
LIBMLX_DIR = ./minilibx/
LIBFT := $(addprefix $(LIBFT_DIR), libft.a)
LIBMLX := $(addprefix $(LIBMLX_DIR), libmlx.a)
INC_DIR = $(LIBFT_DIR)includes/ ./includes/ $(LIBMLX_DIR)

CC = gcc
CC_FLAGS = -W -Wall -Werror -Wextra
:w
T_BLK = \033[5m
T_NRM = \033[25m
C_GRN = \033[32m
C_YLW = \033[33m
C_BLU = \033[34m
C_LGRN = \033[92m
C_LYLW = \033[93m
C_LBLU = \033[54m
C_LMGN = \033[95m
C_END = \033[0m

FILLER := filler.c fi_io.c fi_game.c fi_map.c fi_solve.c \
    fi_place.c fi_place_dist.c

UTILS := ut_mtx.c ut_zone.c

GUI_FILES := fi_gui.c

SRC_FILES := $(addprefix filler/,  $(FILLER)) \
    $(addprefix utils/,  $(UTILS))

GUI_SRC_FILES := $(addprefix gui/, $(GUI_FILES))

SRC_DIR := ./src/
SRC := $(addprefix $(SRC_DIR), $(SRC_FILES))

GUI_SRC := $(addprefix $(SRC_DIR), $(GUI_SRC_FILES))

NB = $(words $(SRC_FILES))
IND = 0
PER = 0

OBJ := $(SRC:.c=.o)
GUI_OBJ = $(GUI_SRC:.c=.o)

all: $(NAME) $(GUI_NAME)

$(NAME): $(LIBFT)
	@echo "$(C_LYLW)➜ [$(NAME)] Compiling objects ...$(C_END)"
	@make $(OBJ)
	@echo "\033[1A$(T_CLR)$(C_LGRN)➜ [$(NAME)] Objects have been compiled successfully ! $(C_END)"
	@$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT) -ltermcap -o $(NAME)
	@echo "$(C_LGRN)➜ [$(NAME)] The program $(C_LBLU)$(NAME)$(C_LGRN)\
	 has been Compiled Successfully !$(C_END)"

$(GUI_NAME): $(LIBMLX) $(LIBFT)
	@echo "$(C_LYLW)➜ [$(GUI_NAME)] Compiling objects ...$(C_END)"
	@make $(GUI_OBJ)
	@echo "\033[1A$(T_CLR)$(C_LGRN)➜ [$(GUI_NAME)] Objects have been compiled successfully ! $(C_END)"
#@mv $(LIBMLX) .
	@$(CC) -L. -lmlx -framework OpenGL -framework Appkit $(GUI_OBJ) $(LIBMLX) $(LIBFT) $(filter-out ./src/filler/filler.o, $(OBJ)) -o $(GUI_NAME)
	@echo "$(C_LGRN)➜ [$(GUI_NAME)] The program $(C_LBLU)$(GUI_NAME)$(C_LGRN)\
	 has been Compiled Successfully !$(C_END)"

$(OBJ): %.o: %.c  $(LIBFT)
	@$(CC) $(CC_FLAGS) -c $< -o $@ $(addprefix -I , $(INC_DIR))
	@$(eval IND=$(shell echo $$(($(IND) + 1))))
	@$(eval PER=$(shell echo $$((($(IND) * 100) / $(NB)))))
	@printf "$(T_CLR)$(C_LYLW)➜ ➜ progress: %3d %% $(C_END)\n\033[1A$(C_END)" $(PER);

$(GUI_OBJ): %.o: %.c  $(LIBFT) $(LIBMLX)
	@$(CC) $(CC_FLAGS) -c $< -o $@ $(addprefix -I , $(INC_DIR))
	@$(eval IND=$(shell echo $$(($(IND) + 1))))
	@$(eval PER=$(shell echo $$((($(IND) * 100) / $(NB)))))
	@printf "$(T_CLR)$(C_LYLW)➜ ➜ progress: %3d %% $(C_END)\n\033[1A$(C_END)" $(PER);

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "$(C_LYLW)=================================================\
	===================$(C_END)"

$(LIBMLX):
	@make -C $(LIBMLX_DIR)
	@echo "$(C_LYLW)=================================================\
	===================$(C_END)"

clean:
	@rm -f $(OBJ) $(GUI_OBJ)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(LIBMLX_DIR)
	@echo "$(C_LMGN)➜ [$(NAME)] Objects have been cleaned\
	 Successfully !$(C_END)"
	@echo "$(C_LMGN)➜ [$(GUI_NAME)] Objects have been cleaned\
	 Successfully !$(C_END)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(GUI_NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(C_LMGN)➜ [$(NAME)] The Executable has been deleted\
	 Successfully !$(C_END)"
	@echo "$(C_LMGN)➜ [$(GUI_NAME)] The Executable has been deleted\
	 Successfully !$(C_END)"

re: fclean all
	@echo "$(C_LGRN)➜ [$(NAME)] The Program has been re-builded\
	 Successfully !$(C_END)"
	@echo "$(C_LGRN)➜ [$(GUI_NAME)] The Program has been re-builded\
	 Successfully !$(C_END)"

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC) $(INC)
	@norminette -R CheckForbiddenSourceHeader $(GUI_SRC) $(INC)
	@make norm -C $(LIBFT_DIR)

quick: clean
	@rm $(NAME) & make $(NAME)
	@echo "READY !!!"

.PHONY: all, re, clean, fclean, norm
