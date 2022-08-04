/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:48:49 by adouay            #+#    #+#             */
/*   Updated: 2022/08/04 15:37:37 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(t_pipex *pipex, char **av)
{
	char	*line;

	line = NULL;
	while (1)
	{
		write (0, "here_doc>", 9);
		line = get_next_line(0);
		if (line == NULL)
			return ; // ERROR
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
			break ;
		write(pipex->pipe[1], &line, ft_strlen(line));
		free (line);
	}
	free (line);
	pipex->infile_fd = pipex->pipe[0];
}