/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaunola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:34:11 by amaunola          #+#    #+#             */
/*   Updated: 2023/07/16 18:44:28 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

# define HUNDRED 100
# define THOUSAND 1000
# define MILLION 1000000
# define BILLION 1000000000

typedef struct s_rule {
	unsigned int	key;
	char			*word;
}	t_rule;

void			ft_putstr(char *str);
void			ft_convert_to_text(int number, char *dictionary);
unsigned int	ft_atoi(char *str);
int				validate_input(char *str);
char			*ft_putnbr(t_rule *numberPairs, unsigned int nb,
					int flag, char *str);
t_rule			*parse_dictionary(char *buffer, int line_count, int i, int j);
char			*ft_strcat(char *dest, char *src);
int				get_index(t_rule *numberPairs, unsigned int number);
void			ft_str_create(t_rule *numberPairs,
					unsigned int counter, char *str);
void			ft_place(t_rule *numberPairs, int flag,
					unsigned int check, char *str);
char			*copy_word(char *mod_buffer, t_rule *rule_array, int j);
t_rule			*handle_malloc_rule_array(int line_count);
int				make_keys(char *buffer, t_rule *rule_array, int i, int j);

#endif
