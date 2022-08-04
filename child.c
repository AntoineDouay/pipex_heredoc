/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:06:22 by adouay            #+#    #+#             */
/*   Updated: 2022/08/04 15:37:42 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_dup(int in, int out)
{
	dup2(in, 0);
	dup2(out, 1);
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while(i < pipex->pipe_nbr * 2)
	{
		close (pipex->pipe[i]);
		i++;
	}
}

char	*get_cmd_path(t_pipex *pipex)
{
	char	*tmp;
	char	*cmd;
	int	i;

	i = 0;
	if(access(pipex->cmd_options[0], F_OK | R_OK) == 0)
		return (pipex->cmd_options[0]);
	while (pipex->paths[i] != 0)
	{
		tmp = ft_strjoin(pipex->paths[i], "/");
		cmd = ft_strjoin(tmp, pipex->cmd_options[0]);
		free(tmp);
		if(access(cmd, F_OK | R_OK) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	cmd = NULL;
	return (cmd);
}

void	create_child(t_pipex *pipex, char **envp)
{
	pipex->pid = fork();
	if (pipex->pid == 0)
	{
		if(pipex->cmds_pos == 0)
			make_dup(pipex->infile_fd, pipex->pipe[1]);
		else if(pipex->cmds_pos == pipex->commands_nbr - 1)
			make_dup(pipex->pipe[pipex->cmds_pos * 2 - 2], pipex->outfile_fd);
		else
			make_dup(pipex->pipe[pipex->cmds_pos * 2 - 2], pipex->pipe[pipex->cmds_pos * 2 + 1]);
		close_pipes(pipex);
		pipex->cmd_options = ft_split(pipex->cmds[pipex->cmds_pos], ' ');
		pipex->cmd_path = get_cmd_path(pipex);
		if (pipex->cmd_path == NULL)
		{
			free (pipex->pipe);
			free (pipex->cmds);
			free_double_array(pipex->paths);
			free_double_array(pipex->cmd_options);
			exit(0);// ERROR
		}
		execve(pipex->cmd_path, pipex->cmd_options, envp);		
	}
}