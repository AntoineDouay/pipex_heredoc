/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:34:30 by adouay            #+#    #+#             */
/*   Updated: 2022/06/30 17:16:12 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

#include "libft/libft.h"
#include "get_next_line_bonus.h"
#include <unistd.h>
#include <sys/wait.h>

#include <stdio.h>

typedef struct s_pipex{
	int		pid;
	int		cmds_pos;
	int		here_doc;

	int		infile_fd;
	int		outfile_fd;

	int		commands_nbr;
	int		pipe_nbr;

	int		*pipe;
	char	**cmds;

	char	**cmd_options;
	char	*cmd_path;

	char 	*path_line;
	char	**paths;
}	t_pipex;

void	create_child(t_pipex *pipex, char **envp);
void	close_pipes(t_pipex *pipex);
void	free_double_array(char **tab);
void    here_doc(t_pipex *pipex,char **av);

#endif
