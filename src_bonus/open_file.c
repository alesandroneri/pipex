/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:49:59 by aneri-da          #+#    #+#             */
/*   Updated: 2025/02/04 17:05:34 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int open_fd(char *file, int id_input_output)
{
    int file_permission;

    if (id_input_output == 0)
        file_permission = open(file, O_RDONLY);
    if (id_input_output == 1)
        file_permission = open(file, O_WRONLY, O_CREAT, O_TRUNC, 0777);
    if (id_input_output == -1)
        exit(0);
    return (file_permission);
}