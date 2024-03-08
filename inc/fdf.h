/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:16:15 by chuleung          #+#    #+#             */
/*   Updated: 2024/03/08 23:50:56 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
//# include <wait.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>

typedef enum e_mode
{
	READ,
	WRITE,
}	t_mode;

typedef enum e_exit
{
	EXIT,
	NEXIT,
}	t_exit;

typedef enum e_print
{
	PRINT,
	NPRINT,
}	t_print;

typedef struct s_cmds
{
	char	**cmd;
	char	**cmd2;
	char	*cmd_path;
	char	*cmd_path2;
}	t_cmds;

typedef struct s_res
{
	int	chk_space_res;
	int	chk_null_res;
	int	chk_path_res;
}	t_res;

typedef struct s_args
{
	char	*file1;
	char	*file2;
	int		ac;
	char	**av;
	char	**cmd1;
	char	**cmd2;
	char	*cmd_path1;
	char	*cmd_path2;
	char	**envp;
}	t_args;

typedef struct s_pid
{
	pid_t	pid1;
	pid_t	pid2;
}	t_pid;

//main.c
t_args	extract_args(int ac, char **av, char **envp);

//execve.c
void	ft_execve(char *path, char **cmd, char **envp);

//file_mgt.c
void	open_n_dup2_a_file(t_mode mode, char *file);

//input_mgt.c
int		chk_open_in(char *file_name);
int		chk_open_out(char *file_name);
int		chk_path(char *cmd, char *path);
int		chk_null(char *cmd);
int		chk_space(char *cmd);

//chk_cmds.c
void	chk_all_cmds(char **av);

//pipe.c
int		pipe_operate(int *fd, t_args *args);

//utili.c
void	free_whole_array(char **arr);
void	free_all(char **cmd1, char **cmd2, char *cmd_path1, char *cmd_path2);
#endif
